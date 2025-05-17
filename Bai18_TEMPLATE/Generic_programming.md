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
