# KẾ THỪA - INHERITANCE
## Giới thiệuthiệu
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
