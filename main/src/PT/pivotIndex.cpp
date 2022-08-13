#include <iostream>

/*
Input: nums = [1,7,3,6,5,6]
Output: 3
Explanation:
The pivot index is 3.
Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
Right sum = nums[4] + nums[5] = 5 + 6 = 11
*/

using namespace std;

int pivotIndex(int* nums, int numsSize){
    int leftSum, rightSum;

    for (int i = 0; i < numsSize; i++)
    {
        leftSum = 0;
        rightSum = 0;

        for (int j = i-1; j >= 0; j++)
        {
            leftSum += nums[j];
        }
        for (int k = i+1; k < numsSize; k++)
        {
            rightSum += nums[k];
        }
        
        if (leftSum == rightSum)
        {
            return i;
        }
        
    }

    return -1;
}

int main(){
    int nums[] = {1, 7, 3, 6, 5, 6};
    int size = 6;
    cout << pivotIndex(nums, size) << endl; 

    return 0;
}