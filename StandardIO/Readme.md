# Logger Module in C

## 1. 📌 Mô tả dự án

Dự án này hiện thực một **module ghi log chuyên nghiệp trong ngôn ngữ C**, có khả năng:
- Ghi log ra **nhiều đầu ra**: console (stdout, stderr) và file văn bản.
- **Lọc log theo mức độ nghiêm trọng** (log level) dựa trên chuẩn `syslog`.
- **Tự động thêm metadata** như timestamp, tên file nguồn và số dòng.
- **Sử dụng macro tiện lợi** để ghi log không cần chỉ định `__FILE__`, `__LINE__`.

> Mục tiêu chính: Giúp người dùng dễ dàng tích hợp hệ thống logging có cấu hình linh hoạt, rõ ràng, dễ mở rộng cho bất kỳ dự án C nào.

---

## 2. 📁 Cấu trúc source code

logger_project/
├── include/ # Header files
│ └── logger.h
├── src/ # Source code
│ └── logger.c
├── test/ # Test or example usage
│ └── main.c
├── output/ # File log output (tùy chọn)
│ └── log.txt
├── build/ # (Tùy chọn) file binary sau khi build
│ └── logger_exec
└── Makefile # Biên dịch toàn bộ dự án

---

## 3. 🧩 Các thành phần chính

### 🔹 Enum `logLevel`
```c
typedef enum {
    logEmergency, logAlert, logCritical, logError,
    logWarning, logNotice, logInfo, logDebug
} logLevel;
→ Đại diện cho các mức độ log theo chuẩn syslog.

🔹 Hàm API chính
API	Mô tả
loggerInit(level, filePath)	Khởi tạo logger với mức lọc và file ghi log
loggerLog(level, file, line, format, ...)	Ghi log với thông tin chi tiết
loggerClose()	Đóng file log nếu có
loggerSetLevel(level)	Thay đổi mức lọc log tại runtime
logMessage(level, format, ...)	Macro tiện lợi, tự động chèn __FILE__, __LINE__

🔹 Biến nội bộ (module scope)
static FILE *logFile;
static logLevel currentLevel;
→ Quản lý trạng thái của logger (mức lọc, file log đang mở).

---

## 4. ⚙️ Build & Run
🛠 Build bằng Makefile

make

▶️ Run chương trình
./logger.exe

---

## 5. 🔁 Flow chart

                ┌────────────┐
                │ logMessage │ ←─────────────── Gọi từ main.c
                └─────┬──────┘
                      │
                      ▼
              ┌───────────────┐
              │ loggerLog()   │
              └────┬──────────┘
                   │
        ┌──────────┼────────────┐
        ▼                         ▼
 [1] Kiểm tra level       [2] Format thời gian
        │                         │
        ▼                         ▼
 [3] Gộp log hoàn chỉnh    [4] Xác định stream (stderr/stdout)
        │                         │
        └──────────────┬──────────┘
                       ▼
               [5] In ra console
               [6] In ra file (nếu có)
6. ✅ Kiểm thử
📄 main.c
Đóng vai trò là chương trình kiểm thử, kiểm tra các mức log và thay đổi cấu hình thời gian chạy.

Kết quả mong đợi:
Log được ghi đúng thứ tự ra console và file.

Các mức log thấp hơn mức lọc sẽ không xuất hiện.

Format chuẩn:

[2025-07-07 09:00:00] [ERROR] [main.c:25] - Failed to open file.