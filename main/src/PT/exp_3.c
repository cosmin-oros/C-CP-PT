#include <stdio.h>

void check(int c){
    const int a=0;
    switch (c)
    {
    case 'i':
       
        a+=1;
        break;
    case 'd':
        a-=1;
        break;
    case 'p':
        a=a*a;
    case 'o':
        printf("%d",a);
    }
        
    
    
}

int main(){
    int c;
    while((c=getchar())!=EOF){
        check(c);
    }
    return 0;
}