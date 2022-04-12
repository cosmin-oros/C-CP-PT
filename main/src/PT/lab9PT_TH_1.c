#include <stdio.h>

/*
 * Divide and conquer method for finding
 * a local minimum from the array
 */

#define N 10

int localMin(int elem[N],int i,int j){
    int m = (i+j)/2;
    if ((elem[m-1]>=elem[m])&&
            elem[m]<=elem[m+1])
    {
        printf("Local minimum: %d\n",elem[m]);
        return m;
    }
    else if (elem[m-1]<elem[m])
    {
        return localMin(elem,i,m-1);
    }
    else if (elem[m]>elem[m+1])
    {
        return localMin(elem,m+1,j);
    }
    
}

int main(){
    int elements[N] = {2,7,3,4,1,9,12,6,5,0};
    localMin(elements,0,N);
}