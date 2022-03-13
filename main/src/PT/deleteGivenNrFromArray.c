#include <stdio.h>

void readElemOfArray(int vectorx[], int n){
    printf("Enter the elements of the array: \n");
    for(int i=0;i<n;i++){
        scanf("%d",&vectorx[i]);
    }
}

int findElement(int vectorx[], int n, int del){
    for(int i=0;i<n;i++){
        if(vectorx[i]==del){
            return i;
        }
    }
    return 0;
}

void delete(int vectorx[], int n, int elem){
    for(int i=elem;i<n-1;i++){
        vectorx[i]=vectorx[i+1];
    }
}

int main(){
    int vectorx[100];
    int n,del,elem;
    printf("Enter how many elements do you want to have in the array: ");
    scanf("%d",&n);
    if(n>100){
        while(n>100){
            printf("Enter how many elements do you want to have in the array: ");
            scanf("%d",&n);
        }
    }
    readElemOfArray(vectorx,n);
    printf("The elements you introduced in the array are: \n");
    for(int i=0;i<n;i++){
        printf("%d ",vectorx[i]);
    }
    printf("Enter the value that you want to eliminate from the array: ");
    scanf("%d",&del);
    if(elem=findElement(vectorx,n,del)){
        do{
            delete(vectorx,n,elem);
            n--;
        }while(elem=findElement(vectorx,n,del));
        
    }
    printf("The array after deleting the %d value: \n",del);
    for(int i=0;i<n;i++){
        printf("%d ",vectorx[i]);
    }
    
    return 0;
}