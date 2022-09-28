#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
    C++ has a class in its STL algorithms library which allows us easy partition algorithms using certain inbuilt functions.
    Partition refers to act of dividing elements of containers depending upon a given condition. 
    Partition operations :
    1. partition(beg, end, condition) :- This function is used to partition the elements on basis of condition mentioned in its arguments.
    2. is_partitioned(beg, end, condition) :- This function returns boolean true if container is partitioned else returns false.
*/

int main(){
    vector<int> vect = {2, 1, 5, 6, 8, 7};

    is_partitioned(vect.begin(), vect.end(), [](int x)
    {
        return x % 2 == 0;
    })?
    cout << "Vector is partitioned" : cout << "Vector is not partitioned";
    cout << endl;

    partition(vect.begin(), vect.end(), [](int x)
    {
        return x % 2 == 0;
    });

    is_partitioned(vect.begin(), vect.end(), [](int x)
    {
        return x%2==0;
         
    })?
    cout << "Now, vector is partitioned after partition operation" : cout << "Vector is still not partitioned after partition operation";
    cout << endl;

    cout << "The partitioned vector is : ";
    for (int &x : vect){
        cout << x << " ";
    }
    
    return 0;
}