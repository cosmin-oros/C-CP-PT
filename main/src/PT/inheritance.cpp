#include <iostream>

using namespace std;

class Person{
    int id;
    char name[20];

    public:
        void set(){
            cout << "Enter the id: ";
            cin >> id;
            cout << endl << "Enter the name: ";
            cin >> name;
        }

        void display(){
            cout << endl << id << " " << name;
        }

};

class Student: private Person{
    int fee;
    char course[10];

    public:
        void setStudent(){
            set();
            cout << "Enter the course name: ";
            cin >> course;
            cout << "Enter the fee: ";
            cin >> fee;
        }

        void displayStudent(){
            display();
            cout << " " << course << " " << fee << endl;
        }
};

int main(){
    Student student1;
    student1.setStudent();
    student1.displayStudent();

    return 0;
}