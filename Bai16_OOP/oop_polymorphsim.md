# ĐA HÌNH - POLYMORPHSIM
Đa hình luôn đi kèm với kế thừa.

 Do tính kế thừa, một lớp có thể sử dụng lại các phương thức của lớp khác. Tuy nhiên, nếu cần thiết, lớp dẫn xuất cũng có thể định nghĩa lại một số phương thức của lớp cơ sở. Đó là sự nạp chồng phương thức trong kế thừa. Nhờ sự nạp chồng phương thức này, ta chỉ cần gọi tên phương thức bị nạp chồng từ đối tượng mà không cần quan tâm đó là đối tượng của lớp nào. Chương trình sẽ tự động kiểm tra xem đối tượng là thuộc kiểu lớp cơ sở hay thuộc lớp dẫn xuất, sau đó sẽ gọi phương thức tương ứng với lớp đó. Đó là tính đa hình. 

 Tóm lại có thể hiểu là một hành động - nhiều cách thực hiện khác nhau phụ thuộc hành động đó cho cái gì.

Ví dụ
```cpp
class Car{  
	public: 	 	 	
	void show(); 
}; 
class Bus: public Car{  	
    public: 	 	 	
    void show(); 
};
Bus myBus;
Car *ptrCar = &myBus;
ptrCar->show();
```
Con trỏ đối tượng lớp Car đang chỉ về đối tượng lớp bus, nhưng sau khi truy cập hàm show()
thì hàm show() của lớp Car lại được xuất ra chứ không phải hàm show() của lớp Bus.

Cú pháp khai báo:
```cpp
//Nếu khai báo trong phạm vi lớp: 
virtual <Kiểu trả về> <Tên phương thức>([<Các tham số>]); 

//Nếu định nghĩa ngoài phạm vi lớp: 
virtual <Kiểu trả về> <Tên lớp>::<Tên phương thức>([<Các tham 
số>]){…} 
```
# Nạp chổng - Overloading
Trong một lớp, ta có thể tạo ra nhiều hàm với cùng một tên gọi nhưng khác nhau các dữ liệu đầu vào hoặc tham số, đó gọi là nạp chồng.

Có thể nạp chồng với:
- Methods
- Constructors
- Indexed properties

Các kiểu nạp chồng gồm: `nạp chồng phương thức` và `nạp chồng các toán tử`.

Nạp chồng phương thức:

Trong một lớp, ta có thể tạo ra nhiều hàm với cùng một tên gọi nhưng khác nhau các dữ liệu đầu vào hoặc tham số, đó gọi là nạp chồng phương thức.
Lới ích của việc quá tải phương thức là chúng ta có thể khai báo cùng một tên phương thức trong cùng chương trình, không cần phải khai báo tên khác cho cùng một hành đông.

Ví dụ:
```cpp
class Cal {
public:
	static int add(int a, int b) {
		return a + b;
	}
	static int add(int a, int b, int c)
	{
		return a + b + c;
	}
};
int main(void) {
	Cal C;
  // có thể gọi methods add 2 hay 3 tham số.
	cout << C.add(10, 20) << endl;
	cout << C.add(12, 20, 23);
	return 0;
}
```
Nạp chồng toán tử: là định nghĩa lại toán tử.
```cpp
class Test
{
private:
	int num;
public:
	Test() : num(8) {}
	void operator ++()
	{
		num = num + 2;
	}
	void Print() {
		cout << "The Count is: " << num;
	}
};
int main()
{
	Test tt;
	++tt;  // calling of a function "void operator ++()"  
	tt.Print();
	system("pause");
	return 0;
}
```

# Ghi đè - Overriding
Lớp dẫn xuất định nghĩa lại cùng một phương thức đã định nghĩa ở lớp cơ sở thì nó là ghi đè.

Phương thức ghi đè cho phép cung cấp việc thực hiện cụ thể chức năng đã được lớp cơ sở của nó cung cấp.

```cpp
class Animal {
public:
	void eat() {
		cout << "Eating...";
	}
};
// Thực hiện ghi đè lại eat() trong lớp Dog, eat() đã được định nghĩa trong lớp Animal trước đó
class Dog : public Animal
{
public:
	void eat()
	{
		cout << "Eating bread...";
	}
};
int main(void) {
	Dog d = Dog();
	d.eat();
	return 0;
}
```

# Phương thức ảo - virtual
Phương thức ảo nằm trong lớp cơ sở chúng ta có thể định nghĩa lại trong lớp dẫn xuất. Nó được khai báo bằng từ khóa virtual

Phương thức ảo được sử dụng để thực hiện liên kết động (dynamic linkage) hoặc ràng buộc (binding) trong phương thức.

Phương thức được gọi là ràng buộc  được giải quyết trong thời gian chạy. Do đó trình biên dịch xác định loại đối tượng trong thời gian chạy, và sau đó liên kết các phương thức được gọi.
```cpp
  class A
  {
  public:
    virtual void display()
    {
      cout << "Lop co so duoc goi" << endl;
    }
  };
  class B :public A
  {
  public:
    void display()
    {
      cout << "Lop ke thua duoc goi" << endl;
    }
  };
  int main()
  {
    A* a;    //pointer of base class  
    B b;     //object of derived class  
    a = &b;
    a->display();   //Late Binding occurs  
  }
```
