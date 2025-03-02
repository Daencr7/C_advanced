# SETJMP
## 1. Setjmp.h là gì?
-  `setjmp.h` là một thư viện trong ngôn ngữ lập trình C, cung cấp hai hàm chính là 
`setjmp` và `longjmp`. Cả hai hàm này thường được sử dụng để thực hiện xử lý ngoại lệ 
trong C, mặc dù nó không phải là một cách tiêu biểu để xử lý ngoại lệ trong ngôn ngữ 
này.
## 2. Sử dụng setjmp.h
- Cú pháp khai báo:
`jmp_buf`: Đây là một kiểu mảng được sử dụng để giữ thông tin cho macro setjmp() và hàm longjmp().
```int setjmp(jmp_buf environment)``` :Macro này lưu trữ môi trường (environment) hiện tại bên trong biến environment để sử dụng sau bởi hàm longjmp(). Nếu macro này trả về một cách trực tiếp từ lời gọi macro, thì nó trả về 0; nhưng nếu nó trả về từ một lời gọi hàm longjmp(), thì một giá trị khác 0 được trả về.
`environment` − Đây là đối tượng của kiểu jmp_buf nơi mà thông tin về môi trường được lưu trữ.
`void longjmp(jmp_buf environment, int value)`: Hàm này phục hồi môi trường (environment) đã được lưu trữ bởi lời gọi gần nhất tới macro `setjmp()` trong cùng lời gọi hàm của chương trình với tham số tương ứng là `jmp_buf`. `value` là giá trị để biểu thức `setjmp` ước lượng.
- Ví dụ:
```cpp
#include <setjmp.h> 
#include <stdio.h> 
jmp_buf buf; 
void func() {  // func được mở và in ra Welcome to GfG
    printf("Welcome to GeeksforGeeks\n"); // longjmp(buf,1) phục hồi lại môi trường lưu từ setjmp()
    longjmp(buf, 1);  // Thực hiện gọi lại setjmp(buff) đến dòng 24 lúc này giá trị sẽ khác 0
    printf("Geek2\n"); 
} 
int main() { 
    if (setjmp(buf))  // ban đầu setjmp(buf) = 0 vì nó gọi bằng macro sẽ nhảy qua else in ra Geek4 và đến func();
        printf("Geek3\n"); 
    else { 
        printf("Geek4\n"); 
        func(); 
    } 
    return 0; 
}
```
