#include <stdio.h>
#include <setjmp.h>
#include <string.h>
jmp_buf buf;

int exception_code; 
char error_code[20];
#define TRY if ((exception_code = setjmp(buf)) == 0)
#define CATCH(x) else if (exception_code == x) 
#define THROW(x,error_code) longjmp(buf, x)

double divide(int a, int b) {
    if (b == 0 && a == 0) THROW(2,"Loi Khac");
    else if (b == 0)
        THROW(1,"Loi Chia 0");
    else
        return (double)a / b;
}
int main(int argc, char const *argv[])
{
    exception_code = 0;

    TRY
    {
        printf("Ket qua: %0.3f\n", divide(1,0));
    }
    CATCH(1)
    {   if(exception_code)  strcpy(error_code,"Error: Divide 0");
        printf("%s\n",error_code);
    }
    CATCH(2)
    {   if(exception_code)  strcpy(error_code,"Error: Other");
        printf("%s\n",error_code);
    }
    return 0;
}
