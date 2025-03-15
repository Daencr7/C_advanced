# MEMORY LAYOUT
# Memory Layout là gì?
 - Thắc mắc rằng mỗi khi mình viết chương trình thì máy tính hiểu các chương trình đó và nhớ nó kiểu gì? Đó chính là nhiệm vụ của memory layout.

![image](https://github.com/user-attachments/assets/ad074d83-03a1-4aae-8610-3203390fb458)

- Đây là hình miêu tả khá đầy đủ về memory layout.
- Bộ nhớ được chia thành nhiều vùng khác nhau. Trong đó bao gồm:
  - data segment
  - stack segment
  - heap segment
  - text segment
- Những vùng này chứa cái gì? Cùng tìm hiểu chi tiết từng vùng nhé!
# Text Segment
- Text segment là vùng nhớ thấp nhất trong các vùng, nó chứa các câu lệnh thực thi chương trình.
- Text segment thường có quyền có quyền đọc và thực thi, nhưng không có quyền ghi.
- Nó lưu hằng số toàn cục (const), chuỗi hằng - string literal.
- Tất cả các biến lưu ở vùng Text điều không thể thay đổi giá trị mà chỉ đọc được.
# Data segment
- Data segment thì có 2 vùng đó là DS và BSS
## Initialized Data - DS
- Là nơi lưu trữ `global variable` (biến toàn cục) và `static variables` (biến tĩnh)-các biến này phải được khởi tạo khác `0`.
Ví dụ
```cpp
int global = 100;
int foo() {
    static int number = 10;
    return 0;
}
```
global là biến toàn cục và number biến tĩnh khác 0.
## Unitialized Data - BBS
- BBS được viết tắt là Block Started by Symbol là phân đoạn dữ liệu chưa được khởi tạo.
- Vùng này lưu trữ global variables - biến toàn cục và static variables - biến tĩnh ở dạng không được khởi tạo hoặc khởi tạo với giá trị bằng 0.
* Không được khởi tạo là sao? Không được khởi tạo là biến được khai báo mà không gán giá trị cụ thể cho nó, làm nó ở trạng thái chứa giá trị _rác_.
- Ví dụ:
```cpp
int global;
int foo() {
    static int number = 0;
    return 0;
}
```
# Heap
- Heap này nghe quen :)) nhắc đến heap có lẽ ta nghĩ đến Dynamic Memory Allocation.
- Ở vùng này ta có thể kiếm soát được quá trình cấp phát hoặc giải phóng bộ nhớ bằng 4 lệnh trứ danh trong C (`malloc`, `calloc`, `relloc`, `free`).
- Malloc khởi tạo bộ nhớ động kích thước cho trước, realloc khi mà ta muốn thay đổi kích thước thì cần sử dụng realloc để đặt lại kích thước. calloc thì như malloc chỉ khác là malloc không thiết lập giá trị về `0` và calloc thì có.Cuối cùng là free để giải phóng bộ nhớ. (Nhắc lại để nhớ lâu hơn ạ).
- Đặc biệt hơn ở vùng nhớ này như một bao bố vậy mỗi khi cấp phát thì nó phình lên, khi giải phóng thì nó quay lại ban đầu. Nhưng mà khi ta quên giải phóng cho nó thì nó phình lên quá mức rồi xìu ra ra hiện tượng này tên là` memory leak` : _rò rỉ bộ nhớ_.
- _NHỚ GIẢI VÙNG NHỚ NÀY NHÉ_
# Stack
- Cuối cùng là stack nghe như kiểu cấu trúc dữ liệu stack vậy. Đừng nhầm nhé stack này cũng là `list in first out` nhưng mà dành cho bộ nhớ.
- Đây là vùng nhớ có địa chỉ cao nhất. Stack có cái gọi là Automatoc Variable Storage nghe như là vùng nhớ được cấp phát tự động.
- Nó lưu các biến cục bộ và tham số truyền trừ static.
- Nó là tự động nên khi thực hiện push pop xong thì nó tự động thu hồi vùng nhớ này lại.
- Và sau đây là ví dụ quá trính push pop của nó:
```cpp
int main() {
  int result = getResult();
}
int getResult() {
  int num1 = getNum1();
  int num2 = getNum2();
  return num1 + num2;
}
int getNum1() {
  return 10;
}
int getNum2() {
  return 20;
}
```
![image](https://github.com/user-attachments/assets/bab1c923-0179-46cc-9252-143ead098998)
* LƯU Ý HƠN KHI SỬ DỤNG HẾT VÙNG NHỚ NÀY SẼ VƯỚN STACK OVERFLOW NHÉ
