#include <iostream>
#include <forward_list>

using namespace std;

/*
    Forward List is preferred over the list when only forward traversal is required (same as the singly linked list is preferred over doubly linked list) as we can save space.
*/

int main(){
    forward_list<int> fList = {1, 2, 3, 4, 5, 6};

    // insert at the front
    fList.push_front(7);

    cout << "Forward list: ";
    for (int& c: fList){
        cout << c << " ";
    }
    cout << endl;

    // delete first value 
    fList.pop_front();

    cout << "Forward list: ";
    for (int& c: fList){
        cout << c << " ";
    }
    cout << endl;

    fList.assign({10, 20, 30});

    cout << "Forward list: ";
    for (int& c: fList){
        cout << c << " ";
    }
    cout << endl;

    forward_list<int> :: iterator it;
    
    // inserting values from second position
    it = fList.insert_after(fList.begin(), {7, 3, 9});

    cout << "Forward list: ";
    for (int& c: fList){
        cout << c << " ";
    }
    cout << endl;

    // delete after the pointer
    it = fList.erase_after(it);

    cout << "Forward list: ";
    for (int& c: fList){
        cout << c << " ";
    }
    cout << endl;

    // delete values in a range
    it = fList.erase_after(fList.begin(), fList.end());

    cout << "Forward list: ";
    for (int& c: fList){
        cout << c << " ";
    }
    cout << endl;

    // clear the forward list
    fList.clear();

    cout << "Forward list: ";
    for (int& c: fList){
        cout << c << " ";
    }
    cout << endl;

    return 0;
}