# ASSERT
## 1. Assert là gì?
- Là một thư viện cung cấp macro assert.
- Macro này được sử dụng để kiểm tra điều kiện, nếu đúng thì tiếp tục, nếu sai thì dừng lại.
- Dùng debug, dùng #define NDEBUG để tắt debug.
## 2. Sử dụng Assert
- Cú pháp:
```cpp
void assert(int expression);
```
```cpp
#include <stdio.h>
#include <assert.h>
int main() {
  int x = 5;
  assert(x == 5);
  printf("X is: %d", x);
  return 0;
}
```
assert(x==5) kiểm tra xem x có bằng 5 hay không, trường hợp này x bằng 5 nên đoạn code phía sau được chạy.
- Assert được sử dụng với `#define` để debug
`#define LOG(condition, cmd) assert(condition && #cmd)`
```cpp
#include <assert.h>
#define ASSERT_IN_RANGE(val, min, max) assert((val) >=(min) && (val) <= (max))
void setLevel(int level) {
  ASSERT_IN_RANGE(level, 1, 10);
}
```
