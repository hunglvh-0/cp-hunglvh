import os
import time
import subprocess
from datetime import datetime

REPO_PATH = "."
COMMIT_MSG = "Auto sync CP code"
SYNC_INTERVAL = 300

C_GREEN = '\033[92m'
C_BLUE = '\033[94m'
C_MAGENTA = '\033[95m'
C_YELLOW = '\033[93m'
C_RESET = '\033[0m'
C_BOLD = '\033[1m'

def auto_commit():
    os.chdir(REPO_PATH)
    status = subprocess.run(["git", "status", "--porcelain"], capture_output=True, text=True)
    current_time = datetime.now().strftime("%H:%M:%S")

    if status.stdout.strip():
        changed_files = []
        for line in status.stdout.strip().split('\n'):
            if line:
                file_name = line.strip().split(maxsplit=1)[1].replace('"', '')
                changed_files.append(file_name)

        print(f"\n{C_YELLOW}{C_BOLD}[{current_time}] 🚀 Đang push...{C_RESET}")
        subprocess.run(["git", "add", "."], stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
        subprocess.run(["git", "commit", "-m", COMMIT_MSG], stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
        subprocess.run(["git", "push"], stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)

        print(f"{C_GREEN}{C_BOLD}[{current_time}] ✅ Đã xong:{C_RESET}")

        for file in changed_files:
            print(f" {C_GREEN}■{C_RESET} [{current_time}] {C_BOLD}{file}{C_RESET}")
        print()
    else:
        print(f"\r{C_BLUE}👀 Đang soi...{C_RESET} ", end="", flush=True)

if __name__ == "__main__":
    os.system('cls' if os.name == 'nt' else 'clear')
    print(f"{C_MAGENTA}{C_BOLD}")
    print("╔═════════════════════════════════════════════╗")
    print("║          hunglvh'S CP AUTO-SYNC             ║")
    print("╚═════════════════════════════════════════════╝")
    print(f"{C_RESET}")
    print(f"{C_BLUE}Thư mục: {C_BOLD}{os.path.abspath(REPO_PATH)}{C_RESET}")
    print(f"{C_BLUE}Chu kỳ: {C_BOLD}{SYNC_INTERVAL}s{C_RESET}\n")

    while True:
        auto_commit()
        time.sleep(SYNC_INTERVAL)