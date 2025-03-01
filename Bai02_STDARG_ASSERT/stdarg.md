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
  Mỗi lần thay đổi `8 bit` tương đương với `1 byte` bởi vì các tham số được truyền vào trong hàm thì nó được coi là chuổi kí tự được truyền còn dưới dạng một con trỏ `*char` vì vậy việc thay đổi tương ứng với size của char là 1 byte.

* Trường hợp mà tổng tham số ít hơn các tham số truyền vào thì sao?
  Với trường hợp này stdarg nó cho phép input số lượng tham số tùy ý thì việc chạy như này thì hoàn toàn không lỗi. Nó chỉ tính tổng phụ thuộc vào `num_args` để tính `num_args` số ban đầu trong dãy số truyền vào.
- Vậy có cách nào truyền số lượng tham số bất kỳ và không bị bó buộc vào biến đếm số lượng tham số không ?
  => Có cách khác đó là sử dụng kết hợp `stdarg` với `variadic macro`.
  Ví dụ
  ```cpp
  #include <stdio.h>
  #include <stdarg.h>
  #define tong(...) sum(__VA_ARGS__, 0) // 0 là giá trị cuối cùng, dùng để kết thúc công việc tính tổng.
  int sum(int num_args, ...){

    va_list ap;
    va_start(ap, num_args);
    
    int val = num_args;
    int value;
    while((value=va_arg(ap, int)) != 0){
        val += value;
    }
    
    va_end(ap);
    return val;
  }
  int main(){   
      printf("%d",tong(5,1,2,3,4,5,5,5,5,5,5,5));
      return 0;
  }
  ```
  Trong ví dụ này sẽ thêm sau một chuổi bằng giá trị 0, thiết lập ban đầu giá trị `val` bằng giá trị đếm, bản chất sẽ duyệt cho đến khi gặp giá trị 0 thì nó sẽ dừng lại và trả về giá trị tổng.
  * Câu hỏi đặt ra vậy trong dãy số có số 0 thì sao ? Trong trường hợp này khi duyệt trong dãy có số 0 thì sẽ bị dừng lại tại số 0 và trả về giá trị. Để khắc phục điều này thì chỉ cần thay đổi phần tử được thêm vào sau cùng là thứ không thể trùng khi nhập dãy vào là được. Chẵn hạn có thể thay đổi thành kí tự `0`.




  
