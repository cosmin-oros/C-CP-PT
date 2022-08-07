#include <iostream>

using namespace std;

class Poly{
    public:
        void display(int x){
            cout << x << endl;
        }

        void display(double x){
            cout << x << endl;
        }

        void display(int x, int y){
            cout << x << endl << y << endl;
        }
};

int main(){
    Poly object;
    object.display(1);
    object.display(1.01);
    object.display(2, 3);

    return 0;
}