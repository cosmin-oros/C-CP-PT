#include <stdio.h>
#include <stdlib.h>

/*
7. Rational numbers Define a structure type for rational numbers, holding numerator and denominator. 
Implement functions to add and multiply rationals. 
Return results that are in canonical form (denominator is positive and gcd with numerator is 1).
*/

struct Rational{
    int numerator;
    int denominator;
};
typedef struct Rational Q;

int LCM(int a,int b){
    int max=(a>b) ? a : b;
    while(1){
        if(max%a==0 && max%b==0){
            return max;
        }
        max++;
    }
}

int GCD(int a,int b){
    int gcd;
    for(int i=1;i<=a&&i<=b;i++){
        if(a%i==0 && b%i==0){
            gcd=i;
        }
    }
    return gcd;
}

Q organize(Q a){
    int m;
    if(a.denominator<0){
        a.numerator*=-1;
        a.denominator*=-1;
    }
    while((m=GCD(a.numerator,a.denominator))>1){
        a.numerator/=m;
        a.denominator/=m;
    }

    return (Q){a.numerator, a. denominator};

}

Q sum(Q n1,Q n2){
    Q result;
    int lcm;
    int a,b;
    if(n1.denominator!=n2.denominator){
        lcm=LCM(n1.denominator,n2.denominator);
        a=lcm/n1.denominator;
        n1.denominator*=a;
        n1.numerator*=a;
        b=lcm/n2.denominator;
        n2.denominator*=b;
        n2.numerator*=b;
        result.denominator=n1.denominator;
        result.numerator=n1.numerator+n2.numerator;
        organize(result);
    }
    else{
        result.numerator=n1.numerator+n2.numerator;
        result.denominator=n1.denominator;
        organize(result);
    }
    return result;
}

Q product(Q n1,Q n2){
    Q result;
    result.numerator=n1.numerator*n2.numerator;
    result.denominator=n1.denominator*n2.denominator;
    result=organize(result);
    return result;
}

int main(){
    Q nr1={3,5};
    Q nr2={6,10};
    if(!nr1.denominator || !nr2.denominator){
        printf("Not possible\n");
    }
    else{
        organize(nr1);
        organize(nr2);
        Q s=sum(nr1,nr2);
        Q p=product(nr1,nr2);
        printf("The sum is %d/%d\n",s.numerator,s.denominator);
        printf("The product is %d/%d\n",p.numerator,p.denominator);
    }
    return 0;
}