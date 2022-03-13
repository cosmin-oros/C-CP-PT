#include <stdio.h>
#include <ctype.h>

int number_of_digits(int c){    //we check for the number of digits in the respective number
    int k=1;
    while(isdigit(c=getchar())){
        k++;
    }
    ungetc(c,stdin);    //we got a character out that is not a digit so we must return it
    return k;
}

void line(int c){
    int k,a=0;
    ungetc(c,stdin);
    if(isdigit(c=getchar())){
        k=number_of_digits(c);      //we check for the number of digits of the first number so we have something to compare with
    }
    while((c=getchar())!='\n'){ //we compute this until we reach end of line
        if(isdigit(c)){
            if(number_of_digits(c)==k){
                a=1;
            }
            else{
                a=0;
            }
        }

    }
    if(a){  // if a exists then we can conclude that every number in this line has k digits
        printf("%d ",k);
    }
    else{
        printf("NO");
    }

}

int main(){
    int c;
    while((c=getchar())!=EOF){  //we compute until we reach end of file
        line(c);    //we check if there exists a number of digits k such that every number in this line has k digits
    }
    return 0;
}