#include <stdio.h>
#include <ctype.h>

int max_len_of_subs(){
    int c,sum=0,lenght=0;
    while((c=getchar())!='-'){  //we stop when we find a negative value
        while(c!=' '){
            sum=sum+c;
            lenght++;
            c=getchar();
        }
        if(sum%2==0){
            lenght=0;       //we keep the lenght only if the sum is odd
        }
        sum=0;
    }
    return lenght;
}
int main(){
    int c;
    while((c=getchar())!=EOF){
        ungetc(c,stdin);
        printf("%d",max_len_of_subs());  //max_len_of_subs() computes until it finds a negative number and returns the lenght
    }                                   //of numbers that have the sum of digits odd
    return 0;
}