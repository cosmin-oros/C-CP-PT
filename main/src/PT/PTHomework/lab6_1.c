#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>

void myCustomPrintf(const char* format,unsigned int n,...){
    char type[3];   
    int k; 
    int number;
    int nr;
    va_list valist;
    va_start(valist,n);
    for (int i = 0; format[i]!='\0'; i++)
    {
        k=0;
        if (format[i]=='%')
        {
            while (isalpha(format[i++]) || format[i]=='0')
            {
                type[k]=format[i];
                k++;
            }
            for (int i = 0;type[i]; i++)
            {        
            switch (type[i])
            {
            case 'c':
                putchar(va_arg(valist,char));
                break;
            case 'd':
                number=va_arg(valist,int);
                while (number)
                {
                    nr=0;
                    nr=nr*10+number%10;
                    number/=10;
                }
                while (nr)
                {
                    putchar((nr%10)-'0');
                    nr/=10;
                }
                break;
                       
            default:
                for (int i = 0; type[i]!='\0'; i++)
                {
                    putchar(type[i]);
                }
                break;
            }
            }
        }
        else{
            putchar(format[i]);
        }
        for (int i = 0; i < 3; i++)
        {
            type[i]='\0';
        }
        
    }
    va_end(valist);
    
}

int main(){
    myCustomPrintf("%c has %d apples\n",2,"j", 3);
    return 0;
}