#include <stdio.h>
#include <ctype.h>

int main(){
    char var1[]="program";
    char var2[]="0xF";
    if(isxdigit(var1[0])){
        printf("var 1 = |%s| is a hexidecimal character\n",var1);
    }
    else{
        printf("var 1 = |%s| is not a hexidecimal character\n",var1);
    }
    if(isxdigit(var2[0])){
        printf("var 2 = |%s| is a hexidecimal character\n",var2);
    }
    else{
        printf("var 2 = |%s| is not a hexidecimal character\n",var2);
    }
    return 0;
}