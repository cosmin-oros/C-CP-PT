#include <stdio.h>

void fact(int n){
    int p=1,*f=1;
    while(p<=n){
        if(p!=1){
            printf("*%d",p);
        }
        else{
            printf("%d",p);
        }
        *f*=p;
        p++;
    }
    printf("=%d",*f);
}

int main(){
    int n;
    printf("Enter the number of which you want to find the factorial:\n");
    scanf("%d",&n);
    fact(n);
    return 0;
}