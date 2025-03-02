#include <stdio.h>
#include <setjmp.h>
#include <string.h>


jmp_buf buf;
enum ErrorCodes { 
    NO_ERROR, 
    DIVIDE_ERROR, 
    OTHER_ERROR, 
}; 
int exception_code; 
char error_code[30];
char *error[] = {"Divide0","Othererror"};
#define TRY if ((exception_code = setjmp(buf)) == 0)
#define CATCH(x) else if (exception_code == x) 
#define THROW(x,error) {\
    int i = 0;\
    while(error[i]!='\0'){\
        error_code[i] = error[i];\
        i++;\
    }\
    error_code[i] = '\0';\
    longjmp(buf, x);\
}
double divide(int a, int b) {
    if (b == 0 && a != 0){
        THROW(DIVIDE_ERROR,error[0]);
    }
    else if(b == 0 && a == 0){
        THROW(OTHER_ERROR,error[1]);
    } 
    else return (double)a / b;
}
int main(int argc, char const *argv[])
{


    exception_code = 0;
    int a,b;
    printf("Enter a = ");scanf("%d",&a);
    printf("Enter b = ");scanf("%d",&b);
    // printf("%d",a);

    TRY
    {
        printf("Result: %0.3f\n", divide(a,b));
    }
    CATCH(DIVIDE_ERROR)
    {   
        printf("%s\n",error_code);
    }
    CATCH(OTHER_ERROR)
    {   
        printf("%s\n",error_code);
    }
    return 0;
}
