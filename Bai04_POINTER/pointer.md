# POINTER
## 1. Con trỏ là gì?
- Con trỏ (Pointer) là một biến chứa giá trị là địa chỉ của một biến khác, tức là địa chỉ trực tiếp của vị trí bộ nhớ (memory location). Giống như bất kỳ biến hoặc hằng số nào, bạn phải khai báo một con trỏ trước khi sử dụng nó để lưu trữ địa chỉ của bất kỳ biến nào.
![image](https://github.com/user-attachments/assets/08319d24-d71b-4629-adf4-e26dfea1000f)

- Dạng tổng quát của khai báo biến con trỏ là:
  ```cpp
  type *var-name;
  ```
Trong đó `type` là kiểu dữ liệu con trỏ, `var-name` là tên biến con trỏ, `*` khai báo con trỏ.

- Ví dụ:
```cpp
int    *ip;    /* pointer to an integer */
double *dp;    /* pointer to a double */
float  *fp;    /* pointer to a float */
char   *ch     /* pointer to a character */
```
## 2. Sử dụng con trỏ.
- Con trỏ sử dụng khá linh hoạt gồm sử trỏ đến biến, hàm, hằng, con trỏ khác và một số dạng như hằng con trỏ, con trỏ null. Chúng ta sẽ tìm hiểu lần lượt như sau:
### 2.1 Con trỏ trỏ đến biến.
Ta có thể dùng như này trực tiếp vừa khai báo vừa trỏ đến địa chỉ biến
```cpp
int m = 2;
int *ptr = &m;
```
hoặc 
```cpp
int m = 2;
int *ptr;
ptr = &m
```
khai báo con trỏ trước rồi trỏ đến địa chỉ biến.
Ta cũng có thể dùng con trỏ trỏ đến một mảng như sau:
```cpp
int arr[]={1, 2, 3};
int *ptr = &arr;
int *ptr1 = &arr[0];
printf("%p\n%p",ptr,ptr1);
```
Kết quả:
`
0x7ffcc4d9428c
0x7ffcc4d9428c`
Tại sao 2 con trỏ lại trỏ đến địa chỉ giống nhau? Bình thường thì địa chỉ của một mảng chính là địa chỉ của ô đầu tiên trong mảng đó.
Vậy muốn trỏ đến địa chỉ khác trong mảng thì ta chỉ cần `ptr+i` thì sẽ đến vị trí phần tử mà ta muốn, muốn quay lại thì chỉ cần `ptr-i` là được.
* Lưu ý con trỏ chỉ trỏ đến biến có cùng kiểu dữ liệu nếu trỏ đến khác kiểu dữ liệu thì sẽ lỗi như sau:
 ![image](https://github.com/user-attachments/assets/35ec6aa5-7139-49bd-a40b-bafcc1e43e3e)
Vậy có con trỏ nào có thể trỏ đến biến khác kiểu dữ liệu không?
Có đó là `void pointer` .
Void pointer thường dùng để trỏ để tới bất kỳ địa chỉ nào mà không cần biết tới kiểu dữ 
liệu của giá trị tại địa chỉ đó.
- Cú pháp:
  ```cpp
  void *ptr_void;
  ```
```cpp
#include <stdio.h>
int main(){
	char a = 'c';
	int b = 15;
	void *ptr;
	ptr = &a;
	ptr = &b;
	return 0;
}
```
Trong ví dụ này ptr hoàn toàn có thể trỏ tới bất kỳ đâu mà nó muốn mà không gặp lỗi.
### 2.2 Con trỏ hàm
-  Pointer to function (con trỏ hàm) là một biến mà giữ địa chỉ của một hàm. Có nghĩa 
là, nó trỏ đến vùng nhớ trong bộ nhớ chứa mã máy của hàm được định nghĩa trong 
chương trình.
-  Trong ngôn ngữ lập trình C, con trỏ hàm cho phép bạn truyền một hàm như là một 
đối số cho một hàm khác, lưu trữ địa chỉ của hàm trong một cấu trúc dữ liệu, hoặc thậm 
chí truyền hàm như một giá trị trả về từ một hàm khác.
- Cú pháp:
  ```cpp
  <return_type> (* func_pointer)(<data_type_1>, <data_type_2>);
  ```
- Ví dụ:
```cpp
int (*fptr1)(int);
int square(int num) {
    return num*num;
}
int n = 5;
fptr1 = square;
printf("%d squared is %d\n",n, fptr1(n));
```
Ở dòng 87 `fptr1 = square` tại sao lại không dùng `fptr1 = &square` vì trong ngữ cảnh này việc dùng toán tử địa chỉ là không cần thiết và dư thừa vì trình biên dịch sẽ bỏ qua toán tử address-of một cách hiệu quả khi được sử dụng trong ngữ cảnh này.
![image](https://github.com/user-attachments/assets/348390a0-505a-4aaa-9f14-8b9612e93199)
### 2.3 Con trỏ hằng - Pointer to Constant
- Là cách định nghĩa một con trỏ không thể thay đổi giá trị tại địa chỉ mà 
nó trỏ đến thông qua dereference nhưng giá trị tại địa chỉ đó có thể thay đổi.
- Cú pháp:
```cpp
int const *ptr_const;
const int *ptr_const;
```
- Ví dụ:
  ```cpp
  #include <stdio.h>
  #include <stdlib.h>
  int main() {
	 int value = 5;
	 int test = 8;
	 int const *ptr_const = &value;
	 //*ptr_const = 7; // wrong
	 //ptr_const = &test; // right
	 printf("value: %d\n", *ptr_const);
	 value = 9;
	 printf("value: %d\n", *ptr_const);
	 return 0;
	}
  ```
Việc thực hiện thay đổi giá trị trong con trỏ hằng là không đúng. Ta chỉ có thể thay đổi được địa chỉ con trỏ trỏ vào bằng cách thay đổi địa chỉ của biến.
### 2.4 Hằng con trỏ - Constant Pointer
- Định nghĩa một con trỏ mà giá trị nó trỏ đến (địa chỉ ) không thể thay đổi. Tức 
là khi con trỏ này được khởi tạo thì nó sẽ không thể trỏ tới địa chỉ khác.
- Cú pháp:
```cpp
int *const const_ptr = &value;
```
- Ví dụ:
```cpp
#include <stdio.h>
#include <stdlib.h>
int main() {
 int value = 5;
 int test = 15;
 int *const const_ptr = &value;
 printf("value: %d\n", *const_ptr);
 *const_ptr = 7;
 printf("value: %d\n", *const_ptr);
 //const_ptr = &test; // wrong
 
 return 0;
}
```
Ta có thể thay đổi giá trị trong hằng con trỏ, nhưng việc thay đổi địa chỉ thì không đúng.
### 2.5 Con trỏ trỏ đến con trỏ - Pointer to Pointer
- Con trỏ đến con trỏ (Pointer to Pointer) là một kiểu dữ liệu trong ngôn ngữ lập trình 
cho phép bạn lưu trữ địa chỉ của một con trỏ. Con trỏ đến con trỏ cung cấp một cấp bậc 
trỏ mới, cho phép bạn thay đổi giá trị của con trỏ gốc. Cấp bậc này có thể hữu ích trong 
nhiều tình huống, đặc biệt là khi bạn làm việc với các hàm cần thay đổi giá trị của con 
trỏ.
- Cú pháp:
```cpp
type **name;
name = &single_ptr;        // After declaration - Đã khai báo trước đó
type **name = &single_ptr; // With declaration - Vừa khai báo vừa trỏ.
```
- Hình dung ví dụ sau đây:
![image](https://github.com/user-attachments/assets/a7a0140a-36d3-47ea-ac86-062294638c25)
- Bản chất ở đây cũng như con trỏ trỏ đến biến mà thôi, trường hợp này thì nó lại lưu địa chỉ của một con trỏ khác.
- Vậy con trỏ có thể trỏ đến con trỏ khác, nhưng một số trường hợp lưu ý là nên con trỏ trỏ đến con trỏ khác thấp hơn 1 cấp để đảm bảo việc không xảy ra nhiều bug ẩn về lỗi truy cập bộ số.
### 2.6 Con trỏ NULL - NULL Pointer
- Null Pointer là một con trỏ không trỏ đến bất kỳ đối tượng hoặc vùng nhớ cụ thể 
nào. Trong ngôn ngữ lập trình C, một con trỏ có thể được gán giá trị NULL để biểu 
diễn trạng thái null, C++ (NULL, nullptr).
- Sử dụng null pointer thường hữu ích để kiểm tra xem một con trỏ đã được khởi 
tạo và có trỏ đến một vùng nhớ hợp lệ chưa. Tránh dereferencing (sử dụng giá trị mà 
con trỏ trỏ đến) một null pointer là quan trọng để tránh lỗi chương trình.
Cho đoạn chương trình dưới đây:
```cpp
#include <stdio.h>
#include <stdlib.h>
int main() {
	int *ptr;
	printf("%p",ptr); 
	return 0;
}
Kết quả: 3 lần run:
1:0x7fff7b464408
2:0x7ffee8dce7a8
3:0x7ffd48689b08
```
Giống như biến khi chúng ta khai báo chưa có giá trị cụ thể thì biến đó nó được mang một giá trị bất kỳ luôn được thay đổi và con trỏ cũng vậy khi khai báo mà chưa trỏ đến địa chỉ cụ thể thì nó sẽ tự động trỏ đến địa chỉ bất kỳ. Để tránh bug ẩn trong quá trình code việc gán cho nó địa chỉ `null` là thật sự cần thiết
```cpp
#include <stdio.h>
#include <stdlib.h>
int main() {
	int *ptr = NULL;
	printf("%p",ptr); 
	return 0;
}
Kết quả: 3 lần run:
1:(nil)
2:(nil)
3:(nil)
```
