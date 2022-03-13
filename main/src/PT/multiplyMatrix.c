#include <stdio.h>

#define ROW 3
#define COL 3

void printMatrix(int mat[][COL]){
    for(int i=0;i<ROW;i++){
        for(int j=0;j<COL;j++){
            printf("%d ",*(*(mat+i)+j));   
        }
        printf("\n");
    }
}


void matrixMultiply(int mat1[][COL],int mat2[][COL],int product[][COL]){
    int sum;
    for(int i=0;i<ROW;i++){
        for(int j=0;j<COL;j++){
            sum=0;
            for(int k=0;k<COL;k++){
                sum+=(*(*(mat1+i)+k))*(*(*(mat2+k)+j));
            }
            *(*(product+i)+j)=sum;
        }
    }
}

void matrixInput(int mat[][COL]){
    for(int i=0;i<ROW;i++){
        for(int j=0;j<COL;j++){
            scanf("%d",(*(mat+i)+j));
        }
    }
}

int main(){
    int mat1[ROW][COL];
    int mat2[ROW][COL];
    int product[ROW][COL];
    printf("Enter the elements of the first array:\n");
    matrixInput(mat1);
    printf("Enter the elements of the second array:\n");
    matrixInput(mat2);
    matrixMultiply(mat1,mat2,product);
    printMatrix(product);
    return 0;
}