#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> v1;

    for (int i = 0; i < 5; i++)
    {
        v1.push_back(i);
    }

    cout << endl << "begin and end: " << endl;

    for (auto i = v1.begin(); i != v1.end(); i++)
    {
        cout << *i << " ";
    }

    cout << endl << "cbegin and cend: " << endl;

    for (auto i = v1.cbegin(); i != v1.cend(); ++i)
    {
        cout << *i << " ";
    }
    
    cout << endl << "rbegin and rend: " << endl;

    for (auto i = v1.rbegin(); i != v1.rend(); ++i)
    {
        cout << *i << " ";
    }

    cout << endl << "crbegin and crend: " << endl;

    for (auto i = v1.crbegin(); i != v1.crend(); ++i)
    {
        cout << *i << " ";
    }

    return 0;
}