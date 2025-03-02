#include <stdio.h>
#include <setjmp.h>
#include <string.h>
jmp_buf buf;
#define error_check 2
int exception_code;

enum ErrorCodes { 
    NO_ERROR, 
    FILE_ERROR, 
    NETWORK_ERROR,
    CALCULATION_ERROR 
}; 
char error_reply[100];



#define TRY if ((exception_code = setjmp(buf)) == 0)
#define CATCH(x) else if (exception_code == x) 
#define THROW(x,error_message) {\
    int s = strlen(error_message);\
    for(int i = 0; i < s; i++){\
        error_reply[i] = error_message[i];\
    }    \
    error_reply[s] = '\0';\
    longjmp(buf, x);\
}

void readFile() {
    printf("Reading file...\n");
    if(error_check == FILE_ERROR){
        THROW(FILE_ERROR, "Error read file: File does not exist.");
    }
    else{
        printf("Reading complete!\n");
    }

}
void networkOperation() {
    printf("Running network...\n");
    if(error_check==NETWORK_ERROR){
        THROW(NETWORK_ERROR, "Error run network: Network does not run.");

    }else printf("NetworkOperation complete!\n");
}
void calculateData() {
    printf("Calculating data...\n");
    if(error_check==FILE_ERROR){
        THROW(FILE_ERROR, "Error calculate data: Can not calculate data.");
    }
    else{
        printf("Calculating complete!\n");
    }
}

int main(int argc, char const *argv[])
{
    TRY {
        readFile();
        networkOperation();
        calculateData();
    } 
    CATCH(FILE_ERROR) {
        printf("%s\n", error_reply);
    }
    CATCH(NETWORK_ERROR) {
        printf("%s\n", error_reply);
    }
    CATCH(CALCULATION_ERROR) {
        printf("%s\n", error_reply);
    }
    printf("Program is closed");
    return 0;
}
