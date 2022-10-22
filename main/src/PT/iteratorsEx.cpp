#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int main(){
    vector<int> arr1 = {1, 2, 3, 4, 5};
    vector<int> arr2 = {4, 2, 2, 1, 6};

    // iterator to a vector
    vector<int> :: iterator it = arr1.begin();

    // use advance to set position
    advance(it, 3);

    // inserts arr2 in arr1 after iterator
    copy(arr2.begin(), arr2.end(), inserter(arr1, it));

    cout << "vector: " << endl;
    for (int &x : arr1){
        cout << x << " ";
    }
    cout << endl;

    vector<int> v1 = { 10, 20, 30, 40, 50 };
 
    // Declaring an iterator
    vector<int> :: iterator i1;
 
    for (i1 = v1.begin(); i1 != v1.end(); ++i1) {
        // Assigning values to locations pointed by iterator
        *i1 = 7;
    }
 
    for (i1 = v1.begin(); i1 != v1.end(); ++i1) {
        // Accessing values at locations pointed by iterator
        cout << (*i1) << " ";
    }
    cout << endl;

    return 0;
}