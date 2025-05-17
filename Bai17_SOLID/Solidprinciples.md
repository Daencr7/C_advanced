# SOLID
## Giới thiệu
SOLID là một tập hợp của năm nguyên tắc lập trình quan trọng được Robert C.Martin hay Uncle Bob đề xuất.

Những nguyên tắc này được thiết kế để giúp việc ngăn chặn việc phát sinh các vấn đề phổ biến trong lập trình, giúp code dễ bảo dưỡng, mở rộng và tái sử dụng.

Năm chữ cái viết tắt của `solid` đại diện cho năm nguyên tắc trong lập trình.
- SOLID:

S: `Single Responsibility Principle (SRP)`
O: `Open-Closed Principle (OCP)`
L: `Liskov Substitution Principle (LSP)`
I: `Interface Segregation Principle (ISP)`
D: `Dependency Inversion Principle (DIP)`
## Single Responsibility Principle (SRP)
`Nguyên tắc trách nhiệm đơn lẻ`

Mỗi phần của chương trình chỉ nên làm một việc duy nhất. Nếu một phần có nhiều nhiệm vụ, nó sẽ khó bảo trì và dễ gây lỗi khi thay đổi.

Chi tiết hơn về OOP thì một class chỉ thực hiện một công việc.

```cpp
class LearnEnglish{
  public:
    void WriteEnglish(){
    write_ac();
  }
  public:
    void SpeakEnglish(){
    speak_ac();
  }
};
```
Việc chia nhỏ ra có thể dễ dạng gọi đến lớp tương ứng với từng công việc, nó cũng dễ hơn khi maintain code và không phải sửa ở lớp chính quá nhiều, các đối tượng đã được tách biệt hoàn toàn về nhiệm vụ.
```cpp
class WriteEnglish{
  public:
    void write(){}
};
```
```cpp
class SpeakEnglish{
  public:
    void speak(){}
};
```
## Open-Closed Principle (OCP)
`Nguyên tắc đóng mở`

Cho phép mở rộng nhưng không sửa đổi code cũ. Khi cần thêm tính năng mới thì thêm code mới thay vì đổi code cũ.

Trong `OOP`, việc này dẫn đến tình trạng phát sinh nhiều class, nhưng chúng ta sẽ không cần phải test lại các class cũ nữa, mà chỉ tập trung vào test các class mới, nơi chứa các chức năng mới.
```cpp
// code không tuân thử OCP
class Payment
{
    public:
        void processPayment(string type)
        {
            if (type == "CreditCard")  
            {
                /* Xử lý thẻ tín dụng */
            }
            else if (type == "PayPal")
            {
                /* Xử lý PayPal */
            }
        }
};
```
Code được đổi theo nguyên tắc OCP.
```cpp
class PaymentMethod
{
    public:
        virtual void pay() = 0;
};
   
class CreditCard : public PaymentMethod
{
    public:
        void pay() override { /* Xử lý thẻ tín dụng */ }
};
   
class PayPal : public PaymentMethod
{
    public:
        void pay() override { /* Xử lý PayPal */ }
};

```
## Liskov Substitution Principle (LSP)
`Nguyên tắc phân vùng Liskov`

Nguyên tắc này nói răng trong một chương trình, các object của class con có thể thay thế class cha mà không làm thay đổi tính đúng đắn của chương trình.
```cpp
class Bird {
public:
    virtual void fly() {
        cout << "Bird is flying" << endl;
    }
};

class Ostrich : public Bird {
public:
    void fly() override {
        throw runtime_error("Ostrich can't fly!");
    }
};

void letBirdFly(Bird* bird) {
    bird->fly();
}

int main() {
    Bird* bird = new Ostrich();
    letBirdFly(bird);  // => Lỗi khi chạy!
}

```
Vấn đề ở đây là dù `Ostrich` là một `Bird`, nhưng nó không thể bay, do đó việc thay thế `Bird` bằng `Ostrich` gây lỗi.

Giải pháp khắc phục theo nguyên tắc LSP chính là chia `Bird` thành hai loại: `FlyingBird` và `NonFlyingBird`. Nhờ vậy không ép lớp con thực hiện những hành vi mà nó không hỗ trợ, từ đó tuân thủ nguyên tắc `Liskov`.
```cpp
class Bird {
public:
    virtual void makeSound() {
        cout << "Bird sound" << endl;
    }
    virtual ~Bird() {}
};

class FlyingBird : public Bird {
public:
    virtual void fly() {
        cout << "FlyingBird is flying" << endl;
    }
};

class Sparrow : public FlyingBird {
public:
    void fly() override {
        cout << "Sparrow is flying" << endl;
    }
};

class Ostrich : public Bird {
public:
    void makeSound() override {
        cout << "Ostrich sound" << endl;
    }
};

// Code sử dụng
void letBirdMakeSound(Bird* bird) {
    bird->makeSound();
}

void letBirdFly(FlyingBird* bird) {
    bird->fly();
}

int main() {
    Bird* o = new Ostrich();
    FlyingBird* s = new Sparrow();

    letBirdMakeSound(o);  // OK
    letBirdFly(s);        // OK
}

```
## Interface Segregation Principle (ISP)
`Nguyên tắc phân tách giao diện`

Nếu Interface quá lớn thì nên tách thành các interface nhỏ hơn, với nhiều mục đích cụ thể. Trong đó mỗi lớp chỉ nên cài đặt những gì nó cần.

Code vi phạm ISP thì với một lớp `TextBlogger` nhưng với những phương không liên quan lại trong lớp `TextBlogger`
```cpp
class TextBlogger : public IBlogger {
public:
    void writePost() override {
        cout << "Writing post..." << endl;
    }

    void uploadVideo() override {
        // Không dùng, nhưng vẫn phải cài đặt
        throw runtime_error("TextBlogger can't upload video.");
    }

    void livestream() override {
        // Không dùng, nhưng vẫn phải cài đặt
        throw runtime_error("TextBlogger can't livestream.");
    }
};
```
Mã nguồn sau khi được tách ra thành các interface nhỏ.
```cpp
class IWriter {
public:
    virtual void writePost() = 0;
    virtual ~IWriter() {}
};

class IVideoUploader {
public:
    virtual void uploadVideo() = 0;
    virtual ~IVideoUploader() {}
};

class ILivestreamer {
public:
    virtual void livestream() = 0;
    virtual ~ILivestreamer() {}
};
```
## Dependency Inversion Principle (DIP)
`Nguyên tắc đảo ngược phụ thuộc`

Các module cấp cao không nên phụ thuộc vào các module cấp thấp. Cả hai nên phụ thuộc vào abstraction.

Abstraction không nên phụ thuộc vào chi tiết. Mà chi tiết nên phụ thuộc vào abstraction.

Đơn giản hơn được hiểu:
- Code cấp cao (quy tắc, logic nghiệp vụ) không nên phụ thuộc trực tiếp vào code cấp thấp (cách thực hiện cụ thể).
- Thay vào đó, cả hai nên làm việc thông qua giao diện (interface/abstraction).

Code không tuẩn thủ DIP, UserManager phụ thuộc vào MySQLDatabase từ chi tiết cụ thể.
```cpp
class MySQLDatabase {
public:
    void connect() {
        cout << "Connected to MySQL" << endl;
    }
};

class UserManager {
    MySQLDatabase db;  // Phụ thuộc trực tiếp vào lớp cụ thể
public:
    void login() {
        db.connect();  // Khó thay thế bằng loại DB khác
    }
};
```
Code được chỉnh sửa theo nguyên tắc DIP
```cpp
// Abstraction
class IDatabase {
public:
    virtual void connect() = 0;
    virtual ~IDatabase() {}
};

// Cài đặt chi tiết
class MySQLDatabase : public IDatabase {
public:
    void connect() override {
        cout << "Connected to MySQL" << endl;
    }
};

class SQLiteDatabase : public IDatabase {
public:
    void connect() override {
        cout << "Connected to SQLite" << endl;
    }
};

// Module cấp cao
class UserManager {
    IDatabase* db;  // Phụ thuộc vào abstraction
public:
    UserManager(IDatabase* db) : db(db) {}

    void login() {
        db->connect();
    }
};

```
## Mỗi quan hệ của các nguyên tắc trong SOLID
![image](https://github.com/user-attachments/assets/7979631b-062f-4fb3-a5a7-b68622278ff2)
