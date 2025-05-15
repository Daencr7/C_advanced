# CLASS
## Class là gì?
Class hay lớp là một mô tả trừu tượng của nhóm các đối tượng có cùng bản chất. Mỗi đối tượng là một thể hiện cụ thể trong những mô tả trừu tượng này.
### Đặc điểm của class
Một class gồm thuộc tính-property và phương thức-method.
Class thực chất là một kiểu dữ liệu do người dùng lập trình định nghĩa.
Ví dụ : Class xe hơi, xe hơi có thể có nhiều loại khác nhau, cấu tạo khác nhau theo các hãng khác nhau nhưng nhìn chung chúng có 4 bánh, chúng có độ cơ, vô lăng điều khiển,...Thì class xe hơi nó quy định một mẫu chúng như vậy.
## Sử dụng class
### Cú pháp khai báo
```cpp
class <ClassName> {
    <access_modifier>:
        <data_type> property;

        <return_type> <method_name>(arguments) {
            return <something_match_return_type>;
        }

        <_return_type> <_method_name>(_arguments);
};

<_return_type> <ClassName>::<_method_name>(_arguments) {
    return <something_match_return_type>;
}

```
Cơ bản khai báo gồm có 'class' đầu tiên vào sau đó là tên class.
Trong class bao gồm phạm vi truy cập, các phương thức (có thể là các hàm) và thuộc tính (các data member).
- Ví dụ:
```cpp
class MeoMeo{
    public:
        int age;
        string skin;
        string type;

        void cao(){
            cout <<"Cào\n";
        };
        void uoneo(){
            cout <<"Làm nũng\n";
        }
}
```
Trong ví dụ miêu tả một lớp `MeoMeo` có thuộc tính tuổi, màu lông, loại và có hai phương thức lần lược là `cao` và `uoneo`.
### Phạm vi truy cập Access modifiers
Có 3 phạm vi truy cập trong class C++, đó là `public`, `private` và `protected`.
- Các thuộc tính và phương thức mà được khai báo ở `public` thì có thể truy cập trực tiếp thông qua instance của class đó. Khi không có ràng buộc điều kiện trước khi gán hoặc không cần xử lý trước khi trả về giá trị thuộc tính thì nên khai báo `public'.
- Đối với các thuộc tính và phương thức mà được khai báo ở `private` thì chỉ có thể truy cập gián tiếp qua các phương thức `public` ( Getter và Setter ).
- Còn lại với `protected`, các phương thức và thuộc tính chỉ có thể truy cập qua các class kế thừa nó hoặc chính nó.
### Phương thức
Với phương thức có 2 cách khai báo cơ bản một là trong class, hai là ngoài class sử dụng toán tử `::`.
Ví dụ:
```cpp
Cách 1:
class Meo{
    public:
        int name;
        int age;
        void run(){
            cout <<"Running!\n";
        }
}
Cách 2:
class Meo{
    public:
        int name;
        int age;
}
void Meo::run(){
    cout <<"Running!\n";
}
```
Với cách phương thức không làm thay đổi giá trị thuộc tính của đối tượng thì nên thêm vào từ khóa `const`.
Ví dụ
```cpp
void Meo::run const(){
    cout <<"Running!\n";
}
```
hoặc
```cpp
void run const(){
    cout <<"Running!\n";
}
```
### Getter & setter với private
Khi các thuộc tính ở vùng private thì không thể truy cập trực tiếp từ bên ngoài. Cách có truy cập là thông quá các phương thức lấy các giá trị thuộc tính. Cái này gọi là _getter_ là các phương thức `lấy` giá trị của thuộc tính. Các phương thức `gán` giá trị thuộc tính thì được gọi là _setter_.
Ví dụ 
```cpp
class Meo{
    private:
        string _name;
    public:
        //Cái này là getter
        string getName(){
            return _name;
        }
        // Cái này là setter
        void setName(string name){
            _name = name;
        }
}
```
### Hàm tạo - Constructor
Constructor là một hàm đặc biệt, hàm này sẽ được gọi ngay khi khởi tạo một đối tương ( object ).
Constructor phải được khai báo ở `public`. Công dụng chính của constructor là khởi tạo các thuộc tính.
Constructor có tên trùng với tên class.
```cpp
class Person {
	public:
	    string firstName;
	    string lastName;
	    int age;

	    Person(string _firstName, string _lastName, int _age)
	    {
	        firstName = _firstName;
	        lastName = _lastName;
	        age = _age;
	    }

	    void fullname() {
			cout << firstName << ' ' << lastName;
	    }
};
```
Constructor cũng có thể được định nghĩa bên ngoài class thông qua toán tử `::`.
```cpp
Person::Person(string _firstName, string _lastName, int _age)
{
	firstName = _firstName;
	lastName = _lastName;
	age = _age;
}
```
Để khởi tạo một đối tượng qua constructor thì chỉ cần truyền tham số vào hàm thôi.
```cpp
Person person("Dang", "Nguyen Huu", 18);
person.fullname();
```
### Hàm hủy - Destructor
Thường dùng để hủy bỏ các phương thức mặc định khi đã dùng xong.
Việc này quan trọng trong việc giải phóng bộ nhớ tránh memory leak.
Tên Destructor cũng giống tên class chỉ khác là có thêm `~` vào trước hàm.
Ví dụ:
```cpp
class MyClass {
    public:
        MyClass() { // constructor
            cout << "Constructor is executedn";
        }

        ~MyClass() { // destructor
            cout << "Constructor is executedn";
        }
};

// Khởi tạo object
ClassName t; // gọi constructor không tường minh
// Gọi destructor tường minh
t.~MyClass();
```
### Static member
Static member hay thành viên tĩnh trong class C++ cũng tương tự như với static variable (biến tĩnh) trong function. Đối với function, sau khi thực hiện xong khối lệnh và thoát thì biến tĩnh vẫn sẽ không mất đi. Đối với class, thành viên tĩnh sẽ là thuộc tính dùng chung cho tất cả các đối tượng của class đó, cho dù là không có đối tượng nào tồn tại. Tức là bạn có thể khai báo nhiều object, mỗi object các thuộc tính của nó đều khác nhau nhưng riêng static thì chỉ có một và static member tồn tại trong suốt chương trình cho dù có hay không có object nào của nó hay nói ngắn gọn là dùng chung một biến static.

Các thành viên tĩnh của class có thể được truy cập từ bất kì đối tượng nào của class đó hoặc thông qua toán tử phạm vi (::). Biến tĩnh cũng có phạm vi truy cập như một biến thông thường (public, private và protected). Để khai báo một biến tĩnh, ta thực hiện thêm từ khóa “static” vào trước kiểu dữ liệu, sau đó khởi tạo giá trị bên ngoài như sau:
```cpp
class MyClass {
    public:
        static int count;
};

int MyClass::count = 0;
```
Phương thức tĩnh cũng giống như thuộc tính tĩnh, chúng ta có thể gọi trực tiếp qua toán tử phạm vi mà không cần một object nào của nó tồn tại cả.

Các phương thức tĩnh sẽ chỉ truy cập được đến các biến tĩnh và phương thức tĩnh khác chứ không được truy cập thành viên khác ngoài static member.
```cpp
class Person {
	public:
	    string firstName;
	    string lastName;

	    static void fullname() {
	        cout << firstName << ' ' << lastName; // không hợp lệ
	    }
};
```
