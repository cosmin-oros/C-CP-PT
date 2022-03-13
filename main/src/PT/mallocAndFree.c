#include <stdio.h>
#include <stdlib.h>
int main(){
    int n,*ptr,sum=0;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    ptr=(int*)malloc(n*sizeof(int));
    if(ptr==NULL){
        printf("Error, memory not allocated");
        return 0;
    }
    printf("Enter the elements of the array:\n");
    for(int i=0;i<n;i++){
        scanf("%d",ptr+i);
        sum+=*(ptr+i);
    }
    printf("Elements of the array are:\n");
    for(int i=0;i<n;i++){
        printf("%d ",ptr[i]);
    }
    printf("\n");
    free(ptr);
    return 0;
}