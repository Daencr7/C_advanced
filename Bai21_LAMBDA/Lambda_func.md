# LAMBDA - FUNCTOR

# 1. Lambda
Là hàm vô danh (anonymous function) được định nghĩa ngay tại nơi sử dụng.
Lambda được hỗ trợ từ phiên bản C++11

Biểu thức lambda cho phép các hàm nội tuyến có thể được sử dụng cho các đoạn mã ngắn sẽ không được sử dụng lại. Vì vậy `không yêu cầu` tên cho hàm.

Cú pháp:
```cpp
[capture-clause] (parameters) -> return-type { 
    // definition
}
```
`_return-type_`: biểu thức lambda được đánh giá bởi chính trình biên dịch và chúng ta không cần phải chỉ định một cách rõ ràng. Tuy nhiên, trong một số trường hợp phức tạp, ví dụ như câu lệnh điều kiện, trình biên dịch không thể xác định kiểu trả về và cần có đặc tả rõ ràng.

`_parameters_`: là tham số bình thường có thể có hoặc không có trong lambda. Lambda còn có thể nhận một lambda khác làm đối số.

`_capture-clause_`: Một biểu thức lambda có thể tốt hơn một hàm thông thường bằng cách có quyền truy cập vào các biến từ phạm vi bao quanh. Có thể nắm bắt các biến bên ngoài từ phạm vi bao quanh theo ba cách sử dụng _capture-clause_.
- Cách 1: [&] : bắt tất cả các biến bên ngoài bằng tham chiếu.
- Cách 2: [=] : bắt tất cả các biến bên ngoài theo giá trị.
- Cách 3: [a, &b] : bắt a theo giá trị và chụp b bằng tham chiếu.

Sử dụng `lambda` với _capture-clause_.
- Bắt gán giá trị chi tiết hoặc bắt toàn bộ biến biên ngoài hàm.
```cpp
int x = 10;
// Thay thế trực tiếp x = 10 vào trong hàm.
auto func = [x](){
    cout << x;
};
func();
```
```cpp
int a = 1;
int b = 2;
int c = 3;
int d = 4;
// Dùng dấu `=` để có thể bắt tất cả các biến bên ngoài mà không cần khai báo.
auto res = [=]() -> int{
    return a + b + c + d;
};
```
- Bắt theo tham chiếu từng biến bên ngoài hoặc toàn bộ. Khi dùng tham chiếu thì tất nhiên thay đổi giá trị biên trong hàm sẽ thay đổi giá trị biên ngoài hàm.
```cpp
int x = 10;
int y = 20;
// Khai báo sử dụng biến x làm tham chiếu theo kiểu bắt rêng lẻ
auto func = [&x](){
    x += 5;
};
auto func1 = [&](){
    x += 1;
    y += 1
}
func(); //Thay đổi theo riêng lẻ
func1(); //Thay đổi theo tất cả các biến bên ngoài hàm.
```
- Bắt theo biến với nhiều kiểu bắt khác nhau.
    - [&total, factor]
    - [factor, &total]
    - [&, factor]
    - [factor, &]
    - [=, &total]
    - [&total, =]
```cpp
int a = 1, b = 2;

auto res = [=, &a]() mutable{
    a = 10;
    b = 20;
};
res();
cout << b;el;
```

Dùng `mutable` trong lambda: Thông thường khi bắt biến theo giá trị, biến đố là const mặc định bên trong lambda. Nếu muốn thay đổi bản sao trên trong lambda thì có thể dùng `mutable`.
```cpp
#include <iostream>
using namespace std;
#define el cout<<"\n"
int main(){
    int a = 1;
    auto res = [a]() -> void{
        a = 10;
    };
    res();
    return 0;
}
```
![image](https://github.com/user-attachments/assets/bfb093cd-8e9c-4ea1-805d-9eef562f87a3)

- > Lỗi
```cpp
#include <iostream>
using namespace std;
#define el cout<<"\n"
int main(){
    int a = 1;
    auto res = [a]() mutable{
        a = 10;
    };
    res();
    cout << a;
    return 0;
}
```
- > Vậy có thể thay đổi bản sao bên trong nội bộ hàm lambda mà không xảy ra `error`.
# 2. Functor

Functor có thể làm một hàm tự do, hoặc có thể là một function pointer. Nhưng thực tế rằng những hàm này đã wrap các function/function pointer được truyền vào thành một Function Object và gọi function object đó khi cần thiết.
Vậy chính xác hơn, functor là một function object.

Function object được sử dụng rất nhiều trong thư viện STL C++, và nên viết functor để sử dụng các thuật toán, các chức năng của STL một các hiệu quả hơn.

Đặc điểm của Functor:
- Là hàm thành viên có quyền truy cập là public.
- Không phải là static method.
- Có khai báo operator().

Ví dụ:
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
 
class Incrementor {
public:
    // sử dụng functor với việc khai báo operator, trong phạm vi public
    void operator()(int& i) {
        ++i;
        std::cout << i << ' ';
    }
};
 
int main() {
    std::vector<int> v = {1, 2, 3, 4, 5, 6};
 
    Incrementor in;
 
    std::for_each(v.begin(), v.end(), in);
    std::cout << std::endl;
 
    return 0;
}
```
