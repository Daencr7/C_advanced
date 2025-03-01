# MARCRO
## 1. Macro là gì
- Macro là một đoạn mã trong chương trình được thay thể bằng giá trị của macro. Dễ hiểu hơn nó thứ định nghĩa lại thứ phức tạp, dài dòng thành đơn giản hơn trong chương trình.
## 2. Một số dạng marcro được sử dụng chính.
### 2.1 INCLUDE - CHỈ THỊ BAO HÀM TỆP
-  Include là một chỉ thị tiền xử lý, là một dạng file chuẩn hoặc do người dùng định nghĩa đưa vào chương trình.
-  Include được bộ tiền xử lý đọc và hướng dẫn nó chèn nội dung của tệp tiêu đề do người dùng định nghĩa hoặc hệ thống vào chương trình, quá trình này là _File Inclusion_
-  Có 2 loại: Tệp có sẵn và tệp do người dùng định nghĩa.
  #### Tệp Header có sẵn:
  Có sẵn đi kèm với trình biên dịch năm trong thư mục tệp hệ thống chuẩn.
  * Cú pháp
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
  #### Tệp do người dùng định nghĩa:
  Tệp này cũng giống như tệp trên chỉ khác mỗi do người dùng viết ra để tái sử dụng.
  * Cú pháp
  ```cpp
  #include "name_file"
  ```
  *Lưu ý sử dụng dấu nháy kép ` " " `
  - Ví dụ
  - ```cpp
    `File process.h`
    void add(int a, int b){
        printf("Added value=%d\n", a + b);
    }
    void multiply(int a, int b){
        printf("Multiplied value=%d\n", a * b);
    }
    ```
    ```cpp
    `File chính có chứa process.h`
    #include <stdio.h>
    #include "process.h"
    int main(){
        add(10, 20);
        multiply(10, 20);
        printf("Process completed");
        return 0;
    }
    ```
    * Đoạn code này gọi lại các hàm đã được viết trên `process.h`. File `process.h` đã viết hàm `add(), multiply` in ra tổng và tích 2 tham số a, b. File main chỉ thực hiện gọi lại 2 hàm này và truyền đối số 10 và 20 vào sau đó in ra "Process completed".
    * Vẫn câu hỏi củ không include được không ? Nếu không include thì không sử dụng được các hàm đó vì vẫn chưa được khai báo, nếu vẫn muốn sử dụng thì buộc phải định nghĩa lại hàm ở file main mà không cần include"".
### 2.2 DEFINE & UNDEF - CHỈ THỊ ĐỊNH NGHĨA CHO TÊN
#### DEFINE
-    Dùng để thay thế một chuổi mã nguồn bằng một chuỗi khác trước khi chương trình biên dịch.
-    Tránh lặp lại, dễ bảo trì.
-  * Cú pháp
    ```cpp
    #define identifier replacement-list
    ```
    * Thay thế tên cho một chuỗi dài (có thể sử dụng \ khi phải qua dòng mới)
    ```cpp
    #define NHD "Nguyen Huu Dang"
    ```
    Khi muốn thực hiện in Nguyen Huu Dang thì chỉ cần in ra NHD là được.
   * Định nghĩa cho hàm, hàm có tham số,...
     ```cpp
      #define NHD printf("Nguyen Huu Dang")
     ```
     Khi sử dụng như này thì ta chỉ cần gọi ra NHD thì chương trình sẽ tự động in ra `Nguyen Huu Dang` ra màn hình mà không cần ta phải mất thêm một bước sử dụng hàm `printf("%s",NHD)`.
     Khi đoạn chương trình gồm nhiều câu lệnh thì ta chỉ cần them cặp ngoặc nhọn `{ }` sau macro là được.
     ```cpp
      #define NHD {printf("Nguyen Huu Dang\n");printf("Hello World!");}
     ```
     Khi cần sử dụng tham số:
     ```cpp
     #define NHD(x) (x+1) 
     ```
     Lúc này ta chỉ cần truyền đối số vào `NHD()` thì sẽ có kết quả `(x+1)`. Một lưu lý ở đây là vì sao phải sử dụng dấu ngoặc `()` cho `x+1` . Tham khảo ví dụ tiếp sau đây
     ```cpp
     #define NHD(x) x+1
     ```
     => `NHD(3)*NHD(3)` : ở trường hợp này kết quả mong muốn là `4*4 = 16` nhưng chương trình nó sẽ ra như này
     khi không sử dụng dấu ngoặc ` 3 + 1 * 3 + 1 ` theo quy tắc ưu tiên của toán tử thì phép ` * ` thực hiện trước rồi mới đến phép ` + ` vì vậy kết quả sẽ bằng `7` trái với mong muốn của chúng ra.
### 2.3 IF-ELif-ELSE-IFDEF-IFNDEF - CHỈ THỊ BIÊN DỊCH CÓ ĐIỀU KIỆN

