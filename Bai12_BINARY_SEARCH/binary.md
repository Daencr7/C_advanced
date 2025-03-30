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

## 2.3 Binary Search Tree
- Cấu trúc dữ liệu phân cấp (Tree) là một cấu trúc dữ liệu phi tuyến tính trong đó các phần tử là node được tổ chức theo một thứ bậc phân cấp. Cây là một _cấu trúc dữ liệu_ biểu diễn các quan hệ phân cấp, tìm kiếm, sắp xếp là lưu trữ.
![image](https://github.com/user-attachments/assets/a51b1c79-7543-4ed3-9d67-bfaa21f7421c)
- BST là một cấu trúc dữ liệu dạng cây trong đó:
  - Mỗi nút có tối đa 2 nút con.
  - Nút con bên trái có giá trị nhỏ hơn nút gốc, nút con bên phải có giá trị lớn hơn nút gốc.
Dưới đây là chương trình xây dựng một cây nhị phân.
```cpp
/***************************************************************************
 * @file    Build_Tree.c
 * @brief   Chuyển đổi danh sách liên kết thành cây nhị phân.
 * @details Chương trình xây dựng danh sách liên kết đơn, sau đó chuyển đổi danh sách
 *          thành cây nhị phân tìm kiếm (BST). Hỗ trợ thêm node.
 * @version 1.0
 * @date    2025-30-03
 * @author  Dang Nguyen
 ***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
/**
 * @struct  CenterPoint
 * @brief   Cấu trúc của một node trong cây nhị phân tìm kiếm.
 */
struct Node {
    int key;            /**< Giá trị của node */
    struct Node* left;  /**< Con trỏ đến node con trái */
    struct Node* right; /**< Con trỏ đến node con phải */
};
/**
 * @brief   Khoi tao Node moi
 * @param   key   Gia tri node moi.
 * @param   left  Con tro left tro den NULL.
 * @param   right  Con tro right tro den NULL.
 * @return  struct Node* tra ve kieu cau truc cua mot node.
 */

struct Node* newNode(int item) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
/**
 * @brief   Thêm node vào cay nhi phan và sắp xếp theo thứ tự tăng dần.
 * @param   node   Mot node moi duoc them vao.
 * @param   key  Gia tri cua node moi do.
 * @return  struct Node*
 */

struct Node* insert(struct Node* node, int key) {
    if (node == NULL)
        return newNode(key);
    if (node->key == key)
        return node;
    if (node->key < key)
        node->right = insert(node->right, key);
    else
        node->left = insert(node->left, key);
    return node;
}
/**
 * @brief   In ra cay nhi phan
 * @param   root   Node root coi nhu la mot node goc.
 * @return  void
 */
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}
int main() {
    // Creating the following BST
    //      50
    //     /  \
    //    30   70
    //   / \   / \
    //  20 40 60 80

    struct Node* root = newNode(50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
    inorder(root);

    return 0;
}

``` 

