# GOTO
## 1. Goto là gì?
-  Goto là một từ khóa trong ngôn ngữ lập trình C/C++, cho phép chương trình nhảy 
đến một nhãn (label) đã được đặt trước đó trong cùng một hàm.
- Goto hoạt động tương tự như trong các mã assembly.
  
- Flowchart:
![image](https://github.com/user-attachments/assets/eb22244a-1e29-48a7-9abb-47f2c5de3614)
- Ví dụ:
```cpp
#include <stdio.h>

int main() {
    int n = 0;  

    // If the number is zero, jump to
      // jump_here label
    if (n == 0)
        goto jump_here;

    // This will be skipped
    printf("You entered: %d\n", n);

jump_here:
    printf("Exiting the program.\n");
    return 0;
}
```
Trong đoạn code, khai báo n = 0 ban đầu khi đến lệnh if kiếm tra n có bằng không hay không thì goto `jump_here` tực là ct sẽ nhảy đến nhãn `jump_here` và sẽ thực hiện các câu lệnh sau nhãn đó là `printf("Exiting the program.\n");`
## 2. Goto ứng dụng vào gì?
- Goto dùng trong thiết lập tắt mở của các đoạn led.
## 3. Hạn chế goto?
- Mặc dù nó cung cấp khả 
năng kiểm soát flow của chương trình, nhưng việc sử dụng goto thường được xem là 
không tốt vì nó có thể làm cho mã nguồn trở nên khó đọc và khó bảo trì.
- Việc sử dụng goto cũng bị hạn chế phạm vi cục bộ tức là goto chỉ nhảy đến các label trong phạm vi một hàm thôi. Để khắc phục hạn chế này thì hãy tiến đến phần `setjmp.h` ở file sau nhé!
