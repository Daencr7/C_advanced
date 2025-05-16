# STANDARD TEMPLATE LIBRARY

## Giới thiệu
Standard Template Library (STL) là một tập hợp các thư viện thiết kế để hỗ trợ lập trình tổng quát (generic programming).

STL C++ cung cấp một tập hợp các template classes và functions để thực hiện nhiều loại cấu trúc dữ liệu và các thuật toán phổ biến.

Một số thành phần chính của STL:
- Containers (Cấu trúc dữ liệu)
- Iterators (Bộ lặp)
- Algorithms (Thuật toán)
- Functors & Lambda
## Containers
Trong STL gồm có một số containers phổ biến:
- Vector
- Set, MultiSet, Unordered_set
- Map, Multimap, Unordered_map
### Vector
Vector trong C++ là một container kiểu mảng động, tương tự như mảng nhưng linh hoạt và hỗ trợ nhiều hàm có sẵn. 

Cú pháp:
```cpp
    vector<data_type> vector_name;
```
Các kiểu khai báo:
```cpp
    //Khai báo vector rỗng
    vector<int> v1;
    //Khai báo vector với các phần tử
    vector<int> v2 = {1, 2, 3, 4, 5};
    //Khai báo vector có sẵn n phần tử
    int n = 20;
    vector<int> v3(n);
    //Khai báo vector có sẵn n phần tử có cùng giá trị val
    int val = 0;
    vector<int> v4(n, val);
    return 0;
```
Các hàm sử dụng:

size() : Trả về số lượng phần tử trong vector. Độ phức tạp O(1).

length() : Trả về số lượng phần tử trong vector. Độ phức tạp O(1).

push_back() : Thêm phần tử vào cuối vector. Độ phức tạp O(1).

pop_back() : Xóa phần tử cuối cùng trong vector. Độ phức tạp O(1).
- Hàm truy cập phần tử:

![image](https://github.com/user-attachments/assets/7fb5b802-55d2-4959-9436-55fe90fc0c2d)

- Hàm kích thước:

![image](https://github.com/user-attachments/assets/38bbcaf6-4f8d-4fcc-9876-b90b0b4aa5bf)

- Hàm thêm, chèn, xóa:

![image](https://github.com/user-attachments/assets/8085bf47-00d0-4d38-ba64-2172b52c47b9)


Sử dụng vector:

```cpp
    vector<int> v;
    v.push_back(1); // thêm phần tử 1 vào cuối vector v
    cout << v.size() << v.length(); // In kích thước vector v
    v.pop_back(); // Xóa phần tử 1 ra khỏi vector
```
Sử dụng vector cho mảng hai chiều:

```cpp
vector<vector<data_type>> v;
```
Sử dụng push_back() một vector vào v sẽ tạo thành mảng 2 chiều.

### Set
Set là một container được xây dựng sẵn.
Set được cài đặt bởi cấu trúc dữ liệu cây nhị phân tìm kiếm (binary search tree).

- Các phần tử trong set có giá trị khác nhau, không có 2 phần tử có cùng giá trị.
- Các phần tử trong set được tự động sắp xếp theo thứ tự tăng dần.
- Tìm kiếm phần tử trong set chỉ mất độ phức tạp O(logN).
- Set không thể truy cập phần tử thông qua chỉ số như mảng hay vector, string.

Cú pháp:
```cpp
#include <set>
set<data_type> set_name;
```
Một số hàm cơ bản của set:

![image](https://github.com/user-attachments/assets/c19b8b4c-8267-410a-bbf0-21867b799324)

### Map
Map là một container lưu trữ dữ liệu tương tự như một từ điển, mỗi phần tử trong map là một cặp key - value.

- Các key trong map là riêng biệt, không có 2 key trùng nhau.
- Map duy trì thứ tự các phần tử theo giá trị key tăng dần.
- Map tìm kiếm giá trị key với độ phức tạp O(logN).
- Map không hỗ trợ truy cập thông qua chỉ số như mảng hay vector, string.
- Mỗi phần tử trong map chính là 1 pair.

Cú pháp:
```cpp
#include <map>
map<key_data_type, value_data_type> map_name;
```

Một số hàm cơ bản của map:

- insert() : Thêm phần tử vào trong map với độ phức tạp 
- size() : Trả về số phần tử trong map 
- clear() : Xóa toàn bộ phần tử trong map
- empty() : Kiểm tra vector rỗng

### List
List là một container trong STL của C++, triển khai dưới dạng danh sách liên kết hai chiều.

Một số đặc điểm quan trọng của list:
- Truy cập tuần tự: Truy cập các phần tử của list chỉ có thể thực hiện tuần tự, không hỗ trợ truy cập ngẫu nhiên.
- Hiệu suất chèn và xóa: Chèn và xóa ở bất kỳ vị trí nào trong danh sách có hiệu suất tốt hơn so với vector. Điều này đặc biệt đúng khi thêm/xóa ở giữa danh sách.

Một số method của list:
- push_back(): thêm node cuối list
- push_front(): thêm node đầu list
- insert(): thêm node vị trí bất kỳ
- pop_back(): xóa node cuối list
- pop_front(): xóa node đầu list
- erase(): xóa node bất kỳ của list
- size(): Trả về kích thước của list

Sử dụng:

- Thực hiện nhiều thao tác chèn/xóa ở bất kỳ vị trí nào trong danh sách.
- Cần thực hiện nhiều thao tác chèn/xóa mà không làm ảnh hưởng đến các iterators hiện có.
- Dung lượng không quan trọng hoặc thay đổi thường xuyên.

Cú pháp:
```cpp
list <data_type> name; 
```
### Array
std::array là một container có kích thước cố định và có sẵn trong thư viện STL (Standard Template Library)

Array có kích thước cố định được xác định tại thời điểm biên dịch và không thể thay đổi sau khi được khai báo.

Array hỗ trợ truy cập ngẫu nhiên vào các phần tử thông qua toán tử []

Cú pháp:
```cpp
array <data_type, size> array_name;
```
## Iterators
Iterator trong C++ là một đối tượng tương tự như con trỏ, nó được sử dụng trỏ đến các phần tử trong container của STL như vector, set, map...

Iterator tương tự như con trỏ, nó trỏ tới các phần tử trong vector.

Có 4 iterator chính trong vector mà cần nắm được : 

1. begin() : Iterator trỏ tới phần tử đầu tiên trong vector.
2. end() : Iterator trỏ tới phần tử sau phần tử cuối cùng trong vector.
3. rbegin() : Iterator ngược trỏ tới phần tử cuối cùng trong vector.
4. rend() : Iterator ngược trỏ tới phần tử trước phần tử đầu tiên trong vector.

![alt text](image-5.png)

Cú pháp khai báo iterator:
```cpp
vector<data_type>::iterator iterator_name;
vector<data_type>reverse_iterator iterator_name;
```
Duyệt bằng interator

```cpp
#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> v = {28, 100, 30, 20, 15};
    cout << "Duyet vector bang iterator : \n";
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    cout << "\nDuyet nguoc vector bang iterator nguoc : \n";
    for(vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); ++it){
        cout << *it << ' ';
    }
    return 0;
}
```
Duyệt Iterator cũng tương tự với `set` và `map`.
## Algorithms

Thư viện STL (Standard Template Library) cung cấp một số thuật toán tiêu biểu thông qua algorithm. Các thuật toán này hoạt động trên các phạm vi hoặc các loại dữ liệu khác nhau, giúp thực hiện các nhiệm vụ như sắp xếp, tìm kiếm, chuyển đổi dữ liệu, và nhiều thao tác khác. 

Các thao tác với thuật toán trên vector:
- `sort()`
- `find()`

Cơ bản được được ứng dụng trên mảng, cũng có thể thực hiện trên vector.

Ví dụ:
```cpp
sort(arr.begin(), arr.end());

auto it = find(arr.begin(), arr.end(), <value>);
```
