#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    float *element;
    scanf("%d",&n);
    element=(float*)calloc(n,sizeof(float));
    if(element==NULL){
        printf("No memory allocated\n");
        exit(0);
    }
    for(int i=0;i<n;i++){
        scanf("%f",element+i);
    }
    for(int i=1;i<n;i++){
        if(*element<*(element+i)){
            *element=*(element+i);
        }
    }
    printf("The largest nr is: %.f\n",*element);
    return 0;
}