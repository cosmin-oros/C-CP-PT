#include <iostream>
#include <unordered_map>
#include <climits>

using namespace std;

/*
    Given an array of size N with repeated numbers, You Have to Find the top three repeated numbers. 

    Input : arr[] = {3, 4, 2, 3, 16, 3, 15, 16, 15, 15, 16, 2, 3} 
    Output : Three largest elements are 3 16 15 
    Explanation : Here, 3 comes 4 times, 16 comes 3 times, 15 comes 3 times.
*/

void top3Repeated(int arr[], int n){
    if (n <= 3)
    {
        for (int i = 0; i < n; i++)
        {
            cout << arr[i];
        }
        cout << endl;

        return;
    }

    unordered_map<int, int> freq;
    
    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }

    pair<int, int> x, y, z;
    x.first = y.first = z.first = INT_MIN;

    for (auto curr : freq){
        if (curr.second > x.first) {
 
            // Update second and third largest
            z = y;
            y = x;
 
            // Modify values of x Number
            x.first = curr.second;
            x.second = curr.first;
        }else if (curr.second > y.first) {
 
            // Modify values of third largest
            z = y;
 
            // Modify values of second largest
            y.first = curr.second;
            y.second = curr.first;
        }else if (curr.second > z.first) {
 
            // Modify values of z Number
            z.first = curr.second;
            z.second = curr.first;
        }
    }

    cout << x.second << " " << y.second << " " << z.second << endl;
    
    
}

int main(){
    int arr[] = {3, 4, 2, 3, 16, 3, 15, 16, 15, 15, 16, 2, 3};
    
    int n = sizeof(arr) / sizeof(arr[0]);
    
    top3Repeated(arr, n);

    return 0;
}