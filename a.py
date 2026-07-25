import os

def clean_copy_files(directory):
    count = 0
    # Duyệt qua toàn bộ thư mục và các thư mục con
    for root, _, files in os.walk(directory):
        for file in files:
            # Tìm những file có chữ " - Copy" trong tên
            if " - Copy" in file:
                file_path = os.path.join(root, file)
                try:
                    os.remove(file_path)
                    print(f"🗑️ Đã xóa: {file_path}")
                    count += 1
                except Exception as e:
                    print(f"❌ Lỗi khi xóa {file_path}: {e}")

    print(f"\n✅ Hoàn tất! Đã dọn dẹp sạch sẽ {count} file rác.")

# Dấu "." đại diện cho thư mục hiện tại (nơi bạn đặt file python này)
if __name__ == "__main__":
    clean_copy_files(".")