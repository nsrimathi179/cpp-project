#include <iostream>
using namespace std;

class Flying {
public:
    void fly() {
        cout << "Flying through the air!" << endl;
    }
};

class Swimming {
public:
    void swim() {
        cout << "Swimming through the water!" << endl;
    }
};

class Duck : public Flying, public Swimming {
private:
    string name;

public:
    Duck(string n) : name(n) {}

    void quack() {
        cout << name << " says: Quack!" << endl;
    }

    void display() {
        cout << name << " can:" << endl;
        fly();
        swim();
        quack();
    }
};

int main() {
    Duck d("Donald");
    d.display();
    return 0;
}
