# STACK 
## STACK là gì?
- Từ memory layout thì ta đã biết stack rồi, nhưng mà stack này nó khác nha.
- Stack là một `data structure` - _cấu trúc dữ liệu_ vẫn tuân thủ nguyên lý LIFO - Last In First Out.
- Cấu trúc dữ liệu được phân làm hai loại chính là cấu trúc dữ liệu tuyến tính và cấu trúc dữ liệu phi tuyến tính trong đó `stack` là cấu trúc dữ liệu tuyến tính.
- Vậy `Linear` - tuyến tính là gì và `Non-Linear` phi tuyến tính là gì? Một cách hiểu ở đây tuyến tính là data được lưu theo kiểu nối đuôi nhau còn phi tuyến tính thì nó sẽ rẻ nhánh.
## Mô hình và hoạt động
![image](https://github.com/user-attachments/assets/c0e3fef4-9657-4c92-b94b-ea0752381da9)
- Dữ liệu vào stack giống như ống cầu long vậy cái nào vào trước thì ra cuối cùng, vào cuối cùng thì được lấy ra trước.
Cùng tìm hiểu thêm xíu về độ phức tạp của từng phương thức trong stack nha.
![image](https://github.com/user-attachments/assets/ab826092-fe83-4006-a411-64c88a74665e)
- Các phương thức này đó độ phức tạp về thời gian O(1) nhỏ nhất và ổn định vì đơn giản các thao tác này chỉ thực hiện một bước O(1). Độc phức về không gian là O(n) vì các giá trị được khởi tạo và sử dụng n lần qua số lần duyệt.
- Stack ở C thì không có thư viện hỗ trợ sẵn và phải tự cài đặc nó. Về bản chất stack chỉ là một mảng(động hoặc tĩnh tùy cách dùng) và nó kết hợp với nguyên lý LIFO của nó là xong.
- Tham khảo đoạn code ở `file.c` nha.
