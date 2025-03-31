# JSON
## 1. JSON là gì?
- JSON viết tắt của JavaScript Object Notation - Ghi chú về đội trượng JavaScript
- Đây là một dạng truyền tải dữ liệu phổ biến trong lập trình và giao tiếp giữa các máy chủ và trình duyệt web, cũng như giữa các hệ thống khác nhau.
Tóm tắt lại
- JSON là định dạng trao đổi dữ liệu văn bản dung lượng nhẹ
- JSON là ngôn ngữ độc lập
- JSON được "tự mô tả" và dễ hiểu.
- JSON có thể lưu số, kí tự, đối tượng
* Ví dụ định nghĩa 1 chuỗi JSON:
`
{
"username" : "kimoanh",
"email" : "kimoan@gmail.com",
"website" : "json.org",
"title" : "Tìm hiểu về JSON"
}
`
+ Với một chuỗi Json sẽ bắt đầu và kết thúc bởi dấu ngoặc nhọn `{}`.
+ Mỗi thông tin dữ liệu sẽ có 2 phần gồm `key` và `value`.
+ Giữa mỗi cặp `key-value` này sẽ được ngăn với cặp `key-value` khác bằng dấu phẩy `,`
## 2. Xử lý chuỗi JSON
- Đơn giản bản chất Json chính là chuỗi với mỗi kí tự liên tiếp được lưu trong các ô nhớ liên tiếp nhau.
- Xử lý JSON chính là xử lý với chuỗi.
- Khi bạn muốn lưu trữ dữ liệu đơn thuần dưới dạng metadata ở phía server. Chuỗi JSON sẽ được lưu vào database và sau đó khi cần dữ liệu thì sẽ được giải mã. Ví dụ với PHP, nó cung cấp các hàm liên quan đến JSON để mã hóa hoặc giải mã là `json_encode` và `json_decode`.
