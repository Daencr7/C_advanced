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
* Cú pháp
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
####UNDEF
-  Dùng để hủy định nghĩa trước đó cho đến undef.
*  Cú pháp:
    ```cpp
    #undef identifier
    ```
  Ví dụ:
  ```cpp
  #define NHD "Nguyen Huu Dang"
  ...
  #undef NHD
  ```
  Sau khi `undef NHD` thì `NHD` từ này trở về sau không còn nữa.
  Nếu ta vẫn sử dụng NHD thì sẽ xảy ra lỗi sau:
  ![image](https://github.com/user-attachments/assets/a5151a42-36e4-41af-86bb-6b657c9124a6)

### 2.3 IF-ELif-ELSE-IFDEF-IFNDEF - CHỈ THỊ BIÊN DỊCH CÓ ĐIỀU KIỆN
#### IF-ELif-ELSE
- Chỉ thị có điều kiện như cấu trúc if else bình thường vậy nhưng ở đây là chỉ thị tiền xử lý.
* Cú pháp:
  ```cpp
  #if constant-expression_1
    // Đoạn chương trình 1
  #elif  constant-expression_2
    // Đoạn chương trình 2
  #else
    //Đoạn chương trình 3
  #endif
  ```
  ví dụ
  ```cpp
  #include <stdio.h>
  #define NHD 1

  int main(){   
    #if NHD == 1
      printf("DK1 True");    
    #elif  NHD == 2
      printf("DK2 True");
    #else
      printf("DK con lai True");
    #endif
      return 0;
  }
  ```
  - `if` áp dụng cho điều kiện đầu tiên đúng, `elif` thì điều kiện tiếp theo, `else` điều kiện còn lại khác 2 cái trên, `endif` thì kết thúc điều kiện.
#### IFDEF-IFNDEF
- Với IFDEF : nếu đã được định nghĩa thì ...
- Với IFNDEF : nếu chưa được định nghĩa thì ...
- Hai chỉ thị này được sử dụng trong việc định nghĩa lại các file header cụ thể là xử lý việc xung đột thư viện khi include nhiều thư viện một lúc.
* Ví dụ:
  ```cpp
  FILE A.h
  source A
  ```
  Ta cũng có 2 file cần include file `A.h` là `B`và `C`
  ```cpp
  FILE B.h
  #include "A.h"
  source B

  FILE C.h
  #include "A.h"
  source C
  ```
  ```cpp
  FILE main lại cần File B và C
  #include "B.h"
  #include "C.h"
  source main
  ```
  Khi phân tích ra file `main` trở thành
  ```cpp
  #include "A.h" // Của file B
  #include "A.h" // của file C
  source main
  ```
  Vậy file `main` đã phải include 2 lần File `A.h`
  Trong trường hợp này cần áp dụng IFDEF và IFNDEF, DEFINE để định nghĩa lại.
  ```cpp
  FILE A.h
  #ifndef __A_H__
  #define __A_H__
  Source code A
  #endif // __AH__
  ```
### 2.4 MỘT SỐ TOÁN TỬ VỚI MACRO
- Sử dụng `#`
```cpp
#include <stdio.h>
#define STRINGIZE(x) #x
#define DATA 40
int main() {
 // Sử dụng toán tử #
printf("The value is: %s\n",
STRINGIZE(DATA));
 return 0;
}

```
- Sử dụng khai báo các biến động
```cpp
#include <stdio.h>
#define DECLARE_VARIABLE(prefix, number) int prefix##number
int main() {
 // Sử dụng macro để khai báo các biến động
 DECLARE_VARIABLE(var, 1); // int var1;
 DECLARE_VARIABLE(var, 2); // int var2;
 // Gán giá trị cho các biến
 var1 = 10;
 var2 = 20;
 // In ra giá trị của các biến
 printf("var1: %d\n", var1);
 printf("var2: %d\n", var2);
 return 0;

```
- Định nghĩa các macro có thể xử lý một lượng biến đầu vào khác nhau với **variadic macro**
```cpp
#define MACRO_NAME(...) 
```
Ví dụ 
```cpp
#define eprintf(…) fprintf (stderr, __VA_ARGS__)
// Những đối số được truyền vào eprintf() thì nó sẽ được truyền vào __VA_ARGS__ .
eprintf ("%s:%d: ", input_file, lineno)
     // sẽ được thay thế thành
     fprintf (stderr, "%s:%d: ", input_file, lineno)
```
