#  CAR DASHBOARD

## Giới thiệu
Car Dashboard là hệ thống mô phỏng điều khiển xe ô tô tập trung vào quản lý vận tốcm chế độ lái, giám sát tiêu hao năng lượng và đảm bảo an toàn.
## Mục tiêu
1. Hiển thị thông số vận hành: tốc độ, mức pin, điều hòa.
2. Quản lý chế độ lái SPORT - ECO
3. TÍnh toán tiêu hao năng lượng: tính toán dự đoán tiêu hao dựa trên vận tốc, điều hòa, mức gió
4. Đảm bảo an toàn: quản lý yếu tố an toàn, như ngăn việc đạp ga và phanh cùng lúc.

## Kỹ thuật sử dụng
- Design Patterns : dùng mẫu Singleton, Observer
- Multithreading : Các thead riêng biệt xử lý dự liệu từ file CSV và từ user
- Mutex: Đảm bảo dữ liệu không xung đột
## Cấu trúc thư mục
Car_Dashboard_Project
Car_Dashboard_Project/
```
├── App/ # Application layer
│ ├── Inc/ # Header files (interfaces)
│ │ ├── DashboardController.hpp
│ │ ├── DisplayManager.hpp
│ │ ├── SpeedCalculator.hpp
│ │ ├── BatteryManager.hpp
│ │ ├── DriveModeManager.hpp
│ │ └── SafetyManager.hpp
│ │
│ └── Src/ # Source files (implementations)
│   ├── Main.cpp
│   ├── DashboardController.cpp
│   ├── DisplayManager.cpp
│   ├── SpeedCalculator.cpp
│   ├── BatteryManager.cpp
│   ├── DriveModeManager.cpp
│   └── SafetyManager.cpp
│
├── bin/ # Compiled binaries / executables
│
├── Data/ # Data storage
│ └── Database.csv
│
└── README.md # Project documentation
```
