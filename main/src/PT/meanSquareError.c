#include <stdio.h>

double mean_square_error(size_t n,const int a[],const int b[]){
    double s=0;
    int c;
    int x=(int)n;
    for(int i=0;i<x;i++){
        if(a[i]>b[i]){
            c=a[i]-b[i];
        }
        else{
            c=b[i]-a[i];
        }
        s+=(c*c);
    }
    return s/x;
}

int main(){
    int a[]={1,2,3};
    int b[]={4,5,6};    //sizeof(a)==sizeof(b);
    int len=sizeof(a)/sizeof(a[0]);
    double m=mean_square_error(len,a,b);
    printf("%.lf\n",m);
}