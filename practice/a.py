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

        # Chỉ chạy luồng click, đã bỏ luồng strafe

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

        t_cps = random.uniform(21.0, 24.0)

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

        self.root.geometry("260x160")

        self.root.attributes('-topmost', True)

        self.root.attributes('-alpha', 0.85)

        self.root.configure(bg="#111")



        self.lbl_m = tk.Label(root, text="IDLE", font=("Verdana", 18, "bold"), fg="#888", bg="#111")

        self.lbl_m.pack(pady=15)



        self.lbl_c = tk.Label(root, text="0.0 CPS", font=("Verdana", 12), fg="white", bg="#111")

        self.lbl_c.pack(pady=2)



        self.bar = ttk.Progressbar(root, orient="horizontal", length=220, mode="determinate", maximum=30)

        self.bar.pack(pady=15)



        # Cập nhật lại hướng dẫn ở dưới cùng

        self.lbl_i = tk.Label(root, text="[C] PVP | [V] BRIDGE", font=("Verdana", 8), fg="#555", bg="#111")

        self.lbl_i.pack(side="bottom", pady=5)



        self.update()



    def update(self):

        if self.core.mode == "PVP":

            self.lbl_m.config(text="PVP", fg="#FF3333")

        elif self.core.mode == "BRIDGE":

            self.lbl_m.config(text="V", fg="#33FF33")

        else:

            self.lbl_m.config(text="IDLE", fg="#888")



        self.lbl_c.config(text=f"{self.core.cps:.1f} CPS")

        self.bar['value'] = self.core.cps

        self.root.after(50, self.update)



def run_kb(core):

    def on_press(key):

        if hasattr(key, 'char') and key.char:

            c = key.char.lower()

            if c == 'c':

                if core.mode == "PVP":

                    core.mode = None

                else:

                    core.mode = "PVP"

            elif c == 'v':

                if core.mode == "BRIDGE":

                    core.mode = None

                else:

                    core.mode = "BRIDGE"



    def on_release(key):

        pass # Không cần theo dõi phím S, A, D nữa



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