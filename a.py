import time
import random
import threading
import tkinter as tk
from tkinter import ttk
from pynput.mouse import Button, Controller as MouseController
from pynput.keyboard import Listener, Controller as KeyboardController, Key

class Core:
    def __init__(self):
        self.mode = None
        self.running = True
        self.mouse = MouseController()
        self.keyboard = KeyboardController()
        self.cps = 0.0

    def start(self):
        t1 = threading.Thread(target=self.run_click)
        t1.daemon = True
        t1.start()

    def is_caps_lock_on(self):
        # Kiểm tra trạng thái đèn Caps Lock trên hệ thống
        try:
            # Trên pynput, cách kiểm tra trực tiếp trạng thái Caps Lock phụ thuộc vào hệ điều hành,
            # tuy nhiên ta có thể dùng state kiểm tra hoặc thông qua một cờ theo dõi từ bàn phím.
            # Dưới đây dùng cờ theo dõi trực tiếp từ sự kiện Listener bên dưới để đảm bảo độ chính xác tuyệt đối.
            return getattr(self, '_caps_lock_active', False)
        except:
            return False

    def run_click(self):
        while self.running:
            # Nếu Caps Lock tắt, tự động đưa về IDLE
            if not self.is_caps_lock_on():
                self.mode = None

            if self.mode == "PVP":
                self.pvp_click()
            elif self.mode == "BRIDGE":
                self.bridge_click()
            else:
                self.cps = 0.0
                time.sleep(0.05)

    def pvp_click(self):
        t_cps = random.uniform(13.0, 18.0)
        self.cps = t_cps
        delay = 1.0 / t_cps
        hold = random.uniform(0.01, 0.015)
        rel = delay - hold
        if rel < 0: rel = 0.001
        self.mouse.press(Button.left)
        time.sleep(hold)
        self.mouse.release(Button.left)
        time.sleep(rel)

    def bridge_click(self):
        t_cps = random.uniform(15.0, 25.0)
        self.cps = t_cps
        delay = 1.0 / t_cps
        hold = random.uniform(0.003, 0.007)
        rel = delay - hold
        if rel < 0: rel = 0.001

        self.mouse.press(Button.right)
        time.sleep(hold)
        self.mouse.release(Button.right)
        time.sleep(rel)

class UI:
    def __init__(self, root, core):
        self.root = root
        self.core = core
        self.root.title("Real Feel Client")
        self.root.geometry("280x190")

        # ĐÃ BỎ: self.root.attributes('-topmost', True) để không ghim lên màn hình nữa
        self.root.attributes('-alpha', 0.95)

        self.bg_color = "#1e1e2e"
        self.root.configure(bg=self.bg_color)

        self.style = ttk.Style()
        self.style.theme_use('clam')

        self.style.configure("TProgressbar",
                             thickness=12,
                             background="#89b4fa",
                             troughcolor="#313244",
                             bordercolor=self.bg_color,
                             lightcolor="#89b4fa",
                             darkcolor="#89b4fa")

        self.style.configure("PVP.TProgressbar", background="#f38ba8", lightcolor="#f38ba8", darkcolor="#f38ba8")
        self.style.configure("BRIDGE.TProgressbar", background="#a6e3a1", lightcolor="#a6e3a1", darkcolor="#a6e3a1")

        self.lbl_title = tk.Label(root, text="R E A L   F E E L", font=("Segoe UI", 9, "bold"), fg="#a6adc8", bg=self.bg_color)
        self.lbl_title.pack(pady=(12, 0))

        self.lbl_m = tk.Label(root, text="IDLE", font=("Segoe UI", 24, "bold"), fg="#6c7086", bg=self.bg_color)
        self.lbl_m.pack(pady=(2, 2))

        self.lbl_c = tk.Label(root, text="0.0 CPS", font=("Segoe UI", 13, "bold"), fg="#cdd6f4", bg=self.bg_color)
        self.lbl_c.pack(pady=2)

        self.bar = ttk.Progressbar(root, orient="horizontal", length=230, mode="determinate", maximum=25, style="TProgressbar")
        self.bar.pack(pady=(10, 10))

        self.lbl_i = tk.Label(root, text="[Caps] Bật | [C] PVP | [V] GODBRIDGE", font=("Segoe UI", 8, "bold"), fg="#585b70", bg=self.bg_color)
        self.lbl_i.pack(side="bottom", pady=10)

        self.update()

    def update(self):
        # Kiểm tra nếu Caps Lock tắt thì hiển thị IDLE
        if not self.core.is_caps_lock_on():
            self.lbl_m.config(text="IDLE", fg="#6c7086")
            self.bar.configure(style="TProgressbar")
        else:
            if self.core.mode == "PVP":
                self.lbl_m.config(text="PVP", fg="#f38ba8")
                self.bar.configure(style="PVP.TProgressbar")
            elif self.core.mode == "BRIDGE":
                self.lbl_m.config(text="GODBRIDGE", fg="#a6e3a1")
                self.bar.configure(style="BRIDGE.TProgressbar")
            else:
                self.lbl_m.config(text="READY", fg="#f9e2af")
                self.bar.configure(style="TProgressbar")

        self.lbl_c.config(text=f"{self.core.cps:.1f} CPS")
        self.bar['value'] = self.core.cps
        self.root.after(50, self.update)

def run_kb(core):
    core._caps_lock_active = False

    def on_press(key):
        if key == Key.caps_lock:
            core._caps_lock_active = not core._caps_lock_active
            if not core._caps_lock_active:
                core.mode = None # Tắt chế độ ngay khi tắt Caps Lock

        # Chỉ nhận phím C và V khi Caps Lock đang bật
        elif core._caps_lock_active and hasattr(key, 'char') and key.char:
            c = key.char.lower()
            if c == 'c':
                core.mode = None if core.mode == "PVP" else "PVP"
            elif c == 'v':
                core.mode = None if core.mode == "BRIDGE" else "BRIDGE"

    def on_release(key):
        pass

    with Listener(on_press=on_press, on_release=on_release) as l:
        l.join()

if __name__ == "__main__":
    core = Core()
    core.start()

    t = threading.Thread(target=run_kb, args=(core,), daemon=True)
    t.start()

    root = tk.Tk()
    app = UI(root, core)
    root.mainloop()

    core.running = False