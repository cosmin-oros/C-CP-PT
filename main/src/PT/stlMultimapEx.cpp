#include <iostream>
#include <map>
#include <iterator>

using namespace std;

int main(){
    multimap<int, int> mMap;

    mMap.insert(pair<int, int>(1, 40));
    mMap.insert(pair<int, int>(2, 10));
    mMap.insert(pair<int, int>(3, 30));
    mMap.insert(pair<int, int>(4, 20));
    mMap.insert(pair<int, int>(5, 50));

    multimap<int, int> :: iterator it;

    for (it = mMap.begin(); it != mMap.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }

    multimap<int, int> mMap2(mMap.begin(), mMap.end());

    for (it = mMap2.begin(); it != mMap2.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }
    
    mMap2.erase(mMap2.begin(), mMap2.find(2));

    for (it = mMap2.begin(); it != mMap2.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }

    return 0;
}