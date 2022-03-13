#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
/*
Given two arrays a and b write a function comp(a, b) (orcompSame(a, b)) that checks whether the two arrays have the "same" elements,
 with the same multiplicities (the multiplicity of a member is the number of times it appears). 
"Same" means, here, that the elements in b are the elements in a squared, regardless of the order.
*/
bool comp(const int *a,const int *b){
    int found=0,same=1;
    if(sizeof(a)==sizeof(b)){
        for(int i=0;a[i]!='\0';i++){
            for(int j=0;b[j]!='\0';j++){
                if((a[i]*a[i])==b[j]){
                    found=1;
                }
            }
            if(found==0){
                same=0;
                break;
            }
            found=0;
        }
        if(same==1){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}

int main(){
    int a[] = {121, 144, 19, 161, 19, 144, 19, 11};
    int b[] = {121, 14641, 20736, 361, 25921, 361, 20736, 361};
    if(comp(a,b)==true){
        printf("They are the same\n");
    }
    else{
        printf("They are not the same\n");
    }
    return 0;
}