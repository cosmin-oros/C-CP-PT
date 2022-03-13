#include <stdio.h>
/*
2) Implement a function int arr(int x[], unsigned nx, int y[], unsigned ny) 
which checks if the array y can be obtained form array x by deleting some of it’s elements, returning a logical result.
*/

int arr(int x[], unsigned nx, int y[], unsigned ny){
    int k=0,nr=0,p=0;
    for(int i=0;i<ny;i++){
        for(int j=0;j<nx;j++){
            if(y[i]==x[j]){
                k=1;
            }
            
        }
        if(k==0){
            nx--;
            for(int j=p;j<nx;j++){
                x[j]=x[j+1];
            }
        }
        k=0;
    }
    for(int i=0;i<ny;i++){
        if(x[i]!=y[i]){
            nr=1;
        }
    }
    if(nr){
        return 0;
    }
    else{
        return 1;
    }
    
}

int main(){
    int y[]={1,2,3,4},x[]={1,2,4,3,5};
    if(arr(x,5,y,4)){
        printf("The array y can be obtained from array x by deleting some of it's elements\n");
    }
    else{
        printf("The array y can not be obtained from array x by deleting some of it's elements\n");
    }
    return 0;
}