#include <iostream>

using namespace std;

class Base{
    public:
        virtual void print(){
            cout << "print base class\n";
        }

        void show(){
            cout << "show base class\n";
        }
};

class Derived: public Base{
    public:
        void print(){
            cout << "print derived class\n";
        }

        void show(){
            cout << "show derived class\n";
        }
};

int main(){
    Base* basePtr;
    Derived derived;
    basePtr = &derived;

    basePtr->print();

    basePtr->show();

    return 0;
}