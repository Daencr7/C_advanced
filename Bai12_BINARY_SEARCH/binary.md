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
