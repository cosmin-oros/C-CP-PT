#include <stdio.h>

int main(){
    int a,b;
    int *pa,*pb;
    int *temp;
    printf("Enter a value for a:");
    scanf("%d",&a);
    printf("\nEnter a value for b:");
    scanf("%d",&b);
    printf("Before swapping a=%d b=%d\n",a,b);
    pa=&a;
    pb=&b;
    temp=pa;
    *pa=*pb;
    *pb=*temp;
    printf("After swapping a=%d b=%d\n",a,b);
    return 0;
}