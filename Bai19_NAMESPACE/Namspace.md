# NAMESPACE
_Namespace_ là cách nhóm các đối tượng như biến, hàm, class, struct,... vào một không gian tách biệt.

_Namespace_ được sử dụng với mục đích là để tránh xung đột tên khi có các định danh giống nhau được khai báo trong các phần của chương trình hoặc các thư viện khác nhau.

Tóm lại là `namespace` tránh xung đột giữa những hàm do người dùng viết và những hàm hệ thống có cùng tên do trình biên dịch không biết được hàm được gọi sẽ lấy từ định nghĩa của file nào.

## Sử dụng namespace
Cú pháp:
```cpp
namespace name_of_namespace{
    //code
}
```
Ví dụ:

fileA.cpp
```cpp
#include <iostream>

using namespace std;

namespace fileB{
    void function() { 
        //code
    }
}
```
fileB.cpp
```cpp
#include <iostream>

using namespace std;

namespace fileC{
    void function() { 
        //code
    }
}
```
file_main.cpp
```cpp
#include <iostream>
#incldue “fileA.hpp”
#include “fileB.hpp”

using namespace std;

int main() {
    fileB::function();
    fileC::function();
    
    return 0;
}
```
Khai báo `Namespace`:
```cpp
using namespace ten_namespace;
```
Khai báo như này có thể gọi trực tiếp các hàm,.. được định nghĩa trong `namespace`
fileA.hpp
```cpp
#include <iostream>

using namespace std;

namespace fileB{
    Void function() { cout << “function in fileB running.” << endl; }
}
```
file_main.hpp
```cpp
#include <iostream>
#incldue “fileB.hpp”

using namespace std;
using namespace fileB;

int main() {
    function();

    return 0;
}
```
## Name mangling
Là một cơ chế của trình biên dịch `g++` nhằm mã hóa tên hàm, biến, class, namespace,.. thành tên duy nhất để tránh xung đột trong quá trình biên dịch (giai đoạn compiler).

Trong C++, ta có thể dùng:
- Class chứa hàm thành viên
- Nạp chồng hàm (hàm trùng tên, khác tham số)
- Template
- Namespace

C++, compiler thực hiện name mangling bằng cách thêm các thông tin như tên của lớp, các tham số của hàm, kiểu dữ liệu của tham số vào tên của biến hoặc hàm.

Ví dụ:
```cpp
namespace A{
    void foo() {
        cout << "A:foo()";
    }
}

A::foo() -> _ZN1A3fooEv
```
Ý nghĩa:

- `_z` : bắt đầu name mangling
- `N...E` : Tên nằm trong namespace hoặc class
- `1A` : Namespace "A" (1 ký tự)
- `3foo` : Tên hàm "foo" (3 ký tự)
- `v` : Không có tham số

Mã hóa: `nm <name_file>.o | grep <function>`

Giải mã: `c++filt _ZN1A3fooEv`

