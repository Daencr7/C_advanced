# ĐÓNG GÓI - ENCAPSULATION
Có thể nói tính đóng gói (Encapsulation) là cơ chế của che giấu dữ liệu (Data Hiding) bởi chúng được lớp (class) che giấu đi (ở dạng private) một số dữ liệu, hàm và phương thức để đảm bảo rằng các dữ liệu đó sẽ được truy cập và sử dụng đúng mục đích, đúng cách thông qua các hàm và phương thức ở dạng public mà class cung cấp. Đó là lý do bạn không thể truy cập đến các thuộc tính private hoặc gọi đến phương thức private của class từ bên ngoài class đó.

Tính đóng gói được thể hiện khi mỗi đối tượng mang trạng thái là private ở bên trong một class và những đối tượng khác không thể truy cập trực tiếp vào phạm vi này. Thay vào đó họ chỉ có thể gọi các hàm mang phạm vi public được gọi là phương thức.

Cụ thể, đối tượng sẽ mang trạng thái riêng thông qua các phương thức và không một class nào khác có thể truy cập vào được trừ khi cho phép. Nói chung trạng thái đối tượng không hợp lệ thường do chưa được kiểm tra tính hợp lệ, các bước thực hiện không đúng trình tự hoặc bị bỏ qua nên trong OOP có một quy tắc quan trọng cần nhớ đó là phải luôn khai báo các trạng thái bên trong của đối tượng là private và chỉ cho truy cập qua các public/protected method

Hãy tưởng tượng chúng ta xây dựng trò chơi tên Lửa Không Miễn Phí và có các nhân vật giao tiếp với nhau. Chúng ta muốn áp dụng tính đóng gói nên đã gói gọn tất cả những gì liên quan tới các nhân vật với nhau thành một lớp nhân vật, nó trông như thế này:

![image](https://github.com/user-attachments/assets/21b1d4ba-e322-45cc-9bc3-9540ab83d6ba)
