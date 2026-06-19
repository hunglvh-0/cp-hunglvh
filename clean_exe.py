import os
import glob

def clean_exe_files(directory="."):
    print("Đang quét các file .exe...")
    search_pattern = os.path.join(directory, "**", "*.exe")
    exe_files = glob.glob(search_pattern, recursive=True)
    if not exe_files:
        print("Không tìm thấy file .exe nào để xóa.")
        return
    count = 0
    for file_path in exe_files:
        try:
            os.remove(file_path)
            print(f"Đã xóa: {file_path}")
            count += 1
        except Exception as e:
            print(f"Lỗi khi xóa {file_path}: {e}")
    print(f"\nHoàn thành! Đã dọn dẹp {count} file .exe.")

if __name__ == "__main__":
    clean_exe_files()