#include <iostream>
#include <cstdlib>

/*
Input: nums = [1,2,3,4]
Output: [1,3,6,10]
Explanation: Running sum is obtained as follows: [1, 1+2, 1+2+3, 1+2+3+4].
*/

using namespace std;

int* running_sum(int* nums, int size){
    int* runningSum = (int*) malloc(size*sizeof(int));
    
    for (int i = 0; i < size; i++)
    {
        runningSum[i] = 0;
        for (int j = i; j >= 0; j--)
        {
            runningSum[i] += nums[j];
        }
        
    }
    return runningSum;
    
}

int main(){
    int nums[] = {1, 2, 3, 4};
    int size = 4;
    int* runningSum = running_sum(nums, size);

    for (int i = 0; i < size; i++)
    {
        cout << runningSum[i] << " ";
    }
    cout << endl;
    
    return 0;
}