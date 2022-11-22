#include <iostream>
#include <string>

class MyException {};

class Dummy {
    public:
    Dummy(std::string s) : MyName(s) { 
        PrintMsg("Created Dummy:"); 
        }
    Dummy(const Dummy& other) : MyName(other.MyName) { 
        PrintMsg("Copy created Dummy:"); 
    }
    ~Dummy() { 
        PrintMsg("Destroyed Dummy:"); 
    }
    void PrintMsg(std::string s) { 
        std::cout << s  << MyName << "\n"; 
    }
    std::string MyName;
    int level;
};

void C(Dummy d, int i) {
    std::cout << "Entering FunctionC\n";
    d.MyName = " C";
    throw MyException();

    std::cout << "Exiting FunctionC\n";
}

void B(Dummy d, int i) {
    std::cout << "Entering FunctionB\n";
    d.MyName = "B";
    C(d, i + 1);
    std::cout << "Exiting FunctionB\n";
}

void A(Dummy d, int i) {
    std::cout << "Entering FunctionA\n";
    d.MyName = " A" ;
    //  Dummy* pd = new Dummy("new Dummy"); //Not exception safe!!!
    B(d, i + 1);
    //   delete pd;
    std::cout << "Exiting FunctionA\n";
}

int main() {
    std::cout << "Entering main\n";
    try {
        Dummy d(" M");
        A(d,1);
    }catch (MyException& e) {
        std::cout << "Caught an exception of type: " << typeid(e).name() << "\n";
    }

    std::cout << "Exiting main.\n";
    char c;
    std::cin >> c;
}