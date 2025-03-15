# QUEUE
Từ stack có một người anh em khá thân thiết đó là `queue`
Vậy queue là ?
## Queue
- Queue là một kiểu cấu trúc dữ liệu y chang Stack vậy nhưng nguyên lý của nó là FIFO - First In First Out. Hoạt động như việc đinh thanh toán hàng hoá ở siêu thị vậy, xếp một hàng dài rồi người nào đến trước thì được tính tiền trước và đi về trước.
![image](https://github.com/user-attachments/assets/ae4ade5b-a28d-4b9d-b17e-bb43cac17606)

Tiếp tục với hiệu suất từng phương thức nha:
![image](https://github.com/user-attachments/assets/0b5d9f2b-c2b1-4485-8909-85a83a71dd65)
Về bản chất thì Queue cũng là một cái mảng nhưng kết hợp với FIFO.
- Các phương thức Queue hầu hết ổn định với O(1).
- Cùng so sánh tương quan hiệu suất Queue và Stack
![image](https://github.com/user-attachments/assets/95d663dd-65f8-49c4-b2ae-1fdfc1ebd7c5)
Giống nhau hầu hết đúng không. Ở thương thức `swap` thì độ phức tạp O(n) vì nó cần duyệt n phần tử.
Ở C thì chúng ta có thể tự config bất kì phương thức nào mà ta muốn để tăng tính linh hoạt hơn trong việc sử dụng stack và queue.
## Sử dụng queue
- Việc cấu hình sử dụng queue cũng như stack vậy nhưng đặc biệt hơn queue nó có ba loại biến thể là _Linear Queue_ , _Circular Queue_ và _Priority Queue_
![image](https://github.com/user-attachments/assets/4537d206-e899-4899-89ee-0b169ae292eb)
Ở Linear Queue có một nhược điểm khi tự config đó là khi rear đạt tới giới hạn
thì queue lúc này nó đầy không thể thêm phần tử mới ngay cả khi phía trước còn khoảng trống từ các phần tử đã được xóa tức là một cái queue vừa có cả ô rỗng và ô chứa dữ liệu thì lúc này không thể thêm vào queue do cách config tăng dần đến max và muốn thêm thì phải xóa hết rồi thêm lại.
Với điểm khá khó này đã có Circular Queue khắc phục. Cir Queue hoạt động như vòng tròn vô cực vậy đầy thì dừng rỗng thì có thể thêm vào được đúng nghĩa như cái bàn tròn.
![image](https://github.com/user-attachments/assets/950dd0aa-50c3-4220-b396-6c75fcb295f3)
Cùng tham khảo mã nguồn ở file.c nha.
Loại cuối cùng là _Priority Queue_ , queue như bao loại khác nhưng nó là ưu tiên. Tức là các phần tử trong queue có thể được sắp xếp lại theo độ ưu tiên mà người dùng muốn cài đặc, có thể là lớn hơn, hoặc bé hơn, nhau có nhiều chữ số hơn,...
