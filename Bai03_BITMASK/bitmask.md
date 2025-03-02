# BITMASK
## 1. Bitmask là gì?
-  Bitmask là một kỹ thuật sử dụng các bit để lưu trữ và thao tác với các cờ (flags) 
hoặc trạng thái. Có thể sử dụng bitmask để đặt, xóa và kiểm tra trạng thái của các bit cụ 
thể trong một từ (word).
-  Bitmask thường được sử dụng để tối ưu hóa bộ nhớ, thực hiện các phép toán logic 
trên một cụm bit, và quản lý các trạng thái, quyền truy cập, hoặc các thuộc tính khác của 
một đối tượng.
- Về cơ bản, có 6 toán tử bitwise trong C có thể được sử dụng để thao tác bit như sau:
```
& (Bitwise AND Operator)
| (Bitwise OR Operator)
^ (Bitwise XOR Operator)
~ (Bitwise NOT Operator)
>> (RIght Shift Operator)
<< (Left Shift Operator)
```
## 2. Toán tử bitwise
Các toán tử này được nhắc đến nhiều trong bộ môn kĩ thuật số, mạch số,...
### 2.1 NOT
![image](https://github.com/user-attachments/assets/070f4f51-01b6-4416-bfad-2aa4056b01a9)
- Cú pháp:
```
!Condition

// returns true if the conditions is false
// else returns false
```
### 2.2 OR
![image](https://github.com/user-attachments/assets/786001a1-baf5-4648-8773-e3c1789c848c)

### 2.3 AND
![image](https://github.com/user-attachments/assets/eb0eef1e-d807-46b1-a5e1-ef19ef45ffe2)

### 2.4 XOR
![image](https://github.com/user-attachments/assets/0a2ef077-e8ed-4184-9016-4abeaf3cf7b5)

### 2.5 SHIFT LEFT
-  Trong trường hợp <<, các bit ở bên phải sẽ được dịch sang trái, và các bit trái cùng 
sẽ được đặt giá trị 0.
### 2.6 SHITF RIGHT
-  Trong trường hợp >>, các bit ở bên trái sẽ được dịch sang phải, và các bit phải 
cùng sẽ được đặt giá trị 0 hoặc 1 tùy thuộc vào giá trị của bit cao nhất (bit dấu).
-  Bit dấu là bit cao nhất (Most Significant Bit - MSB) trong một số nhị phân.

Ví dụ 
```cpp
int main()
{
    // a = 5 (00000101 in 8-bit binary), b = 9 (00001001 in
    // 8-bit binary)
    unsigned int a = 5, b = 9;

    // The result is 00000001
    printf("a = %u, b = %u\n", a, b);
    printf("a&b = %u\n", a & b);

    // The result is 00001101
    printf("a|b = %u\n", a | b);

    // The result is 00001100
    printf("a^b = %u\n", a ^ b);

    // The result is 11111111111111111111111111111010
    // (assuming 32-bit unsigned int)
    printf("~a = %u\n", a = ~a);

    // The result is 00010010
    printf("b<<1 = %u\n", b << 1);

    // The result is 00000100
    printf("b>>1 = %u\n", b >> 1);

    return 0;
}
```
## 3. Một số kĩ thuật dùng bitwise
1. Setting a Bit
```
number | (1 << bit_position_to_set)
-----------------------------------
printf("Ans: %d", 13 | (1 << 5));
```
Từ 1 số dịch trái 5 bit ta được 32 tương đương 100000 | 13 ở dạng nhị phân là 45
3. Clearing a Bit
```
number & ~(1 << bit_position_to_clear)
-----------------------------------
printf("Ans: %d", 13 & ~(1 << 2) ); 
```
1 dịch trái 2 bit 0100
đảo bit 1011
& 13 : 1011&1101 = 1001 là 9.
5. Flipping a Bit
```
number ^ (1 << bit_position_to_flip)
-----------------------------------
printf("Ans: %d", 13 ^ (1 << 3) ); 
```
Tương tự ra được 5
7. Checking a Bit
```
number & (1 << bit_position_to_check)
-----------------------------------
printf("Ans: %d \n", 13 & (1 << 3) ); 
printf("Ans: %d \n", 13 & (1 << 4) ); 
```
Ans: 8 
Ans: 0

