# STRUCT 
## 1. Struct là gì?
- Structure trong C là một kiểu dữ liệu người dùng tự định nghĩa cho phép lưu trữ các loại phần tử khác nhau.
- Mỗi phần tử trong struct được gọi là một thành viên (member).
* Cú pháp:
```cpp
struct structure_name {
    data_type member1;
    data_type member2;
    ...
    data_type memeberN;
};
```
Ví dụ:
```cpp
struct employee {
    int id;
    char name[50];
    int ngaycong ;
};
- Trong ví dụ này định nghĩa một cấu trúc nhân viên gồm id, tên, ngày công.
```
- Khi đọc một số mã nguồn thì ta thấy rằng người ta dùng typedef kết hợp với một cấu trúc mà không biết nó để làm gì? Thì typedef là một keyword dùng để đặt tên hoặc định nghĩa lại tên của cấu trúc đó. Nó có một số cách dùng sau đây với_typedef_:
```cpp
typedef struct employee{
    int id;
    char name[50];
    int ngaycong ;
}Employee;

Hoặc có thể như này:

typedef struct{
    int id;
    char name[50];
    int ngaycong ;
}Employee;
```
## 2. Struct Alignment.
```cpp
typedef struct example_struct
{
  uint8_t  member1;
  uint32_t member2;
} ExampleStruct_t;

  -> printf("Size of example struct: %lu bytes\n", sizeof(ExampleStruct_t));
}
```
- Để bắt đầu ta tìm hiểu một chút về đoạn code này nhé. Đoạn code này khai báo kiểu nguyên 8bit cho member1, 32bit cho member2. Trước đoạn này mình vẫn cứ nghĩ là kích thước của struct chính là tổng các kích thước của các member trong struct. Thì kết quả của đoạn code theo tính toán thông thường là `8+32=40bit` chính là `5`bytes. Nhưng khi chạy chương trình thì nó lại là 8bytes ??? :)) tại sao lại vậy.
- Thì alignment trong tiếng anh nó là sự căn chỉnh, sắp xếp vậy struct alignment là cách sắp xếp và truy cập dữ liệu trong bộ nhớ.
- Mỗi kiểu dữ liệu của mỗi member thường được lưu ở vùng địa chỉ là bội số của kích cỡ dữ liệu đó. Ví dụ như 1byte thì lưu ở 0,1,2,3,4... 2bytes thì lưu 0,2,4,6...
![image](https://github.com/user-attachments/assets/62ebe902-148d-4c42-92cc-a3739a00d893)
Mục đích lưu như này để thực hiện các thao tác đọc ghi được đẩy nhanh tốc độ hơn.
Và cách lưu này cũng dẫn đến các ô trống được dư ra khi các kiểu dữ liệu lưu khác nhau.
những vùng nhớ trống này coi như được chèn vào vậy và nó được gọi là _padding_.

```
typedef struct example_struct
{
  uint8_t  member1;
  uint32_t member2;
} ExampleStruct_t;
```
Với ví dụ này ta giải thích như sau: member1 có kiểu dữ liệu 1byte sẽ được lưu ở vùng bội số 1,member1 được lưu trước và xác định ở dùng nhớ đầu tiên 0x00->0x01.Đến member2 thì có kiểu 4byte sẽ được lưu ở những vùng 0x00,0x04,0x08,0x12,... Vì 0x00 đã được lưu cho member1 nên member2 sẽ lưu ở vùng tiếp theo là 0x04->0x08. Vậy xảy ra một khoảng từ 0x01 đến 0x04 thì khoảng này sẽ được chèn vào các vùng nhớ trống vào(padding). Như vậy tổng kích thước của chúng ta hiện ta sẽ từ 0x00 đến 0x08: 8bytes.
## 3. Một số sự kết hợp struct.
- Struct có thể kết hợp được với cấu trúc khác hay không? Điều này hoàn toàn được.
- Struct được lồng nhau vào với một struct khác:
  * Ví dụ:
    ```cpp
    struct Date {
        int day;
        int month;
        int year;
    };
    struct Employee {
        int id;
        char name[20];
        struct Date birthday;
    } emp1;
    ```
Ví dụ này sử dụng việc lồng một struct Date vào struc Employee.
- Struct có thể làm tham số hay kiểu trả về không? Được
  Struct là một cấu trúc dữ liệu nên hoàn toàn đáp ứng đẩy đủ như kiểu dữ liệu.
  * Ví dụ:
  - Struct làm tham số:
    ```cpp
    #include <stdio.h>
    #include <string.h>
     
    struct Books {
       char  title[50];
       char  author[50];
       char  subject[100];
       int   book_id;
    };
    /* function declaration */
    void printBook( struct Books book );
    int main( ) {
       struct Books Book1;        /* Declare Book1 of type Book */
       struct Books Book2;        /* Declare Book2 of type Book */
     
       /* book 1 specification */
       strcpy( Book1.title, "C Programming");
       strcpy( Book1.author, "Nuha Ali"); 
       strcpy( Book1.subject, "C Programming Tutorial");
       Book1.book_id = 6495407;
       /* book 2 specification */
       strcpy( Book2.title, "Telecom Billing");
       strcpy( Book2.author, "Zara Ali");
       strcpy( Book2.subject, "Telecom Billing Tutorial");
       Book2.book_id = 6495700;
     
       /* print Book1 info */
       printBook( Book1 );
       /* Print Book2 info */
       printBook( Book2 );
       return 0;
    }
    void printBook( struct Books book ) {
       printf( "Book title : %s\n", book.title);
       printf( "Book author : %s\n", book.author);
       printf( "Book subject : %s\n", book.subject);
       printf( "Book book_id : %d\n", book.book_id);
    }
    ```
  Đoạn code này với hàm `printBook` đã sử dụng tham số là kiểu struct.
  Khi khai báo kiểu cấu trúc với con trỏ thì việc truy xuất member của struct là cần sử dụng toán tử `->`.
### 3. Trường bit - Bit Fields
- Trường bit cho phép đóng gói dữ liệu trong một cấu trúc, điều này dùng đặc biệt khi bộ nhớ hạn chế.
- Ví dụ:
```cpp
struct packed_struct {
   unsigned int f1:1;
   unsigned int f2:1;
   unsigned int f3:1;
   unsigned int f4:1;
   unsigned int type:4;
   unsigned int my_int:9;
} pack;
```
Ở đây, packed_struct chứa 6 member: Bốn cờ 1 bit f1, f2, f3, f4, một type 4 bit và một my_int 9 bit.
C tự động đóng gói các trường bit trên nén (compact) nhất có thể, đảm bảo độ dài tối đa của trường nhỏ hơn hoặc bằng độ dài từ số nguyên của máy tính (integer word length of the computer). Nếu không đúng như vậy, thì một số compiler có thể cho phép chồng lấn bộ nhớ (overlap memory) các trường, hoặc những compiler khác sẽ lưu trường tiếp theo ở word kế tiếp.




















