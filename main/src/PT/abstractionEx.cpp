#include <iostream>

using namespace std;

class Abstraction{
    private:
        int a, b;
    public:
        void set(int x, int y){
            a = x;
            b = y;
        }

        void display(){
            cout << a << endl << b << endl;
        }
};

int main(){
    Abstraction object;
    object.set(100, 200);
    object.display();

    return 0;
}