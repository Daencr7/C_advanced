# File operations
# 1.File operations
- File CSV ( Comma-Separated Values) là một file văn bản được sử dụng để lưu trữ và truyền tải dữ liệu có cấu trúc dưới dạng bảng, trong đó các dữ liệu của các cột được phân tách bằng dấu phẩy hoặc một kí tự ngăn cách khác.
# 2.Thao tác với file CSV
- Để mở một file, bạn có thể sử dụng hàm fopen(). Hàm này trả về một con trỏ FILE, và cần được kiểm tra để đảm bảo file đã mở thành công.
```cpp
FILE *file = fopen(const char *file_name, const char *access_mode);
```
| Chế độ | Mô tả |
| --------------- | --------------- |
| r | Mở file với chế độ chỉ đọc file. Nếu mở file thành công thì trả về địa chỉ của phần tử đầu tiên trong file, nếu không thì trả về NULL.|
| rb | Mở file với chế độ chỉ đọc file theo định dạng binary. Nếu mở file thành công thì trả về địa chỉ của phần tử đầu tiên trong file, nếu không thì trả về NULL. |
| w | Mở file với chế độ ghi vào file. Nếu file đã tồn tại, thì sẽ ghi đè vào nội dung bên trong file. Nếu file chưa tồn tại thì sẽ tạo một file mới. Nếu không mở được file thì trả về NULL. |
| wb | Mở file với chế độ ghi vào file theo định dạng binary. Nếu file đã tồn tại, thì sẽ ghi đè vào nội dung bên trong file. Nếu file chưa tồn tại thì sẽ tạo một file mới. Nếu không mở được file thì trả về NULL. |
| a | Mở file với chế độ nối. Nếu mở file thành công thì trả về địa chỉ của phần tử cuối cùng trong file. Nếu file chưa tồn tại thì sẽ tạo một file mới. Nếu không mở được file thì trả về NULL. |
| ab | Mở file với chế độ nối dưới định dạng binary. Nếu mở file thành công thì trả về địa chỉ của phần tử cuối cùng trong file. Nếu file chưa tồn tại thì sẽ tạo một file mới. Nếu không mở được file thì trả về NULL. |
| r+ | Mở file với chế độ đọc và ghi file. Nếu mở file thành công thì trả về địa chỉ của phần tử đầu tiên trong file, nếu không thì trả về NULL. |
| rb+ | Mở file với chế độ đọc và ghi file dưới định dạng binary. Nếu mở file thành công thì trả về địa chỉ của phần tử đầu tiên trong file, nếu không thì trả về NULL. |
| w+ | Mở file với chế độ ghi và đọc file. Nếu file đã tồn tại thì trả về địa chỉ của phần tử đầu tiên của file. Nếu file chưa tồn tại thì sẽ tạo một file mới. |
| wb+ | Mở file với chế độ ghi và đọc file dưới định dạng binary. Nếu file đã tồn tại thì trả về địa chỉ của phần tử đầu tiên của file. Nếu file chưa tồn tại thì sẽ tạo một file mới. |
| a+ | Mở file với chế độ nối và đọc file. Nếu file đã tồn tại thì trả về địa chỉ của phần tử cuối cùng của file. Nếu file chưa tồn tại thì sẽ tạo một file mới. |
| ab+ | Mở file với chế độ nối và đọc file dưới định dạng binary. Nếu file đã tồn tại thì trả về địa chỉ của phần tử cuối cùng của file. Nếu file chưa tồn tại thì sẽ tạo một file mới. |
- Đọc File
| Tên hàm | Mô tả |
| --------------- | --------------- |
| fscanf() | Sử dụng chuỗi được định dạng và danh sách đối số biến để lấy đầu vào từ một File |
| fgets() | Copy nội dung trong File vào mảng dùng để lưu trữ với tối đa số lượng phần tử của mảng hoặc tới khi gặp ký tự xuống dòng. |
| fgetc() | Lấy giá trị tại địa chỉ hiện tại của file, sau đó di chuyển tới địa chỉ tiếp theo. Kiểu trả về là char |
| fread() | Đọc một số lượng byte được chỉ định từ File .bin |
| fprintf() | Ghi chuỗi vào File, và có thể thêm danh sách các đối số  |
| fputs() | Ghi chuỗi vào File |
| fputc() | Ghi một ký tự vào File |
| fwrite() | Ghi một số byte được chỉ định vào File .bin |
| fclose() | Đóng File đã mở |
| feof() | Để kiểm tra địa chỉ hiện tại có phải ký tự cuối cùng của File hay chưa |
