#include <stdio.h>
/*
1) Implement the function int isSorted(unsigned t[], unsigned n) which checks 
if the array has the elements in a monotonous order (either increasing or decreasing), returning a logical result.
*/

int isSorted(unsigned t[],unsigned n){
    int k=1;
    for(int i=0;i<n;i++){
        if((t[i]<=t[i+1]) && i<(n-1)){
            k++;
        }
    }
    if(k==n){
        return 1;
    }
    else{
        k=1;
        for(int i=0;i<n;i++){
        if((t[i]>=t[i+1]) && i<(n-1)){
            k++;
        }
    }
    if(k==n){
        return 2;
    }
    else{
        return 0;
    }
    }
    
}

int main(){
    unsigned t[4]={4,3,2,1};
    if(isSorted(t,4)==1){
        printf("The elements of the array are in a monotonous order(increasing)\n");
    }
    else if(isSorted(t,4)==2){
        printf("The elements of the array are in a monotonous order(decreasing)\n");
    }
    else{
        printf("The elements of the array are not in a monotonous order\n");
    }
    return 0;
}