#include <stdio.h>

void inputMatrix(int matrix[][3],int rows,int cols){
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            scanf("%d",(*(matrix+i)+j));    //equivalent to &matrix[i][j]
        }
    }
}

void printMatrix(int (*matrix)[3],int rows,int cols){
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            printf("%d ",*(*(matrix+i)+j));   //equivalent to matrix[i][j]
        }
        printf("\n");
    }
}

int main(){
    int matrix[3][3];
    printf("Enter the elements in the matrix:\n");
    inputMatrix(matrix,3,3);
    printf("The elements of the matrix:\n");
    printMatrix(matrix,3,3);
    return 0;
}