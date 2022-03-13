#include <stdio.h>
#include <math.h>

int triangleType(int a,int b,int c){
    float as, bs, cs ;
    as = a*a ;
    bs = b*b ;
    cs = c*c ;
  
    if( (a >= b+c) || (b >= a+c) || (c >= a+b) ){
        return 0 ;
    }
  
    else if( (cs < bs+as) && (bs < as+cs) && (as < cs+bs) ){
        return 1 ;
    }
  
    else if( (as == bs+cs) || (bs == as+cs) || (cs == as+bs) ){
        return 2 ;
    }
  
    else if( (as > bs+cs) || (bs > as+cs) || (cs > as+bs) ){
        return 3 ;
    }
}

int main(){
    int a=triangleType(4,5,6);
    if(a==1){
        printf("Acute\n");
    }
    else if(a==2){
        printf("Right\n");
    }
    else if(a==3){
        printf("Obtuse\n");
    }
    else{
        printf("Not a triangle\n");
    }
}