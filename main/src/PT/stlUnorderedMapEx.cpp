#include <iostream>
#include <unordered_map>

using namespace std;

int main(){
    unordered_map<string, double> map;

    map["grade1"] = 10.0;
    map["grade2"] = 4.7;
    map["grade3"] = 6.9;
    map["grade4"] = 8.4;

    map.insert(make_pair("grade5", 7.7));

    string key = "grade4";

    if (map.find(key) == map.end())
    {
        cout << key << " not found" << endl;
    }else{
        cout << key << " found" << endl;
    }

    unordered_map<string, double> :: iterator it;

    cout << "Elements of the map: " << endl;
    for (it = map.begin(); it != map.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }
    

    return 0;
}