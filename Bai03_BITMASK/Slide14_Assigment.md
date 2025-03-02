```cpp
// Khai báo thư viện
#include <stdio.h>
#include <stdint.h>
// dùng macro định nghĩa các thành phần Color, power, engine và gán các giá trị tương ứng
#define COLOR_RED 0	
#define COLOR_BLUE 1
#define COLOR_BLACK 2
#define COLOR_WHITE 3
#define POWER_100HP 0
#define POWER_150HP 1
#define POWER_200HP 2
#define ENGINE_1_5L 0
#define ENGINE_2_0L 1
// Đặt lại tên uint8_t là kiểu nguyên dương 8bit thành 3 tên tương ứng
typedef uint8_t CarColor; 
typedef uint8_t CarPower; 
typedef uint8_t CarEngine;


// Định nghĩa các thành phân bằng bitmask 
#define SUNROOF_MASK 1 << 0     // 0001
#define PREMIUM_AUDIO_MASK 1 << 1 // 0010
#define SPORTS_PACKAGE_MASK 1 << 2 // 0100
// Thêm các bit masks khác tùy thuộc vào tùy chọn
// Cài đặc kiểu cấu trúc struct có tên là CarOptions
// 
typedef struct {
    uint8_t additionalOptions : 3; // 3 bits cho các tùy chọn bổ sung 3,2,2,1 truong bit so bit dc khai bao
    CarColor color : 2; // CarColor kieu uint8_t dùng trường bit 2 giá trị từ 0-3
    CarPower power : 2; //CarPower kieu uint8_t dùng trường bit 2 giá trị từ 0-3
    CarEngine engine : 1; //CarEngine kieu uint8_t dùng trường bit 1 giá trị 0-1
    
} CarOptions; //CarOptions : Tên được đặt lại cho kiểu cấu trúc

// Hàm cài đặc cho Car cho các trường color power engine, dùng -> vì kiểu con trỏ *car
void configureCar(CarOptions *car, CarColor color, CarPower power, CarEngine engine, uint8_t options) {
    car->color = color;
    car->power = power;
    car->engine = engine;
    car->additionalOptions = options;
}
// Đặt lựa chọn 
void setOption(CarOptions *car, uint8_t optionMask) {
    car->additionalOptions |= optionMask; // car-> additionalOptions = car-> additionalOptions | optionMask 
}
Hủy lựa chọn 
void unsetOption(CarOptions *car, uint8_t optionMask) {
    car->additionalOptions &= ~optionMask; // car-> additionalOptions = car-> additionalOptions & (~optionMask)
}

// Hàm hiển thị các option 
void displayCarOptions(const CarOptions car) {
// khai báo các mảng con trỏ  đến chuổi hằng có sẵn 
    const char *colors[] = {"Red", "Blue", "Black", "White"};
    const char *powers[] = {"100HP", "150HP", "200HP"};
    const char *engines[] = {"1.5L", "2.0L"};

    printf("Car Configuration: \n");
    printf("Color: %s\n", colors[car.color]); // truy cap phan tu mang dua vao chi so trong truong bit
    printf("Power: %s\n", powers[car.power]); // truy cap phan tu mang dua vao chi so trong truong bit
    printf("Engine: %s\n", engines[car.engine]); // truy cap phan tu mang dua vao chi so trong truong bit
    printf("Sunroof: %s\n", (car.additionalOptions & SUNROOF_MASK) ? "Yes" : "No"); 
    printf("Premium Audio: %s\n", (car.additionalOptions & PREMIUM_AUDIO_MASK) ? "Yes" : "No");
    printf("Sports Package: %s\n", (car.additionalOptions & SPORTS_PACKAGE_MASK) ? "Yes" : "No");
}

int main() {
    CarOptions myCar; // Khai báo đối tượng myCar cho cấu trúc CarOption
    configureCar(&myCar, COLOR_BLACK, POWER_150HP, ENGINE_2_0L, 0);  // cấu hình car truyền các đối số vào
    /* Lúc này đối tượng myCar đã có
    car->color = color; -COLOR_BLACK
    car->power = power; -POWER_150HP
    car->engine = engine; -ENGINE_2_0L
    car->additionalOptions = options; -0
    */

    setOption(&myCar, SUNROOF_MASK);
    /*
    car->additionalOptions |= optionMask; 0000- SUNROOF_MASK - 0001 -> 0001
    */
    setOption(&myCar, PREMIUM_AUDIO_MASK);
    /*
    car->additionalOptions |= optionMask;0001 - PREMIUM_AUDIO_MASK - 0010 -> 0011
    */
    displayCarOptions(myCar);
    /*
    const char *colors[] = {"Red", "Blue", "Black", "White"};
    const char *powers[] = {"100HP", "150HP", "200HP"};
    const char *engines[] = {"1.5L", "2.0L"};

    printf("Car Configuration: \n");
    printf("Color: %s\n", colors[car.color]); //  COLOR_BLACK - 2
    printf("Power: %s\n", powers[car.power]); //  POWER_150HP - 1
    printf("Engine: %s\n", engines[car.engine]); // ENGINE_2_0L - 1
    printf("Sunroof: %s\n", (car.additionalOptions & SUNROOF_MASK) ? "Yes" : "No"); 0011 & 0001 -> 0001
    printf("Premium Audio: %s\n", (car.additionalOptions & PREMIUM_AUDIO_MASK) ? "Yes" : "No"); 0011 & 0010 ->0010
    printf("Sports Package: %s\n", (car.additionalOptions & SPORTS_PACKAGE_MASK) ? "Yes" : "No");0011 & 0100 -> 0000
    */
    unsetOption(&myCar, PREMIUM_AUDIO_MASK);
    //car->additionalOptions &= ~optionMask; 0011 & ~(0010) -> 0001

    displayCarOptions(myCar);
    // tiếp tục hiển thị như trên nhưng lúc này Premium Audio: NO
    printf("size of my car: %d\n", sizeof(CarOptions));

    return 0;
}
```
