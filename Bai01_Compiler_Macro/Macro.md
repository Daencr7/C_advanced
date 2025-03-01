# MARCRO
## 1. Macro là gì
- Macro là một đoạn mã trong chương trình được thay thể bằng giá trị của macro. Dễ hiểu hơn nó thứ định nghĩa lại thứ phức tạp, dài dòng thành đơn giản hơn trong chương trình.
## 2. Một số dạng marcro được sử dụng chính.
### 2.1 INCLUDE
-  Include là một chỉ thị tiền xử lý, là một dạng file chuẩn hoặc do người dùng định nghĩa đưa vào chương trình.
-  Include được bộ tiền xử lý đọc và hướng dẫn nó chèn nội dung của tệp tiêu đề do người dùng định nghĩa hoặc hệ thống vào chương trình, quá trình này là _File Inclusion_
-  Có 2 loại: Tệp có sẵn và tệp do người dùng định nghĩa.
  #### Tệp Header có sẵn:
  Có sẵn đi kèm với trình biên dịch năm trong thư mục tệp hệ thống chuẩn.
  ```cpp
  #include <name_file>
  ```
  *Lưu ý sử dụng ngoặc nhọn ` <> `
  - Ví dụ
  - ```cpp
    #include <stdio.h>
    #include <math.h>
    
    int main()
    {
        double num = 14.0;
        double Res = sqrt(num);
        printf("Square root of %.2f is %.2f\n", num, Res);
        return 0;
    }
    ```
    * Đoạn code trên dùng chỉ thị tiền xử lý include 2 file thư viện `stdio.h` và `math.h` thuộc loại có sẵn trong file hệ thống chuẩn. Thực hiện tính toán sử dụng các hàm như `sqrt()`, `printf`.
    * Nếu không có `#include<>` thì có bị gì không ? Sẽ xuất hiện lỗi chưa khai báo các hàm sử dụng trong chương trình.
      =>![image](https://github.com/user-attachments/assets/c2f157d6-b485-4661-837f-4add49b0e43f)
     
### 2.2 DEFINE
### 2.3 IF-ELSE
### 2.4 DEFINED-IFDEF-IFNDEFINE-UNDEF
