#include <stdio.h>

int main(){
    char *s="test";
    printf("%s\n",s);
    int x=2,y,*p=&x;
    y=p;
    printf("%d %llu\n",x,y);
    
    int a=5,*p1=&a,**p2=&p1,b,c;
    b=p1;
    c=p2;
    printf("%d %d %d\n",a,b,c);
    return 0;
}