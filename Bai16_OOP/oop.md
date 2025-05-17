# OOP
## Giới thiệu
OOP là Object-oriented programming là một mẫu hình lập trình dựa trên khái niệm "công nghệ đối tượng". Trong đó đối tượng chứa các dữ liệu trên các trường gọi là thuộc tính (property), được tổ chức thành phương thức.

Phương thức có thể truy xuất và hiệu chỉnh các trường dữ liệu của đối tượng khác mà đối tượng hiện tại có tương tác.

Một đối tượng gồm thuộc tính và phương thức. Để tạo ra đối tượng cần dựa vào khuôn mẫu class.

Các tính chất của lập trình hương đối tượng bao gồm:
- `Tính kế thừa (Inheritance)`
Kế thừa Kế thừa là khả năng cho phép xây dựng một lớp mới dựa trên các cơ sở (định nghĩa) của một lớp có sẵn và có bổ sung phương thức hay thành phần dữ liệu. Khả năng sử dụng kế thừa các module chương trình rất dễ dàng mà không cần thay đổi module khác.
- `Tính đa hình (Polymorphism)`
Tính đa hình sẽ xuất hiện khi có khái niệm kế thừa và có khả năng cho phép gửi cùng một thông điệp đến những đối tượng khác nhau mà không cần biết đối tượng nhận thuộc lớp dữ liệu nào, chỉ cần tập hợp các đối tượng nhận có chung hoặc gắn liền với một tính chất nào đó.
- `Tính trừu tượng (Abstraction)`
Lớp trừu tượng là một lớp mà nó không thể thực thể hóa thành một đối tượng thực dụng được. Lớp này được thiết kế nhằm tạo ra một lớp có các đặc tính tổng quát nhưng bản thân lớp đó chưa có ý nghĩa (hay không đủ ý nghĩa) để có thể tiến hành viết mã cho việc thực thể hóa.
- `Tính đóng gói (Encapsulation)`
Trong lập trình hướng đối tượng, cả chức năng và dữ liệu đều phải được đóng gói, mỗi đối tượng sẽ không thể truy cập trực tiếp vào các thành phần dữ liệu mà phải thông qua các thành phần chức năng để làm việc đó. Như vậy, đóng gói cho phép dữ liệu của đối tượng sẽ bị che đi một phần khi nhìn từ bên ngoài

## Phạm vi truy nhập lớp
- Phạm vi khối lệnh: Trong phạm vi giữa hai dấu giới hạn “{}” của một khối lệnh. Ví dụ các lệnh trong khối lệnh lặp while(){} sẽ có cùng phạm vi khối lệnh. 
- Phạm vi hàm: Các lệnh trong cùng một hàm có cùng mức phạm vi hàm. 
- Phạm vi lớp: Các thành phần của cùng một lớp có cùng phạm vi lớp với nhau: các thuộc tính và các phương thức của cùng một lớp. 
- Phạm vi chương trình (còn gọi là phạm vi tệp): Các lớp, các hàm, các biến được khai báo và định nghĩa trong cùng một tệp chương trình thì có cùng phạm vi chương trình. 
- Trong phạm vi truy nhập lớp, ta chỉ quan tâm đến hai phạm vi lớn nhất, đó là phạm vi lớp và phạm vi chương trình. Trong C++, phạm vi truy nhập lớp được quy định bởi các từ khóa về thuộc tính truy nhập: 
- private: Các thành phần của lớp có thuộc tính private thì chỉ có thể được truy nhập trong phạm vi lớp.  
- protected: Trong cùng một lớp, thuộc tính protected cũng có ảnh hưởng tương tự như thuộc tính private: các thành phần lớp có thuộc tính protected chỉ có thể được truy nhập trong phạm vi lớp. Ngoài ra nó còn có thể được truy nhập trong các lớp con khi có kế thừa 
- public: các thành phần lớp có thuộc tính public thì có thể được truy nhập trong phạm vi chương trình, có nghĩa là nó có thể được truy nhập trong các hàm tự do, các phương thức bên trong các lớp khác… 
## Sự khác nhau giữa lớp và đối tượng
1.	Đối tượng là thể hiện của 1 lớp.	Lớp là một khuân mẫu hay thiết kế để tạo ra các đối tượng.
2.	Đối tượng là 1 thực thể trong thế giới thực như Bút chì, Xe đạp, …	Lớp là một nhóm các đối tượng tương tự nhau.
3.	Đối tượng là 1 thực thể vật lý	Lớp là 1 thực thể logic
4.	Đối tượng được tạo ra chủ yếu từ từ khóa new.
Ví dụ: Student s1=new Student();	Lớp được khai báo bằng việc sử dụng từ khóa class.
Ví dụ: class Student{}
5.	Đối tượng có thể được tạo nhiều lần.	Lớp được khai báo 1 lần duy nhất.
6.	Đối tượng được cấp bộ nhớ khi nó được tạo ra.	Lớp không được cấp bộ nhớ khi nó được tạo ra.
7.	Chỉ có một  cách để tạo ra đối tượng trong C++ như từ khóa new. Chỉ có một cách để định nghĩa lớp trong C++ sử dụng từ khoá class.
## Con trỏ `this`
Mỗi đối tượng trong C++ có quyền truy cập vào địa chỉ riêng của nó thông qua con trỏ `this`.

Con trỏ `this` là một tham số ngầm định cho tất cả các hàm thành viên. Vì vậy, bên trong một hàm thành viên, điều này có thể được sử dụng để chỉ đối tượng gọi.

Hàm friend không có con trỏ `this`, bởi vì friend không phải là thành viên của một lớp.`Chỉ những hàm thành viên của lớp mới có con trỏ this`.

Các cánh sử dụng chính:
- Có thể được sử dụng để truyền đối tượng hiện tại làm tham số cho phương thức khác.
- Có thể được sử dụng để tham chiếu thuộc tính của lớp hiện tại.
- Có thể được sử dụng để khai báo các chỉ mục.
```cpp
#include<iostream> 
#include<string> 
using namespace std;
/* Định nghĩa lớp */
class Car {
private:
	int  speed;               // Tốc độ  
	string  mark;           // Nhãn hiệu
	float price;               // Giá xe 						
							   // Khởi tạo với các giá trị ngầm định cho các tham số 
public:
	Car(int speed, string mark , float price);
	void show(); // Giới thiệu xe 
};

/* Khai báo phương thức bên ngoài lớp */
Car::Car(int speed, string mark, float price) {
	this->speed = speed;
	this->mark = mark;
	this->price = price;
}

void Car::show() { // Phương thức giới thiệu xe 
	cout << "This is a " << mark << " having a speed of "
		<< speed << "km / h and its price is $" << price << endl;
	return;
}

// Hàm main, chương trình chính 
int  main() {

	Car myCar1(120, "Toyota", 3000); // Khởi tạo đối tượng 1
	Car myCar2(150, "Mercedes", 5000);// Khởi tạo đối tượng 2											
									  
	// Giới thiệu xe thứ nhất 
	cout << "Xe thu nhat: " << endl;
	myCar1.show();
	// Giới thiệu xe thứ hai 
	cout << "Xe thu hai: " << endl;
	myCar2.show();
	return 0;
}
```

## FRIEND trong OOP
### Hàm bạn
Nếu một hàm được định nghĩa là hàm bạn thì dữ liệu vùng protected và private của một lớp có thể truy cập bằng hàm này. (Như kiểu là bạn thì biết bí mật của nhau vậy :) ).

Có hai kiểu:
- Hàm tự do làm bạn của một lớp.
- Hàm là phương thức của một lớp là bạn của lớp khác.
#### Hàm tự do làm bạn của một lớp
```cpp
class <class_name>{ 
       // Khai báo các thành phần lớp như thông thường 
       // Khai báo hàm bạn 
       friend <type_return> <name_func>([<Parameters>]);
 }; 
     
<type_return> <name_friend_func>([<Parameters>]){ 
      // Có thể truy nhập trực tiếp các thành phần private  
      // của lớp đã khai báo 
}
```
#### Phương thức lớp này là bạn lớp khác
```cpp
class B{ 
   // Khai báo các thành phần khác của lớp B 
   void f(A); 
};
```
```cpp
class A{ 
   // Khai báo các thành phần khác của lớp A     
  friend void B::f(A); 
};
```
### Lớp bạn
Lớp friend được xây dựng để khắc phục điểm yếu lớp dẫn xuất không thể truy cập tới các biến private của lớp cơ sở.

- Friend của một class có thể là thành viên của 1 class khác
- Friend của 1 class có thể là thành viên của class khác hoặc tất cả các class trong cùng 1 chương trình. Như là 1 GLOBAL FRIEND
- Friend có thể access private hoặc protected của class được khai báo là Friend.
- Friends không phải là một thành viên vì vậy không có con trỏ "this"
- Friend có thể khai báo ở bất cứ đâu ( public, protected or private section) trong một class.

Cú pháp:
```cpp
class A{ 
     ...// Khai báo các thành phần của lớp A 
     // Khai báo lớp bạn B     
      friend class B; 
};
```
Lúc này class B là bạn của class A, tức là B có thể truy cập thông tin mật từ A. Nhưng có đều B bạn A thì chưa chắc A bạn B vì vậy A không thể biết bí mật của B.
