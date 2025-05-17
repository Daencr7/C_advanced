# GENERIC PROGRAMMING
Các template trong C++ được sử dụng để viết các đoạn code độc lập về `data_type`. Tại thời điểm biên dịch đoạn code thì sẽ được thay thế bằng một kiểu dữ liệu phù hợp, cái này được gọi là instantiation của code.

Kiểu này như dạng auto trong C++ hoặc python.

Class hoặc function được viết dưới dạng template được gọi là `Generics`. Những khai niệm này được gọi chung là Generic Programming trong C++.

## Sử dụng template
Trong C++, tất cả dữ liệu phải được lưu trữ trong một `container`.

Trong CPP việc viết các hàm khác nhau cho cả hai kiểu dữ liệu được ví dụ như `int` không có khả năng lưu trữ các giá trị `float`. Vì vậy phải viết hai hàm riêng biệt cho một chức năng thuộc hai kiểu dữ liệu khác nhau. Đều này gây ra lãng phí bộ nhớ. Vì vậy `Template` giải quyết vấn đề này bằng cách cung cấp một thuật toán tổng quát.
### Function Template
Function Template là kiểu template sử dụng chung cho các hàm.

Cú pháp:
```cpp
template <class identifier> function_declaration;
// or
template <typename identifier> function_declaration;
```
Ví dụ:

```cpp
#include <iostream>
using namespace std;
#define el cout<<"\n"

template <class T>

T sum2num(T a, T b){
    return a+b;
}
int main(){
    int a = 1;
    int b = 2;

    float x = 3.5, y = 2.6;

    cout << sum2num( a , b );el;
    cout << sum2num( x , y );el;
    // có thể ép kiểu từ float sang int thống qua template
    cout << sum2sum<int> (x , y);el; // sẽ ép kiểu x sang int, y sang int, rồi cộng 2 số int lại.
    return 0;
}
```
Đoạn code sử dụng function template cho việc tính tổng 2 số nguuyên a,b và 2 số float x, y.
Kết quả
```cpp
3         // trả về đúng kiểu cần là int
6.1       // trả về kết quả đúng kiểu floatfloat
5
```
Ví dụ:

```cpp

#include <iostream>
using namespace std;
#define el cout<<"\n"
// Tạo lớp persion với thuộc tính tên, tuổi và phương thức toString.
// Có hàm tạo Persion gán giá trị mặc định cho các thuộc tính ở vùng private
class Person{
    private:
        int age;
        string name;
    public:
        Person(string _name, int _age){
            age = _age;
            name = _name;
        }
        void toString(){
            cout << name <<" : "<< age << " Years old";el;
        }
};
// Sử dụng template làm kiểu dữ liệu cho một class Person
template <class T>
void printToScreen( T &per){
    per.toString();
}

int main(){

    Person p = Person("DEN", 18);//Tạo mặc định đối tượng
    printToScreen(p); // in ra màn hình
    
    return 0;
}
```
`Lưu ý: Các declaration & definition phải trong cùng một file.`

### Class Template
Giống như function template, việc sử dụng class template cũng tương tự nhưng với nhiều kiểu dữ liệu

Template chỉ áp dụng cho một định nghĩa cụ thể của class, không áp dụng cho tất cả các class.

Cú pháp:
```cpp
template <class T>
class className {
 // Class Definition.
 // We can use T as a type inside this class.
};
```

Ví dụ class template vs static variablevariable

```cpp
#include <iostream>
using namespace std;

template < class T >
  class Container {
    private:
      T data;
    public:
      static int count;
    Container() {
      count++;
    }

    static void displayStaticVariable() {
      cout << count << endl;
    }
  };

template < class T >
  int Container < T > ::count = 0;

int main() {
  Container < int > obj1;
  Container < float > obj2;
  Container < int > obj3;
  Container < int > ::displayStaticVariable();
  Container < float > ::displayStaticVariable();

  return 0;
}

```
Đối với các kiểu dữ liệu khác nhau, các biến tĩnh có các giá trị khác nhau, điều này cho thấy mỗi loại đều có một bản sao riêng biệt của biến tĩnh.

Ví dụ class template với kế thừa

Dùng kế thừa từ lớp không dùng template vào lớp dùng template.
```cpp
class Base {

};

template < class T >
class Derived: public Base {
    //Use T inside the Derived class
};
```
Sử dụng chung lớp dùng template thông qua lớp không template.
```cpp
template<class T>
class Base {
   
};

//Inheriting from the Base<int>
class Derived : public Base<int>{
   
};
```

```cpp
template<class T>
class Base {
  
};

template<class T>
class Derived : public Base<T>{
    //Pass the T to Base class
};
```

```cpp
template<class T>
class Base {
 
};

template<class U, class T>
class Derived : public Base<T>{
   //Use U in Derived class and pass T to Base class.
   //We can also use U and T in the Derived class.
};
```
So sánh templaTe với macro

![image](https://github.com/user-attachments/assets/a779f242-b2eb-45c6-b0d3-b3d841e2ffd3)

#### Template Specialization
Template Specialization cho phép tùy chỉnh hành vi của template cho một kiểu dữ liệu cụ thể.

Khi chúng ta viết bất kỳ hàm hoặc lớp dựa trên mẫu nào, trình biên dịch sẽ tạo ra một bản sao của hàm/lớp đó bất cứ khi nào trình biên dịch thấy nó được sử dụng cho một kiểu dữ liệu mới hoặc tập hợp các kiểu dữ liệu mới (trong trường hợp có nhiều đối số mẫu).

Nếu có một phiên bản chuyên biệt, trình biên dịch trước tiên sẽ kiểm tra với phiên bản chuyên biệt và sau đó là mẫu chính. Trình biên dịch trước tiên kiểm tra với phiên bản chuyên biệt nhất bằng cách khớp tham số được chuyển với (các) kiểu dữ liệu được chỉ định trong một phiên bản chuyên biệt.
Cú pháp:
```cpp
template <>
class name_of_class<data_type>
{
    private:
        data_type var;
}
```
Ví dụ:
```cpp
#include <iostream>
using namespace std;

template <class T>
class Test
{
  // Data members of test
public:
   Test()
   {
       // Initialization of data members
       cout << "General template object \n";
   }
   // Other methods of Test
};

template <>
class Test <int>
{
public:
   Test()
   {
       // Initialization of data members
       cout << "Specialized template object\n";
   }
};

int main()
{
    Test<int> a;
    Test<char> b;
    Test<float> c;
    return 0;
}
```
Ví dụ này là một specialization template cho kiểu `int`.
#### Variadic Template
Variadic Template cho phép tạo các hàm template hoặc lớp template có thể nhận một số lượng tham số không xác định. Điều này giúp bạn viết mã linh hoạt hơn khi làm việc với danh sách tham số có kích thước động.

Cú pháp:
```cpp
template(typename arg, typename... args)
return_type function_name(arg var1, args... var2)
```
Ví dụ:
```cpp
// C++ program to demonstrate working of
// Variadic function Template
#include <iostream>
using namespace std;

// To handle base case of below recursive
// Variadic function Template
void print()
{
    cout << "I am empty function and "
            "I am called at last.\n";
}

// Variadic function Template that takes
// variable number of arguments and prints
// all of them.
template <typename T, typename... Types>
void print(T var1, Types... var2)
{
    cout << var1 << endl;

    print(var2...);
}

// Driver code
int main()
{
    print(1, 2, 3.14,
          "Pass me any "
          "number of arguments",
          "I will print\n");

    return 0;
}
```
Ví dụ sử dụng variadic template cho hàm print với nhiều tham số được truyền vào khi không biết số lượng tham số đó là bao nhiêu.
