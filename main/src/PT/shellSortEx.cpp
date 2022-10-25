#include <iostream>

#define N 10

void shellSort(int* arr){
    int i, j, step, s;
    int temp;
    int m;

    for (m = 1; m < N; m++)
    {
        step = arr[m-1];
        s = -step;

        for (i = step+1; i <= N; i++)
        {
            temp= arr[i]; j= i-step;
            if (s==0)
            s= -step;
            s= s+1;
            arr[s]= temp; 
            // while (temp.key<arr[j].key)
            // {
            //     a[j+step]= a[j];
            //     j= j-step; 
            // } 
            // arr[j+step]= temp;
        }
        
    }
    

}

void printArr(int* arr){
    for (int i = 0; i < N; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
    
}

int main(){
    int arr[N] = {4, 7, 12, 4, 5, 9, 1, 10, 2, 3};
    
    shellSort(arr);
    printArr(arr);

    return 0;
}