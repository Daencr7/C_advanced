#include <iostream>
using namespace std;

// Class tổng quát sử dụng Variadic Template
template <typename... Args>
class MyClass;

// Định nghĩa class khi không có đối số
template <>
class MyClass<>
{
    public:
    // Khởi tạo methods display() ở publicpublic
        void display()
        {
            cout << "No arguments" << endl;
        }
};

// Định nghĩa class khi có ít nhất một đối số
template <typename T, typename... Args>
class MyClass<T, Args...> : public MyClass<Args...>
{
    private:
        // khởi tạo thuộc tính first_ với template TT
        T first_;

    public:
 // T first_ = first, Args1 args1_ = args1, Args2 args2_ = args2,...
        MyClass(T first, Args... args): first_(first),  MyClass<Args...>(args...){} 

        // Khởi tạo display() method ở publicpublic
        void display()
        {
            cout << first_ << " ";
            MyClass<Args...>::display(); // Gọi hàm display của lớp cơ sở
        }  

};

int main()
{
    // khởi tạo đối tượng obj với 3 đối số khác nhau về kiểu dữ liệu
    MyClass<int, double, char> obj(1, 2.5, 'A');
    obj.display();  // Kết quả: 1 2.5 A

    MyClass obj1;
    obj1.display();
    return 0;
}
