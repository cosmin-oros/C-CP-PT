#include <iostream>
#include <list>

using namespace std;

/*
    To insert multiple elements at once in a list.
    syntax : list.assign(number of times, element).
    To copy elements of 1 list into another.
    syntax : list.assign(lis2.begin(),lis2.end())
    To copy array elements into list.
    syntax : list.assign(arr,arr+size).
*/

int main(){
    list<int> list1;
    list<int> list2;
    list<int> list3;

    int arr[10] = {1, 2, 3, 4};

    // add 4 occurances of 2
    list1.assign(4, 2);

    cout << "The list after inserting multiple elements is : ";
    for (list<int>::iterator i = list1.begin(); i != list1.end(); i++){
       cout << *i << " ";
    }
    cout << endl;

    // copy elements
    list2.assign(list1.begin(), list1.end());

    cout << "The list after inserting multiple elements is : ";
    for (list<int>::iterator i = list2.begin(); i != list2.end(); i++){
       cout << *i << " ";
    }
    cout << endl;

    // copy elements from array
    list3.assign(arr, arr+4);

    cout << "The list after inserting multiple elements is : ";
    for (list<int>::iterator i = list3.begin(); i != list3.end(); i++){
       cout << *i << " ";
    }
    cout << endl;
    
    return 0;
}