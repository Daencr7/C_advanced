#include <stdio.h>
#include <setjmp.h>
#include <string.h>
jmp_buf buf;

int exception_code;

enum ErrorCodes { 
    NO_ERROR, 
    FILE_ERROR, 
    NETWORK_ERROR,
    CALCULATION_ERROR 
}; 
char error_message[50];
#define TRY if ((exception_code = setjmp(buf)) == 0)
#define CATCH(x) else if (exception_code == x) 
#define THROW(x,error_message) longjmp(buf, x)

void readFile() {
    printf("Reading file...\n");
    THROW(FILE_ERROR, "Error read file: File does not exist.");
}
void networkOperation() {
    printf("Running...\n");
    THROW(NETWORK_ERROR, "Error run network: Network does not run.");
}
void calculateData() {
    printf("Calculating...\n");
    THROW(FILE_ERROR, "Error calculate data: Can not calculate data.");
}

int main(int argc, char const *argv[])
{
    exception_code = 0;

    TRY {
        readFile();
        networkOperation();
        calculateData();
    } 
    CATCH(FILE_ERROR) {
        printf("%s\n", error_message);
    }
    CATCH(NETWORK_ERROR) {
        printf("%s\n", error_message);
    }
    CATCH(CALCULATION_ERROR) {
        printf("%s\n", error_message);
    }
    printf("Program is closed");
    return 0;
}
