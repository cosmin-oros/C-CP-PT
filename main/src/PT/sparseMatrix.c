#include <stdio.h>

int main(){
    static int array[10][10];
    int m,n;
    int counter=0;
    printf("Enter the order of the matrix: ");
    scanf("%d %d",&m,&n);
    printf("Enter the coefficients of the matrix: \n");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&array[i][j]);
            if(array[i][j]==0){
                counter++;
            }
        }
    }
    if(counter>((m*n)/2)){
        printf("The given matrix is a sparse matrix\n");
    }
    else{
        printf("The given matrix is not a sparse matrix\n");
    }
    printf("There are %d zeros\n",counter);
    return 0;
}