#include <iostream>
#include <set>

using namespace std;

int main(){
    set<int, greater<int>> s;

    s.insert(5);
    s.insert(2);
    s.insert(4);
    s.insert(5);
    s.insert(3);
    s.insert(9);

    set<int, greater<int>> :: iterator it;

    for (it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    // assign elements from s to s2
    set<int> s2(s.begin(), s.end());

    for (it = s2.begin(); it != s2.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    
    // remove all elements up to 5
    s2.erase(s2.begin(), s2.find(5));

    for (it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}