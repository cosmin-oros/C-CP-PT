#include <iostream>

/*
    In the Factory pattern, we create objects without exposing the creation logic to the client and the client uses the same common interface to create a new type of object.
*/

enum VehicleType {
    VT_TwoWheeler,    VT_ThreeWheeler,    VT_FourWheeler
};

class Vehicle {
public:
    virtual void printVehicle() = 0;
    static Vehicle* Create(VehicleType type);
    virtual ~Vehicle(){}
};

class TwoWheeler : public Vehicle {
public:
    void printVehicle() {
        std::cout << "I am two wheeler\n";
    }
};

class ThreeWheeler : public Vehicle {
public:
    void printVehicle() {
        std::cout << "I am three wheeler\n";
    }
};

class FourWheeler : public Vehicle {
    public:
    void printVehicle() {
        std::cout << "I am four wheeler\n";
    }
};

Vehicle* Vehicle::Create(VehicleType type){
    if (type == VT_TwoWheeler)
    {
        return new TwoWheeler();
    }else if (type == VT_ThreeWheeler)
    {
        return new ThreeWheeler();
    }else if (type == VT_FourWheeler)
    {
        return new FourWheeler();
    }else{
        return NULL;
    }
    
    
    
}

class Client{
public:
    Client(){
        VehicleType type = VT_ThreeWheeler;
        pVehicle = Vehicle::Create(type);
    }
    ~Client(){
        if (pVehicle)
        {
            delete pVehicle;
            pVehicle = NULL;
        }
        
    }
    Vehicle* getVehicle()  {
        return pVehicle;
    }

private:
    Vehicle* pVehicle;
};

int main(){
    Client *pClient = new Client();
    Vehicle * pVehicle = pClient->getVehicle();
    pVehicle->printVehicle();
    delete pClient;

    return 0;
}