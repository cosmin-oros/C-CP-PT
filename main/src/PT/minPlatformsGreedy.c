#include <stdio.h>

#define N 6
#define max(a,b) (((a) < (b)) ? (a) : (b)) 

void sort(double* arr){
    int temp;
    int j;
    for (int i = 1; i < N; i++)
    {
        temp=arr[i];
        j=i-1;
        while ((temp<arr[j])&&(j>=0))
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
    
}

int findMinPlatforms(double arrival[N],double departure[N]){
    sort(arrival);
    sort(departure);

    int count=0;    //count of trains
    int minPlat=0;  //minimum platforms needed
    int i=0,j=0;

    while (i<N)
    {
        if (arrival[i]<departure[j])
        {
            minPlat = max(minPlat,++count);
            i++;
        }else{
            count--;
            j++;
        }
        
    }
    
}

int main(){
    double arrival[N] = {2.00, 2.10, 3.00, 3.20, 3.50, 5.00};
    double departure[N] = {2.30, 3.40, 3.20, 4.30, 4.00, 5.20};

    printf("The minimum platforms needed is %d\n",findMinPlatforms(arrival,departure));

    return 0;
}