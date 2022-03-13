#include <stdio.h>
#include <stdlib.h>

int** create_spiral(int n){
    if(n<=0){
        return NULL;
    }
    int** array=(int**)calloc(n,sizeof(int*));
    for(int i=0;i<n;i++){
        array[i]=(int*)calloc(n,sizeof(int));
    }
    int x=-1,y=0,dx=1,dy=0,l=n,k=0;
    while(l>0){
        for(int i=0;i<l;i++){
            x+=dx;
            y+=dy;
            if(x>=0){
                array[y][x]=k++;
            }
            if(l==0){
                return array;
            }
        }
        if(dy==0){
            l--;
        }
        int t=dx;
        dx=-dy;
        dy=t;
    }
    return array;
}

int main(){
    int** v=create_spiral(3);
    for(int i=0;i<3;i++){
        for(int j=i;j<3;j++){
            printf("%d ",v[i][j]);
        }
    }
    return 0;
}