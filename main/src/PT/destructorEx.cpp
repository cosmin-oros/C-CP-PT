#include <iostream>

using namespace std;

class Test{
    public:
        Test(){
            cout << "Constructor" << endl;
        }

        ~Test(){
            cout << "Destructor" << endl;
        }
};

int main(){
    Test test1, test2, test3;

    return 0;
}