#include <iostream>

using namespace std;

class Encapsulation{
    private:
        //data hidden from outside of the class
        int x;
    public:
        void set(int a){
            x = a;
        }

        int get(){
            return x;
        }

};

int main(){
    Encapsulation object;
    object.set(10);

    cout << object.get() << endl;

    return 0;
}