#include <iostream>

using namespace std;

int removeDuplicates(int* nums, int numsSize){
    for(int i=1; i < numsSize; i++){
        if(nums[i] == nums[i-1]){
            for(int j = i; j < numsSize; j++){
                nums[j] = nums[j+1];
            }
            numsSize--;
        }
    }
    return numsSize;

}

int main(){
    int nums[] = {1, 1, 2, 3, 3, 4};
    int numsSize = 6;

    cout << removeDuplicates(nums, numsSize) << endl;

    return 0;
}