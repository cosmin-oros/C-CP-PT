#include <stdio.h>
#include <ctype.h>
/*
2. Write a function that takes a string and prints out all numbers in the string. Prefix them with "int " or "float ",
 depending on their format (as in C).
 Print a) only numbers separated by whitespace from other text; b) all substrings interpretable as numbers.
*/

void print_numbers_a(char s[]){
    int j,dot=0,counter=0;
    for(int i=0;s[i]!='\0';i++){
        if(s[i]==' ' && isdigit(s[i+1])){
            j=i;
            while(isdigit(s[j++])){
                ;
            }
            if(s[j]==' '){
                i++;
                int nr=0;
                while(isdigit(s[i])){
                    nr*=10+s[i];
                    i++;
                }
                printf("%d ",nr);
            }
            else if(s[j]=='.'){
                float nr=0;
                while(isdigit(s[j++])){
                    ;
                }
                if(s[j]==' '){
                    i++;
                    while(isdigit(s[i]) || s[i]=='.'){
                        if(isdigit(s[i])){
                            nr*=10+s[i];
                        }
                        if(dot){
                            counter++;
                        }
                        if(s[i]=='.'){
                            dot=1;
                        }
                    }
                    while(counter){
                        nr/=10;
                        counter--;
                    }
                    printf("%f ",nr);
                }
            }
            dot=0;
            counter=0;
        }
    }
}

int main(){
    char s[]="John has 12 apples and 3.5 pears";
    print_numbers_a(s);
    return 0;
}