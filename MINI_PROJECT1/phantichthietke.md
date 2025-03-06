# Phân tích thiết kệ hệ thống quản lý module trên oto
# 1. Mô tả và thiết kế
- Project quản lý các module trạng thái module trong ô tô.
- Project bao gồm 3 folder chính Automotive_Module_Manager, manager, handler.
- Automotive_Module_Manager: chứa file main.c, module_manager.c, module_manager.h.
    - Trong này sẽ chứa các hàm bao gồm:
        + _configureModulecars_: thực hiện setup các giá trị, thông số module như ID, tên, trạng thái, quyền truy cập, hoạt động điều khiển.
        + _setControls_: thiết lập hoạt động điều khiển như tắt mở, tăng nhiệt độ, giảm nhiệt độ.
        + _displayModulecars_: in các thành phần trong một module ra màn hình
        + _create_modules_: thực hiện cấp phát độ danh sách module với malloc.
        + _create_module_newsizes_: thực hiệp cấp phát lại danh sách module khi có sự thay đổi kích thước.
        + _freeCarmodules_: giải phóng danh sách khỏi bộ nhớ.
- manager : chưa các file bitmask, function_handler: thực hiện điều khiển tráng thái mà lưu trạng thái.
    - bitmask:
        + _setStatus_: thiết lập trạng thái của module dựa vào define bitmask off, on, error, warning.
        + _unsetStatus_: hủy thiết lập trạng thái.
    - function_handler: điều khiển hoạt động trạng thái bằng con trỏ hàm
        + _checkModule_status_: kiểm tra và in trạng thái ra màn hình
        + _controlActivity_: điều khiển hoạt động
        + _turnOnModule_status_: mở trạng thái
        + _turnOffModule_status_: tắt trạng thái
- handler : kiểm tra và xử lý lỗi
        + _checkError_: so sánh giữa trạng thái modlue và trạng thái lỗi thực hiện trả về trạng thái an toàn
        + _noncheckError_: thực hiện check lỗi, có lỗi thì ra thông báo, không lỗi tiếp tục chương trình.

# 2. Cách sử dụng bitmask, function poiter, setjmp (phần git bài học)
# 3. Flowchart chương trình.
![image](https://github.com/user-attachments/assets/3773285d-0b18-4330-a35d-03da2279ebda)
