# TRỪU TƯỢNG - ABSTRACTION
Các lớp trừu tượng là cách để đạt được sự trừu tượng trong C ++. Sự trừu tượng trong C ++ là quá trình ẩn các chi tiết bên trong và chỉ hiển thị chức năng. Sự trừu tượng có thể đạt được bằng hai cách:
- Lớp trừu tượng
- Giao diện

Trong lớp C++ để tạo ra trừu tượng bằng cách khai báo ít nhất một phương thức thuần ảo. Một phương thức thuần ảo được xác định bằng cách đặt "= 0" trong khai báo của nó. Được dùng cung cấp bởi các lớp dẫn xuất.

Ví dụ về lớp trừu tượng trong C ++ có một phương thức abstract (). Nó được cung cấp bởi các lớp dẫn xuất: Rectangle và Circle. Cả hai lớp đều có cách triển khai khác nhau.

```cpp
#include <iostream>  
using namespace std;
class Shape {
public:
	virtual void draw() = 0;
};

class Rectangle : Shape {
public:
	void draw()
	{
		cout <<"drawing rectangle..." <<endl;
	}
};

class Circle : Shape {
public:
	void draw()
	{
		cout << "drawing circle..." <<endl;
	}
};


int main() {
	Rectangle rec;
	Circle cir;
	rec.draw();
	cir.draw();
	system("pause");
	return 0;
}
```

## Trừa tượng dữ liệu
Trong chương trình C ++ nếu chúng ta thực hiện lớp với các thành viên private và public. Đó là một ví dụ về trừu tượng dữ liệu.
```cpp
#include <iostream>  
using namespace std;
class Sum
{
private: int x, y, z;
public:
	void add()
	{
		cout << "Enter two numbers: ";
		cin >> x >> y;
		z = x + y;
		cout << "Sum of two number is: " << z << endl;
	}
};
int main()
{
	Sum sm;
	sm.add();
	system("pause");
	return 0;
}
```
