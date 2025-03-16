# LINKED LIST
## Linked List gì?
- Là một cấu trúc dữ liệu tuyến tính - is a linear data structure, Linked List gồm 2 phần tử đó là một con trỏ và một data, thường được ví như các node vậy.
- ```
  A linked list is a sequence of nodes where each node contains two parts:
    Data: The value stored in the node.
    Pointer: A reference to the next node in the sequence.
  ```
- Không như mảng các dữ liệu lưu ở địa chỉ liên tiếp cách đều nhau(tùy vào size), linked list được lưu trữ vị trí ngẫu nhiên trong bộ nhớ - _random memory locations_.
- Để liên kết các node này ta thông qua con trỏ của nó trỏ đến địa chỉ của node khác vậy là xong.
![image](https://github.com/user-attachments/assets/90555a39-3c4e-48af-a7de-77b7b1634445)
Trong hình ảnh này khởi đầu bằng node head, node head trỏ đến các node khác cứ tiếp tục như vậy đến kết thúc là NULL. Đây chỉ là ví dụ cơ bản nhất về linked list vậy Linked List có những biến thể nào? Cùng đi vào phần tiếp theo nhé.
## Các loại Linked List
### 1. Singly Linked List - Danh sách liên kết đơn
- Linked List được cấp phát động nên chú ý được lưu ở bộ nhớ `heap` nhé.
- Đặc biệt Linked List không giống như mảng có thể truy cập bất kỳ phần tử nào thông qua chỉ, Linked List phải duyệt tuần tự từ đầu cho đến vị trí mà ra mong muốn rồi mới truy cập được.
* Cấu trúc đơn giản sau đây:
```cpp
struct node{
    int data; // có thể thay thành kiểu dữ liệu khác
    node *next;
};

typedef struct node node;

int main(){
    node *head = (node*)malloc(sizeof(node));
    head->data = 100;
    head->next = NULL;
    printf("Gia tri cua head : %d\n", head);
    printf("Du lieu node ma head quan ly : %d", head->data);
}
```
- Đầu tiên ra khai báo cấu trúc node chưa data vào con trỏ next. 
- Ở hàm `main` thì ta cấp phát động node `head`, cái này ở trạng thái rỗng.
- Sau đó set up dữ liệu vào địa chỉ cần trỏ đến của nó. Lưu ý `Node* head` là con trỏ nên head là địa chỉ của nó nha.
![image](https://github.com/user-attachments/assets/e14f61e8-5dc6-49a7-b77b-e96e22767008)
- Đây là độ phức tạp của các phương thức của nó vì linked list duyệt từ đầu đến cuối nên chèn hay xóa ở đầu thì chỉ O(1) còn thao tác ở các node n thì lại tốn O(n) nha.
- Vậy muốn cắt Linked List ở vị trí bất kỳ thì sao? Như ta thấy thì dấu hiệu cho thấy kết thúc của một Linkedlist thì nó trỏ vào NULL, muốn cắt thì chỉ cần duyệt đến vị trí đó và cho node đó trỏ vào NULL là xong.
- Việc duyệt tuần tự như này chỉ là một chiều không thể quay lại được các node phía trước. Để khác phục nhược điểm này DSLK đôi sẽ giúp được điều này.
### 2. Doubly Linked List - Danh sách liên kết đôi
    ```
    Data: The actual information stored in the node.
    Next: A pointer that links to the next node in the sequence.
    Previous: A pointer that links to the previous node in the sequence.
    ```
Loại này bao cần có thêm một con trỏ Previous nữa, trong khi Next trỏ vào node tiếp theo thì Previous trỏ vào node phía trước nó.
![image](https://github.com/user-attachments/assets/6a0aaabe-ac90-4643-baef-20487243f5ff)
Cấu trúc như này:
```cpp
struct Node {
  
  // Data field - can be of any type and count
  int data;
  
  // Pointer to the next node
  Node* next;
  
  // Pointer to the previous node
  Node* prev;
}
```
Đây là bảng độ phức tạp từng thao tác với DSLK đôi
![image](https://github.com/user-attachments/assets/94620842-09f8-414c-a984-947d2a15b90e)
### 3. Circular Linked List 
- Trong queue ta đã được biến đến với Circular Queue việc hoạt động như bàn tròn thì Cir Linkedlist cũng như vậy vậy để cấu hình được thì đơn giản node đầu chỉ vào node tiếp, node tiếp chỉ vào node tiếp nữa cho đến khi node cuối cùng thì ban đầu node cuối cùng chỉ vào `NULL` đúng không, nhưng lần này ta lại để node cuối cùng không chỉ vào NULL mà node cuối chỉ vào địa chỉ con node head - tức là node đầu tiên.
![image](https://github.com/user-attachments/assets/db364882-87b3-4817-8860-a4b2e7a1dab0)
