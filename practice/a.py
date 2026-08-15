import time
import random
import threading
import tkinter as tk
from tkinter import ttk
from pynput.mouse import Button, Controller as MouseController
from pynput.keyboard import Listener

class Core:
    def __init__(self):
        self.mode = None
        self.running = True
        self.mouse = MouseController()
        self.cps = 0.0

    def start(self):
        t1 = threading.Thread(target=self.run_click)
        t1.daemon = True
        t1.start()

    def run_click(self):
        while self.running:
            if self.mode == "PVP":
                self.pvp_click()
            elif self.mode == "BRIDGE":
                self.bridge_click()
            else:
                self.cps = 0.0
                time.sleep(0.01)

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
        t_cps = random.uniform(16.0, 20.0)
        self.cps = t_cps
        delay = 1.0 / t_cps
        hold = random.uniform(0.005, 0.008)
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
        self.root.attributes('-topmost', True)
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

        self.lbl_i = tk.Label(root, text="[C] PVP  |  [V] BRIDGE", font=("Segoe UI", 9, "bold"), fg="#585b70", bg=self.bg_color)
        self.lbl_i.pack(side="bottom", pady=10)

        self.update()

    def update(self):
        if self.core.mode == "PVP":
            self.lbl_m.config(text="PVP", fg="#f38ba8")
            self.bar.configure(style="PVP.TProgressbar")
        elif self.core.mode == "BRIDGE":
            self.lbl_m.config(text="BRIDGE", fg="#a6e3a1")
            self.bar.configure(style="BRIDGE.TProgressbar")
        else:
            self.lbl_m.config(text="IDLE", fg="#6c7086")
            self.bar.configure(style="TProgressbar")

        self.lbl_c.config(text=f"{self.core.cps:.1f} CPS")
        self.bar['value'] = self.core.cps
        self.root.after(50, self.update)

def run_kb(core):
    def on_press(key):
        if hasattr(key, 'char') and key.char:
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