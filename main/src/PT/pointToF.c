#include <stdio.h>
#include <stdlib.h>

int fctToCompareInt(const void* el1,const void* el2){
    int x=*(const int*)el1;
    int y=*(const int*)el2;
    return x-y;
}

int main(){
    int v[10];
    int n=sizeof(v)/sizeof(v[0]);
    for(int i=0;i<n;i++){
        v[i]=rand()%1000;
    }
    qsort(v,n,sizeof(v[0]),fctToCompareInt);
    for(int i=0;i<n;i++){
        printf("%d ",v[i]);
    }
}