#include <iostream>
using namespace std;

class Vehicle {
protected:
    string brand;

public:
    Vehicle(string b) : brand(b) {}
    virtual double fuelEfficiency() = 0;
    virtual void display() {
        cout << "Brand: " << brand << ", Fuel Efficiency: " << fuelEfficiency() << " mpg" << endl;
    }
    virtual ~Vehicle() {}
};

class Car : public Vehicle {
public:
    Car(string b) : Vehicle(b) {}
    double fuelEfficiency() override { return 35.0; }
};

class Truck : public Vehicle {
public:
    Truck(string b) : Vehicle(b) {}
    double fuelEfficiency() override { return 18.0; }
};

class Motorcycle : public Vehicle {
public:
    Motorcycle(string b) : Vehicle(b) {}
    double fuelEfficiency() override { return 55.0; }
};

int main() {
    Vehicle* vehicles[] = {
        new Car("Toyota"),
        new Truck("Ford"),
        new Motorcycle("Harley-Davidson")
    };

    for (Vehicle* v : vehicles) {
        v->display();
        delete v;
    }
    return 0;
}
