# BINARY SEARCH
# 1. Linear Seach?
- Muốn tìm hiểu về binary search thì trước tiên là cân biết về Linear seach. Vậy Linear search là gì?
- Linear search - Tìm kiếm tuyến tính là thuật toán đơn giản để tìm kiếm một phần tử trong mảng.
- Đơn giản là duyệt tuần tự cách phần tử trong mảng rồi so sánh với giá trị cần tìm kiếm.
- Khi tìm kiếm thì sẽ có 2 trường hợp xảy ra là tồn tại giá trị tìm kiếm và không tồn tại giá trị tìm kiếm.
  ![image](https://github.com/user-attachments/assets/c3decd30-4c5e-4314-84c7-93d66b056d28)

- Đoạn code sau đây tìm kiếm một giá trị trong mảng và in ra có xuất hiện hoặc không.
```cpp
int arr[5] = {1,2,3,4,5};
int x = 3;
for(int i = 0; i < 5; i++){
  if(arr[i] == x) {printf("Found!");return;}
}
printf("Not Found!");
```
# 2. Binary Search?
- Binary Search là thuật toán tìm kiếm nhị phân hoạt động bằng cách chia đôi mảng để tìm kiếm.
- Điều kiện để thực hiện Binary Search đó là mảng đã được sắp xếp tăng dần hoặc giảm dần.
- Để đi vào `Binary Search` ta cần tìm hiểu qua một số thuật toán sắp xếp trước.
## 2.1 Bubble Sort
- Bubble Sort - sắp xếp nổi bọt, là kiểu sắp xếp dựa trên việc hoán đổi hai phần tử liền kề để đưa phần tử lớn hơn về cuối dãy hoặc nhỏ hơn về đầu dãy.
```cpp
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
```
* Giải thích:
  - Duyệt phần tử đầu tiên đến phần tử kế cuối
  - Với mỗi phần tử đang duyệt ta duyệt tiếp từ đầu đến phần tử trước đó của phần tử đang duyệt.
  - Do sánh 2 phần tử đang duyệt lần 2 đấy đưa phần tử lớn hơn về sau. Kết quả mỗi lần duyệt lần 2 này là đưa phần tử lớn nhất trong khoảng đó về cuối cùng.
- Việc sắp xếp như này sẽ có độ phức tạp O(n^2).

![image](https://github.com/user-attachments/assets/9f2fdf7f-8e7b-4994-b997-a4be3cbcd583)

![image](https://github.com/user-attachments/assets/e0a88e0b-62eb-42ca-a1f9-b785d1b9aed4)

![image](https://github.com/user-attachments/assets/2caa82b8-2562-45bf-a8ba-fac80a9096cf)
## 2.2 Binary search.
- Sau khi mảng đã được sắp xếp ta sử dụng 'binary search' để tìm kiếm.
- Bản chất của binary search là phân đôi mảng ra để tìm, khi phần đôi mảng thì ta so sánh phần tử cần tìm với phần tử chính giữa nếu lớn hơn thì nằm bên phải (với mảng tăng dần) bé hơn thì nằm bên trái và nếu bằng thì ta tìm được phần tử đó.
* Thuật toán như sau:
```cpp
int binary_search(int arr[], int n, int x){
  int left = 0, right = n-1;
  while(left >= right){
    int mid = (left + right)/2;
    if(arr[mid] == x) return 1;
    else if(arr[mid] > x) right = mid - 1; //tim ben trai
    else left = mid + 1; // tim ben phai
  }
  return -1;
}
```
![image](https://github.com/user-attachments/assets/42789fb7-7da0-4024-8a84-6bef255e1b73)



