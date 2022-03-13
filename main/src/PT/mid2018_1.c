#include <stdio.h>
#include <ctype.h>

int peek(){
    int a;
    a=getchar();
    ungetc(a,stdin);
    return a;
}

int maxim(int nr){
    static int max=0;
    if(nr>max){
        max=nr;
    }
    return max;
}

int nr(int c){
    int num=c;
    while((c=getchar())!=' '){
        num=num*10+c;
    }
    return num;
}
int main(){
    int c,number=0,m;
    while((c=getchar())!='\n'){
        if(isdigit(c)){
            number=nr(c);
        }
        m=maxim(number);
    }
    printf("\n The maximum value:%d",m);
    return 0;
}