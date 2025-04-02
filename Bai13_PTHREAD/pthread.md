# PTHREAD
## 1.Pthread là gì?
- Pthread là một thư viện implement chuẩn POSIX đặc tả việc tạo nhiều luồng tính toán song song.
- Theo chức năng mà các API của pthread được chia thành 4 loại:
  + Thread management: là các hàm sử dụng để tạo, hủy, detached, join thread cũng như set/get các thuộc tính của thread.
  + Mutexes: là các hàm sử dụng để tạo, hủy, unlocking, locking mutex cũng như set/get các thuộc tình của mutex.
  + Condition variables: là các hàm để tạo, hủy, đợi hoặc phát tín hiệu dựa trên giá trị của một biến cụ thể.
  + Synchronization: là các hàm dùng để quản lý việc read/write lock và barriers.
Giải thích một số thuật ngữ :
### Thread:
- là một đơn vị thực thi nhỏ nhất có thể quản lý bởi hệ điều hành.
- Process là một nhóm các thread có liên kết, thực thi cùng nhau trên cùng một môi trường và cũng chia sẽ tài nguyên trên đó với nhau (memory space).
- Mỗi một thead chỉ có thể tồn tại trong một process.
- Thread dùng thông qua việc `parallelism-song song`, thực tế chỉ có một thread được thực thi tại một thời điểm bởi CPU, nhưng CPU có thể chuyển đổi nhanh chóng giữa các thread để tạo hiệu ứng giống như các thread đang được thực thi song song với nhau.

![image](https://github.com/user-attachments/assets/269ba77c-d649-48b0-b0f0-51acef80cac6)

### Mutex
- Mutial Exclusion là loại trừ lẫn nhau, đảm bảo một task duy nhất được quyền truy cập vào tài nguyên tại một thời điểm. Bản chất là Flag hay một Key .
![image](https://github.com/user-attachments/assets/ef6ccf61-43bb-44dd-a53f-4fb660740049)
## 2.Thao tác
### 2.1 Tạo mới một thread.
Cú pháp hàm:
```pthread_create(pthread_t *th, const pthread_attr_t *attr, void *(* func)(void *), void *arg)```
+ Tham số 1: một con trỏ kiểu pthread_t, đại diện cho một thread mới được tạo ra.
+ Tham số 2: một thuộc tính của thread, đặt là NULL nếu giữ thuộc tính mặc định.
+ Tham số 3: địa chỉ hàm muốn thực thi.
+ Tham số 4: một con trỏ đối số cho hàm thuộc kiểu void.
### 2.2 Dừng một thread
### 2.2.1 Tự dừng
- Tự dừng tực là khi thread đó thực hiện xong xử lý của nó, nó kết thúc.
- Cú pháp: ```pthread_exit(NULL)```
- Nếu được gọi ở thread ngoài hàm main() thì sẽ dừng thread đang chạy.
- Nếu được gọi ở trong hàm main() thì sẽ đợi khi các thread con được thoát rồi nó mới thoát.
### 2.2.2 Dừng bắt buộc
- Cú pháp: ```pthread_cancel()```
- Thread sẽ bị hủy bỏ ngay tức khắc.

# END
Tham khảo chương trình sử dụng Pthread file `main.c`
