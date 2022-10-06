#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

#define N 1000

int* generateArr(){
	int* arr = (int*)malloc(N*sizeof(int));

	if (!arr){
		return NULL;
	}

	for (int i = N - 1; i >= 0; i--){
		arr[i] = N - i;
	}

	return arr;
}

int main(){
    int* arr = generateArr();
    vector<int> v(arr, arr+N);

    cout << "Vector before sorting: ";
    for (int i = 0; i < N; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    // sorting vector
    sort(v.begin(), v.end());
    
    cout << "Vector after sorting: ";
    for (int i = 0; i < N; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    // sorting vector in descending order
    sort(v.begin(),v.end(), greater<int>());

    cout << "Vector after sorting in descending order: ";
    for (int i = 0; i < N; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    // reversing vector
    reverse(v.begin(), v.end());

    cout << "Vector after reversing: ";
    for (int i = 0; i < N; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    cout << "Max element of the vector is: " << *max_element(v.begin(), v.end()) << endl;
    cout << "Min element of the vector is: " << *min_element(v.begin(), v.end()) << endl;
    cout << "The sum of the vector elements is: " << accumulate(v.begin(), v.end(), 0) << endl;

    return 0;
}