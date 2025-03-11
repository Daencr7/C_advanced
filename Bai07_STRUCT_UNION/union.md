# UNION
Sau khi đã đi qua struct thì đến với `union` kiểu cấu trúc khác tương tự như `struct` nhưng có một số điểm đặc biệt sau đây. Cùng tìm hiểu nhé!
## 1. Union là gì?
- Trong ngôn ngữ lập trình C, union là một cấu trúc dữ liệu giúp lập trình viên kết hợp nhiều kiểu dữ liệu khác nhau vào cùng một vùng nhớ. Mục đích chính của union là tiết kiệm bộ nhớ bằng cách chia sẻ cùng một vùng nhớ cho các thành viên của nó. Điều này có nghĩa là, trong một thời điểm, chỉ một thành viên của union có thể được sử dụng. Điều này được ứng dụng nhằm tiết kiệm bộ nhớ.
- Định nghĩa hơi dài đúng không? Nói gọn lại như này struct nó dùng nhiều vùng nhớ nhưng union chỉ một mà thôi.
- Cú pháp:
```cpp
union union_name {
    data_type member1;
    data_type member2;
    ...
    data_type memeberN;
};
```
Ví dụ:
```
union employee {
    int id;
    char name[50];
    float salary;
};
```
Vì chỉ một vùng nhớ nên kích thước của union thì là kích thước của phần tử lớn nhất trong đó. Đặc biệt như định nghĩa đã nói là tại một thời điểm thì chỉ lưu được một phẩn tử trong union mà thôi.
Ví dụ sau sẽ giúp ta hiểu được cái này.
```cpp
#include <stdio.h>
#include <string.h>
 
union Data {
   int i;
   float f;
   char str[20];
};
 
int main( ) {
   union Data data;        
   data.i = 10;
   data.f = 220.5;
   strcpy( data.str, "C Programming");
   printf( "data.i : %d\n", data.i);
   printf( "data.f : %f\n", data.f);
   printf( "data.str : %s\n", data.str);
   return 0;
}
```
Output:
```
data.i : 1917853763
data.f : 4122360580327794860452759994368.000000
data.str : C Programming
```
Ở ví dụ này ta có thể in ra chuẩn dạng của str mà thôi.
```cpp
#include <stdio.h>
#include <string.h>
 
union Data {
   int i;
   float f;
   char str[20];
};
 
int main( ) {
   union Data data;        
   data.i = 10;
   printf( "data.i : %d\n", data.i);
   
   data.f = 220.5;
   printf( "data.f : %f\n", data.f);
   
   strcpy( data.str, "C Programming");
   printf( "data.str : %s\n", data.str);
   return 0;
}
```
Output
```
data.i : 10
data.f : 220.500000
data.str : C Programming
```
Trường hợp này lại tốt hơn vì chỉ sử dụng mỗi phần tử ở mỗi thời điểm khác nhau.
## 2. Kết hợp union và struct
```
union Color {
    int value;
    struct {
        unsigned char a;
        unsigned char r;
        unsigned char g;
        unsigned char b;
    };
};
```
Ví dụ này ta có thể sử dụng value cùng một vùng bộ nhớ với struct để sử dụng nó một các tối ưu. Mỗi vùng 1bytes của value tương ứng với mỗi biến a,r,g,b.
