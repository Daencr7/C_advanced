# STORAGE CLASS
## 1. Extern
-  Khái niệm Extern trong ngôn ngữ lập trình C được sử dụng để thông báo rằng một 
biến hoặc hàm đã được khai báo ở một nơi khác trong chương trình hoặc trong một file 
nguồn khác. Điều này giúp chương trình hiểu rằng biến hoặc hàm đã được định nghĩa 
và sẽ được sử dụng từ một vị trí khác, giúp quản lý sự liên kết giữa các phần khác nhau 
của chương trình hoặc giữa các FILE nguồn.
- Cú pháp:
```
    extern var_type var_name;
    extern ret_type func_name (arg_types …. );
```
- Ví dụ:
```cpp
File src.c
--------------------
int ext_var = 22;

File main.c
--------------------
#include <stdio.h>
extern int ext_var;

void printExt() {
      printf("%d", ext_var);
}
int main() {
    printExt();
    return 0;
}
```
Để sử dụng lại biến có giá trị ở file khác ta không cần thiết phải include file khi nhu cầu sử dụng ít mà thay vào đó ta có thể sử dụng extern để khai báo đúng tên biến mà ta sử dụng.
## 2. Static local variables
```cpp
#include <stdio.h>
void exampleFunction() {
   int count = 0;
   count++;
   printf("Count: %d\n", count);
}
int main() {
   exampleFunction(); // In ra "Count: 1"
   exampleFunction(); // In ra "Count: 1"
   exampleFunction(); // In ra "Count: 1"
 return 0;
}
```
Trong đoạn chương trình này khi ra gọi hàm 3 lần thì giá trí trả về hàm đó đều như nhau và đạt giá trị là 1, muốn thay đổi giá trị trả về đó qua những lần gọi hàm thì có cách nào không?
- Đầu tiên một cách có thể thay đổi được đó là truyền toán tử địa chỉ vào hàm những cách này yêu cầu chúng ta cần khai báo thêm biến đếm và truyền tham số vào hàm.
- Cách hai là có thể cho biến đếm thành biến toàn cục là ta có thể thay đổi được giá trị mỗi khi gọi rồi.
Những 2 cách này đều làm thay đổi cấu trúc chương trình chúng ta, muốn thay đổi giá trị in ra những không thay đổi cấu trúc hàm thì làm sao?
-> Sử dụng khai báo biến static local ta sẽ giải quyết đưowjc vấn đề này.
```cpp
#include <stdio.h>
void exampleFunction() {
   static int count = 0;
   count++;
   printf("Count: %d\n", count);
}
int main() {
   exampleFunction(); // In ra "Count: 1"
   exampleFunction(); // In ra "Count: 2"
   exampleFunction(); // In ra "Count: 3"
 return 0;
}
```
## 3. Static global variables 
-  Khi static được sử dụng với global variables ( biến toàn cục - khai báo biến bên 
ngoài hàm), nó hạn chế phạm vi của biến đó chỉ trong file nguồn hiện tại.
-  Ứng dụng: dùng để thiết kế các file thư viện.
- Ví dụ ứng dụng của static global cho thư viện:
```cpp
-------------- FILE motor.c
#include <stdio.h>
#include "motor.h"
void startMotor(PIN pin) {
   printf("Start motor at PIN %d\n",pin);
}
void stopMotor(PIN pin) {
   printf("Stop motor at PIN %d\n",pin);
}
-----------------FILE motor.h
#ifndef __MOTOR_H
#define __MOTOR_H
typedef struct {
  void (*start)(int gpio);
  void (*stop)(int gpio);
} MotorController;
typedef int PIN;
static void startMotor(PIN pin);
static void stopMotor(PIN pin);
```
## 4. Static trong class
-  Khi một thành viên của lớp được khai báo là static, nó thuộc về lớp chứ không 
thuộc về các đối tượng cụ thể của lớp đó. Các đối tượng của lớp sẽ chia sẻ cùng một bản 
sao của thành viên static, và nó có thể được truy cập mà không cần tạo đối tượng. Nó 
thường được sử dụng để lưu trữ dữ liệu chung của tất cả đối tượng.
## 5. Volatile

## 6. Register
