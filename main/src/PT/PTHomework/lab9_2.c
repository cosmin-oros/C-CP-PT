#include <stdio.h>
#include <stdlib.h>

/*2. Use divide and conquer to find the peak values from a 2D array of
 *given size populated with random values. The random() function
 *is accessible via <stdlib.h>.
 */

#define LEN1 10
#define LEN2 10

void fillArray(int r[LEN1][LEN1]){
    for (int i = 0; i < LEN1; i++)
    {
        for (int j = 0; j < LEN2; j++)
        {
            r[i][j]=rand()%10;
        }
        
    }
}

void findPeakValues(int* peakValues,int randArr[LEN1][LEN2]){
    for (int i = 0; i < LEN1; i++)
    {
        peakValues[i] = findMax(randArr,i,0,LEN1);   
    }
    
}

int findMax(int randArr[LEN1][LEN2],int i,int left,int right){
    int a,b,m;

    if (left == right)
    {
        return randArr[i][left];
    }
    else if (left==right-1)
    {
        if (randArr[i][left]>randArr[i][right])
        {
            return randArr[i][left];
        }
        else return randArr[i][right];
    }else{
        m = (left+right)/2;
        a = findMax(randArr,i,left,m);
        b = findMax(randArr,i,m,right);
        if (a<b)
        {
            return b;
        }else return a;
        
    }
    
    
}

void print2dArr(int r[LEN1][LEN2]){
    printf("2D Array:\n");
    for (int i = 0; i < LEN1; i++)
    {
        for (int j = 0; j < LEN2; j++)
        {
            printf("%d ",r[i][j]);
        }
        printf("\n");
        
    }
    
}

void printArray(int* p){
    printf("\nMax for each row: ");
    for (int i = 0; i < LEN1; i++)
    {
        printf("%d ",p[i]);
    }
    printf("\n");
    
}

int main(){
    int randArr[LEN1][LEN2];
    
    /* fill the array with random values */
    fillArray(randArr);

    int* peakValues = malloc(LEN1*sizeof(int));

    /* fill the peakValues array with the maximum from each row*/
    findPeakValues(peakValues,randArr);

    print2dArr(randArr);
    printArray(peakValues);

    return 0;
}