#include <iostream>

using namespace std;

//works for all data types

template <typename T> T myMax(T x, T y){
    return (x > y) ? x : y;
}

int main(){
    cout << myMax<int>(3, 10) << endl;
    cout << myMax<double>(3.2, 4.6) << endl;
    cout << myMax<char>('c', 'd') << endl;

    return 0;
}