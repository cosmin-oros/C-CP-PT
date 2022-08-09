#include <iostream>

using namespace std;

class Student{
    int nr;
    char name[20];
    double fee;

public:
    //constructor for the Student class
    Student(){
        cout << "Enter the stundet nr: ";
        cin >> nr;
        cout << endl << "Enter the student name: ";
        cin >> name;
        cout << endl << "Enter the fee: ";
        cin >> fee;
    }

    void display(){
        cout << endl << nr << " " << name << " " << fee << endl;
    }

};

int main(){
    Student s; // constructor gets called automatically when
               // we create the object of the class
    s.display();

    return 0;
}