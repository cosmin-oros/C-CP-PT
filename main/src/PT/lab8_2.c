#include <stdio.h>
int xPow(int x,int m){
    if(m>1){
        return xPow(x,m-1)*x; 
    }
    else{
        return x;
    }
}

int factorial(int m){
    if(m>1){
        return factorial(m-1)*m;
    }
    else{
        return 1;
    }
}

double taylorSin(int x){
    int n=1;
    double sin=x;
    int m,power,fact;
    while(sin>0.000001){
        m=2*n+1;
        if(n%2==0){
            power=xPow(x,m);
            fact=factorial(m);
            sin+=(1.0*xPow/factorial);
            n++;
        }
        else{
            power=xPow(x,m);
            fact=factorial(m);
            sin-=(1.0*xPow/factorial);
            n++;
        }
    }
    return sin;
}

double taylorCos(int x){
    int n=1;
    double cos=1;
    int m,power,fact;
    while(cos>0.000001){
        m=2*n;
        if(n%2==0){
            power=xPow(x,m);
            fact=factorial(m);
            cos+=(1.0*xPow/factorial);
            n++;
        }
        else{
            power=xPow(x,m);
            fact=factorial(m);
            cos-=(1.0*xPow/factorial);
            n++;
        }
    }
    return cos;
}

int main(){
    printf("%f\n",taylorSin(3));
    printf("%f\n",taylorCos(3));
    return 0;
}