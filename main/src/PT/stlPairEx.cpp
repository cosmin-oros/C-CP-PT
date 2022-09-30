#include <iostream>
#include <utility>

using namespace std;

int main(){
    pair<int, double> Pair1;
    pair<string, char> Pair2;
    
    // initialized to 0
    cout << Pair1.first << " " << Pair1.second;

    // it prints nothing because it is initialized to NULL
    cout << Pair2.first << " " << Pair2.second;

    pair<char, int> pair1 = make_pair('A', 1);
    pair<char, int> pair2 = make_pair('B', 2);
  
    cout << "Before swapping:\n ";
    cout << "\nContents of pair1 = " << pair1.first << " " << pair1.second;
    cout << "\nContents of pair2 = " << pair2.first << " " << pair2.second;
    pair1.swap(pair2);
  
    cout << "\nAfter swapping:\n ";
    cout << "\nContents of pair1 = " << pair1.first << " " << pair1.second;
    cout << "\nContents of pair2 = " << pair2.first << " " << pair2.second;

    return 0;
}