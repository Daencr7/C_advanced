# STDARG
## 1. STDARG là gì?
- Là một thư viện trong file hệ thống chuẩn.
- Tương tự như **variadic macro** thì thư viện **stdarg** cung cấp một phương thức làm việc với số lượng tham số đầu vào không cố định (nghĩa là có thể sử dụng nhiều ít tùy ý).
## 2. STDARG có gì?
- Có 4 thứ chính được nhắc đến ở đây trong thư viện stdarg:
    - va_list : **kiểu dữ liệu** phù hợp để lưu thông tin của 3 macro va_start(), va_arg() và va_end().
    - `void` va_start(`va_list` ap, last_arg) :**macro** bắt đầu một danh sách đối số biến đổi.
    - `type` va_arg(`va_list` ap, `type`) :**macro** truy cập một đối số trong danh sách với kiểu `type`.
    - `void` va_end(`va_list` ap) :**macro** kết thúc việc sử dụng danh sách đối số biến đổi.
## 2.1 Macro va_start(), Macro va_arg(), Macro va_end()
-  Cú pháp:
  *Macro va_start()
  ```cpp
  void va_start(va_list ap, last_arg);
  ```
  `va_list ap` Kiểu dữ liệu được khai báo trước đó.
  `last_arg` Tham số cố định được biết cuối cùng, tham số này trùng với tổng tham số được truyền vào trong hàm.
  *Macro va_arg()
  ```cpp
  type va_arg(va_list ap, type)
  ```
  `ap` Đối tượng của kiểu va_list với thông tin về các tham số bổ sung và trạng thái thu nhận. Đối tượng này nên được khởi tạo bởi một lời gọi ban đầu tới va_start trước khi lời gọi đầu tiên tới va_arg.
  `type` Tên kiểu. Tên kiểu này được sử dụng như là kiểu của biểu thức, mà macro này mở rộng tới.
  *Macro va_end()
  ```cpp
  void va_end(va_list ap)
  ```
  `ap` Đối tượng va_list được khởi tạo trước đó bởi va_start trong cùng hàm.
- Phân tích hoạt động bằng debug:
  Cho dòng code sau tiến hành debug:
  ```cpp
  #include <stdio.h>
  #include <stdarg.h>
  int sum(int num_args, ...){
     int val = 0;
     va_list ap;
     va_start(ap, num_args);
     for(int i = 0; i < num_args; i++){
        val += va_arg(ap, int);
     }
     va_end(ap);
     return val;
  }
  int main(){   
      printf("%d",sum(5,1,2,3,4,5));
      return 0;
  }
  ```
Đặt breakpoint vào dòng 46 và step into hàm sum ta thấy:
- Dòng 35: Lúc này biến val có giá trị rác, ap ở trạng thái lưu địa chỉ offset ban đầu.
  ![image](https://github.com/user-attachments/assets/3a307001-afed-4bb1-88ef-147a3650e93d)
- Dòng 38: Step over đến dòng 38 lúc này val đang có giá trị 0 vì đã được khai báo
- Dòng 39: `ap` đã được thay đổi địa chỉ.
- Dòng 40: step lại 39 thì được địa chỉ `ap` thay đổi liên tục như sau:
  ![image](https://github.com/user-attachments/assets/c5eb0687-2fcb-403b-86ea-32f3a3e06d2c)
  ![image](https://github.com/user-attachments/assets/3cc53071-f821-4918-880e-46e3f68efffc)
  ![image](https://github.com/user-attachments/assets/23eae89c-e97b-4772-9ce6-422388b231b9)
  ![image](https://github.com/user-attachments/assets/2038fa8d-d043-4106-9daf-afbe8d92e9ec)
  ![image](https://github.com/user-attachments/assets/866ef65d-5850-4aef-97b9-72dee66e88df)
  Việc `ap` thay đổi địa chỉ liên tục 5 lần đó là do số lần lặp cho đối số truyền vào là 5. Và cuối cùng kết quả trả về là `15`.
  



