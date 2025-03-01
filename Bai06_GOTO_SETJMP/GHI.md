# GOTO
-
-
Ứng dụng thứ 2-> tạo ra các menu
Ứng dụng thứ 3-> Web leb
? Ý tưởng gắn một chân vào một led tạo led ma trận, TH k đủ chân thì k thể làm được
- Hạn chế nhảy trong phạm vi cục bộ hàm. -> muốn nhảy ngoài hàm thì sao?
  Sử dụng một thư viện setjmp

  setjmp sử đụng để lưu lại trạng thái chương trình, thanh ghi con trỏ,..
  lưu vào một biến kiểu jmp_buf kiểu như một struct
  return về một số nguyên, lần đầu tiên thì trả về 0 lần tiếp !=0.
  longjmp nhảy lại vị trí của setjmp
  sử dụng một đối số tên biến , mà đối số tiếp theo trả về cho setjmp
  Ứng dụng setjmp: sử lý lỗi " Xử lý ngoại lệ - Exception Handling "
  - Phát hiện lỗi, xử lý lỗi
