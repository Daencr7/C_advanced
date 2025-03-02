```cpp
#include <stdio.h>
#include <string.h>
//Khai báo cấu trúc và các thành phần trong cấu trúc
typedef struct {
   char ten[50];
   float diemTrungBinh;
   int id;
} SinhVien;
// hàm trả về int có đối 2 đối số là con trỏ hằng
int stringCompare(const char *str1, const char *str2) {
   while (*str1 && (*str1 == *str2)) { // điều kiện vòng lặp
       str1++;
       str2++;
   }
   return *(const unsigned char*)str1 - *(const unsigned char*)str2; // trả về việc so sánh ký tự đầu của 2 chuổi
}
// Giả sử so sánh 2 tên Hoang và Tuan
// str1-> H o a n g ------ str2->T u a n
//while -> (*str1 == true) true 
//      -> (*str1==*str2) true

// Hàm so sánh theo tên trả về hàm stringCompare
int compareByName(const void *a, const void *b) {
   SinhVien *sv1 = (SinhVien *)a;
   SinhVien *sv2 = (SinhVien *)b;
   return stringCompare(sv1->ten, sv2->ten);
}

// Hàm so sánh theo điểm trung bình
int compareByDiemTrungBinh(const void *a, const void *b) {
   SinhVien *sv1 = (SinhVien *)a;
   SinhVien *sv2 = (SinhVien *)b;
   if (sv1->diemTrungBinh > sv2->diemTrungBinh)
   {
       return 1;
   }
  
   return 0;
}

// Hàm so sánh theo ID
int compareByID(const void *a, const void *b) {
   SinhVien *sv1 = (SinhVien *)a; // thực hiện ép kiểu con trỏ hằng thành kiểu struct
   SinhVien *sv2 = (SinhVien *)b;
   return sv1->id - sv2->id;
}

// Hàm sắp xếp chung
void sort(SinhVien array[], size_t size, int (*compareFunc)(const void *, const void *)) {
   int i, j;
   SinhVien temp;
   for (i = 0; i < size-1; i++)    
       for (j = i+1; j < size; j++)
           if (compareFunc(array+i, array+j)>0) {
               temp = array[i];
               array[i] = array[j];
               array[j] = temp;
           }
}

void display(SinhVien *array, size_t size) {
   for (size_t i = 0; i < size; i++) {
       printf("ID: %d, Ten: %s, Diem Trung Binh: %.2f\n", array[i].id, array[i].ten, array[i].diemTrungBinh);
   }
   printf("\n");
}

int main() {
// Khai báo một đối tượng danhSachSV - mảng nhiều phần tử
   SinhVien danhSachSV[] = {
       {  
           .ten = "Hoang",
           .diemTrungBinh = 7.5,
           .id = 100
       },
       {
           .ten = "Tuan",
           .diemTrungBinh = 4.5,
           .id = 101
       },
       {
           .ten = "Vy",
           .diemTrungBinh = 6.8,
           .id = 102},
       {  
           .ten = "Ngan",
           .diemTrungBinh = 5.6,
           .id = 10
       },
   };
   size_t size = sizeof(danhSachSV) / sizeof(danhSachSV[0]);

   // Sắp xếp theo tên
   sort(danhSachSV, size, compareByName);

   display(danhSachSV, size);

   // Sắp xếp theo điểm trung bình
   sort(danhSachSV, size, compareByDiemTrungBinh);

   display(danhSachSV, size);

   // Sắp xếp theo ID
   sort(danhSachSV, size, compareByID);

   display(danhSachSV, size);

   return 0;
}
```
