#include <stdio.h>
#include <ctype.h>

/*
2. Ints in string Write a function that prints out all numbers (strings of digits with optional sign) 
from a string given as parameter. Consider only standalone numbers, 
i.e. numbers that do not have any non-whitespace characters adjacent to them.
*/

void printNrs(char* str){
    int number=0;
    for(int i=0;str[i]!='\0';i++){
        int j=i;
        if(str[i]==' '){
            i++;
            if(str[i]=='-'||str[i]=='+'||isdigit(str[i])){
                printf("am gasit un posibil numar care incepe la poz %d\n", i);     //position 10
                while(isdigit(str[i++])){
                    printf("\n");   //executes this twice but at the number 13 it should only execute it once
                }
                printf("Numarul se termina la poz %d\n", i-1);  //it should be position 11 but it prints 12
                if(str[i]==' '){
                    number++;
                    printf("A\n");  //doesn't print this
                }
            }
        }
        if(number){
            while(str[j++]!=' '){
                printf("%c",str[j]);
            }
            printf("\n");
        }
        number=0;
    }
}

int main(){
    char str[]="ana12 are 13 mere si -14 pere";
    //fgets(str,10,stdin);
    printNrs(str);
    return 0;
}