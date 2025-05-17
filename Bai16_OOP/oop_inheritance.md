# KẾ THỪA - INHERITANCE
## Giới thiệu
Kế thùa là việc dùng lại mã trên lớp này từ lớp khác.

Việc thừa kế cho phép các lớp thừa kế (gọi là lớp dẫn xuất) sử dụng lại các phương thức đã được định nghĩa trong các lớp gốc (gọi là lớp cơ sở). 

Cú pháp:
```cpp
class <Tên lớp dẫn xuất>: <Từ khóa dẫn xuất> <Tên lớp cơ sở>{ 
  // Khai báo các thành phần lớp 
}; 
```
Trong đó:
- Tên lớp dẫn xuất: là tên lớp được cho kế thừa từ lớp khác. Tên lớp này tuân thủ theo quy tắc đặt tên biến trong C++. 
- Tên lớp cở sở: là tên lớp đã được định nghĩa trước đó để cho lớp khác kế thừa. Tên lớp này cũng tuân thủ theo quy tắc đặt tên biến của C++. 
- Từ khóa dẫn xuất: là từ khóa quy định tính chất của sự kế thừa. Có ba từ khóa dẫn xuất là private, protected và public. Mục tiếp theo sẽ trình bày ý nghĩa của các từ khóa dẫn xuất này. 
Ví dụ:
Khai báo một lớp Car kế thừa từ lớp Vehicle.
```cpp
class Car: public Vehicle{

}
```
## Tính chất dẫn xuất
Sự kế thừa cho phép trong lớp dẫn xuất có thể sử dụng lại một số mã nguồn của các phương thức và thuộc tính đã được định nghĩa trong lớp cơ sở. Nghĩa là lớp dẫn xuất có thể truy nhập trực tiếp đến một số thành phần của lớp cơ sở. Tuy nhiên, phạm vi truy nhập từ lớp dẫn xuất đến lớp cơ sở không phải bao giờ cũng giống nhau: chúng được quy định bởi các từ khóa dẫn xuất private, protected và public. 

`Dẫn xuất private`
Dẫn xuất private quy định phạm vi truy nhập như sau: 

- Các thành phần private của lớp cơ sở thì không thể truy nhập được từ lớp dẫn xuất. 
- Các thành phần protected của lớp cơ sở trở thành các thành phần private của lớp dẫn xuất 
- Các thành phần public của lớp cơ sở cũng trở thành các thành phần private của lớp dẫn xuất. 
- Phạm vi truy nhập từ bên ngoài vào lớp dẫn xuất được tuân thủ như quy tắc phạm vi lớp thông thường. 

`Dẫn xuất protected`
Dẫn xuất protected quy định phạm vi truy nhập như sau: 

- Các thành phần private của lớp cơ sở thì không thể truy nhập được từ lớp dẫn xuất. 
- Các thành phần protected của lớp cơ sở trở thành các thành phần protected của lớp dẫn xuất 
- Các thành phần public của lớp cơ sở cũng trở thành các thành phần protected của lớp dẫn xuất. 
- Phạm vi truy nhập từ bên ngoài vào lớp dẫn xuất được tuân thủ như quy tắc phạm vi lớp thông thường. 

`Dẫn xuất public`
Dẫn xuất public quy định phạm vi truy nhập như sau: 

- Các thành phần private của lớp cơ sở thì không thể truy nhập được từ lớp dẫn xuất. 
- Các thành phần protected của lớp cơ sở trở thành các thành phần protected của lớp dẫn xuất. 
- Các thành phần public của lớp cơ sở vẫn là các thành phần public của lớp dẫn xuất. 
- Phạm vi truy nhập từ bên ngoài vào lớp dẫn xuất được tuân thủ như quy tắc phạm vi lớp thông thường.

Tổng hợp:

![image](https://github.com/user-attachments/assets/c75ef660-b541-4d53-8177-f9b3ac74858a)

## Phạm vi truy xuất trong kế thừa

![image](https://github.com/user-attachments/assets/60b5d270-cb82-4097-892d-0b61b56e7b9f)

# ĐA KẾ THỪA
Đa kế thừa tức là là một lớp có thể được dẫn xuất từ nhiều lớp cơ sở khác nhau, với những kiểu dẫn xuất khác nhau. 

Cú pháp:
```cpp
class <Tên lớp dẫn xuất>: <Từ khoá dẫn xuất> <Tên lớp cơ sở 1>, 
                   <Từ khoá dẫn xuất> <Tên lớp cơ sở 2>, 
                   … 
                   <Từ khoá dẫn xuất> <Tên lớp cơ sở n>{ 
         …  // Khai báo thêm các thành phần lớp dẫn xuất 
};
```
Ví dụ:
Khai báo lớp Bus (xe buýt) kế thừa từ hai lớp xe Car (ô tô) và PublicTransport (phương tiện giao thông công cộng) theo cùng một kiểu dẫn xuất là public. 
```cpp
class Bus: public Car, public PublicTransport{      …     // Khai báo các thành phần bổ sung 
}; 
```
# LỚP CƠ SỞ TRỪU TƯỢNG
Sự cho phép đa kế thừa trong C++ dẫn đến một số hậu quả xấu, đó là sự đụng độ giữa các thành phần của các lớp cơ sở, khi có ít nhất hai lớp cơ sở lại cùng được kế thừa từ một lớp cơ sở khác.

Ví dụ:

![image](https://github.com/user-attachments/assets/b6a89970-5f51-4cf4-b3b5-c55c1876004a)

Car kế thừa Engine, PublicTransport cũng kế thừa Engine, sau đó Bus kế thừa 2 lớp này.
Dẫn đến từ Bus sẽ lặp lại 2 enginre từ Car vs PublicTransport. Khai báo 2 lần, giải phóng 2 lần là sự rắc rối.

Để tránh các vấn đề này, C++ cung cấp một khái niệm là kế thừa từ lớp cơ sở trừu tượng. Khi đó, ta cho các lớp Car và PublicTransport kế thừa trừu tượng từ lớp Engine. Bằng cách này, các thành phần của lớp Engine chỉ xuất hiện trong lớp Bus đúng một lần. Lớp Engine được gọi là lớp cơ sở trừu tượng của các lớp Car và PublicTransport.

Cú pháp cơ sở trừu tượng:

```cpp
class <Tên lớp cơ sở>: <Từ khoá dẫn xuất> virtual <Tên lớp cơ sở>{ 
     …  // Khai báo các thành phần bổ sung 
};
```

Ví dụ:
```cpp
class Engine{ 
     …     // Các thành phần lớp Engine 
}; 
class Car: public virtual Engine{ 
         …  // Khai báo các thành phần bổ sung 
}; là khai báo lớp Car, kế thừa từ lớp cơ sở trừu tượng Engine, theo kiểu dẫn xuất public. 
```
```

Ví dụ đoạn code sử dụng cơ sở trừu tượng:

```cpp
#include<string> 
#include <iostream>
using namespace std;
/* Định nghĩa lớp Engine */
class Engine {
	int  power; 	 	 	// Công suất 
public:
	Engine() { power = 0; };  	// Khởi tạo không tham số  
	Engine(int power) {
		this->power = power;
	};
	void show(); 	 	 	// Giới thiệu  
	float getPower() {
		return power;
	};
};

// Giới thiệu 
void Engine::show() {
	cout << "This is an engine having a power of " << power << "KWH" << endl;

}

/* Định nghĩa lớp Car dẫn xuất từ lớp cơ sở trừu tượng Engine*/
class Car : public virtual Engine {
	int  speed;               // Tốc độ  
	string  mark;           // Nhãn hiệu
	float price;               // Giá xe 						
							   // Khởi tạo với các giá trị ngầm định cho các tham số 
public:
	Car();
	Car(int speed, string mark, float price);
	void show(); 	 	 	// Giới thiệu  
	float getSpeed() {
		return speed;
	};
	string getMark() {
		return mark;
	};
	float getPrice() {
		return price;
	};
};
/* Khai báo phương thức bên ngoài lớp */
Car::Car() {
	this->speed = 0;
	this->mark = "";
	this->price = 0;
}
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

/* Định nghĩa lớp PublicTransport dẫn xuất trừu tượng từ lớp Engine */
class PublicTransport : public virtual Engine {
	float ticket; 	 	 	// Giá vé phương tiện
public:
	PublicTransport(); 	 	// Khởi tạo không tham số 
	PublicTransport(int, float); // Khởi tạo đủ tham số
	void show(); 	 	 	// Giới thiệu 
	float getTicket() {
		return ticket;
	};
};

PublicTransport::PublicTransport() {  	// Khởi tạo không tham số  	
	this->ticket = 0;
}

// Khởi tạo đủ tham số 
PublicTransport::PublicTransport(int power, float ticket) : Engine(power) {
	this->ticket = ticket;
}

// Giới thiệu 
void PublicTransport::show() {
	cout << "This is a public transport havìn a ticket of $" << ticket << " and its power is " << getPower()
		<< "KWh" << endl;
}
/* Định nghĩa lớp Bus kế thừa từ lớp Car và PublicTransport */
class Bus : public Car, public PublicTransport { // Thứ tự khai báo  	 	
	int label;  	 	 	// Số hiệu tuyến xe  	
public:
	Bus(); 	 	 	 	// Khởi tạo không tham số  
	Bus(int, int, string, float, float, int);// Khởi tạo đủ tham số  	 	
	void show(); 	 	 	// Giới thiệu 
};

// Khởi tạo không tham số 
Bus::Bus() : Engine(), Car(), PublicTransport() {  	// Theo thứ tự dẫn xuất  	
	label = 0;
}

// Khởi tạo đủ tham số 
Bus::Bus(int power, int speed, string mark, float price, float ticket, int label) :
	Engine(power), Car(speed, mark, price), PublicTransport(power, ticket) {
	this->label = label;
}

// Giới thiệu 
void Bus::show() {
	cout << "This is a bus on the line " << label
		<< ", its speed is " << getSpeed()
		<< "km / h, power is" << Car::getPower()
		<< "KWh, mark is " << getMark() << ", price is $" << getPrice()
		<< " and ticket is " << getTicket() << endl;

}

// phương thức main 
int main() {
	Bus myBus(250, 100, "Mercedes", 3000, 1.5, 27);
	myBus.Car::Engine::show();  	// Hàm của lớp Engine 
	myBus.PublicTransport::Engine::show();// Hàm của lớp Engine 
	myBus.Car::show(); 	 	 	// Hàm của lớp Car 
	myBus.PublicTransport::show(); 	// Hàm của lớp PublicTransport 
	myBus.show(); 	 	 	 	// Hàm của lớp Bus 
	return 0;
}
```
