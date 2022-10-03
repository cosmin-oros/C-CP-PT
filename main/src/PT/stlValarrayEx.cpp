#include <iostream>
#include <valarray>

using namespace std;

/*
    It supports element-wise mathematical operations and various forms of generalized subscript operators, slicing and indirect access.
    As compare to vectors, valarrays are efficient in certain mathematical operations than vectors also.
*/

int main(){
    valarray<int> varr1 = {10, 8, 12, 7, 19};
    valarray<int> varr2;

    // increment all elements by 5
    varr2 = varr1.apply([](int x){return x += 5;});

    for (int& x: varr2)
    {
        cout << x << " ";
    }
    cout << endl;

    cout << "Sum of varr1 = " << varr1.sum() << endl;
    cout << "Sum of varr2 = " << varr2.sum() << endl;

    return 0;
}