import pyautogui
import time
import random

def main():
    print("Chương trình auto OwO bắt đầu sau 5 giây. Vui lòng click vào Discord...")
    time.sleep(5)

    try:
        print("\n--- BẮT ĐẦU PHANG 100 VÒNG ---")
        for i in range(1, 101): # Chạy đúng 100 lần
            print(f"Đang thực hiện vòng {i}/100...")

            # 1. Gõ "oh"
            pyautogui.write("oh")
            pyautogui.press("enter")

            # 2. Chờ ngẫu nhiên từ 1 đến 3 giây
            delay_oh_ob = random.uniform(1.0, 3.0)
            time.sleep(delay_oh_ob)

            # 3. Gõ "ob"
            pyautogui.write("ob")
            pyautogui.press("enter")

            # 4. Chờ hồi chiêu cho vòng lặp tiếp theo (Bắt buộc để không bị bot bơ)
            # Lệnh OwO có cooldown 15s, nên ta chờ khoảng 16.5 - 20 giây cho an toàn
            delay_next_round = random.uniform(16.5, 20.0)
            print(f"  -> Xong vòng {i}. Đợi {delay_next_round:.1f}s để qua vòng tiếp theo...\n")
            time.sleep(delay_next_round)

        print("ĐÃ HOÀN THÀNH 100 VÒNG! Nghỉ ngơi thôi.")

    except KeyboardInterrupt:
        print("\nĐã dừng auto thủ công bằng Ctrl+C.")

if __name__ == "__main__":
    main()