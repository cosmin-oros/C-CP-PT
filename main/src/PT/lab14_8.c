#include <stdio.h>
#include <stdlib.h>

struct pol{
    int degree;
    double coef[10];
};
typedef struct pol Polynom_t;

void printP(Polynom_t f){

    for(int i=((f.degree)-1);i>=0;i--){
        if(i==((f.degree)-1)){
            if(f.coef[i]){
                if(f.coef[i]==1 && (i+1)>1){
                    printf("X^%d",i+1);
                }
                else if(f.coef[i]>1 && (i+1)==1){
                    printf("%.lfX",f.coef[i]);
                }
                else if(f.coef[i]==1 && (i+1)==1){
                    printf("X");
                }
                else{
                    printf("%.lfX^%d",f.coef[i],i+1);
                }
            }
        }
        else{
            if(f.coef[i]>0){
                if(f.coef[i]==1 && (i+1)>1){
                    printf("+X^%d",i+1);
                }
                else if(f.coef[i]>1 && (i+1)==1){
                    printf("+%.lfX",f.coef[i]);
                }
                else if(f.coef[i]==1 && (i+1)==1){
                    printf("+X");
                }
                else{
                    printf("+%.lfX^%d",f.coef[i],i+1);
                }
                
            }
            else if(f.coef[i]<0){
                if(f.coef[i]==1 && (i+1)>1){
                    printf("X^%d",i+1);
                }
                else if(f.coef[i]>1 && (i+1)==1){
                    printf("%.lfX",f.coef[i]);
                }
                else if(f.coef[i]==1 && (i+1)==1){
                    printf("X");
                }
                else{
                    printf("%.lfX^%d",f.coef[i],i+1);
                }
            }
        }
    }
    printf("\n");
}

int main(){
    Polynom_t f1={3,{1,2,1}};
    Polynom_t f2={4,{1,2,3,1}};
    printP(f1);
    printP(f2);
    return 0;
}