#include <iostream>
#include <cstring>
using namespace std;

class Car {
private:
    char* model;
    int year;

public:
    Car(const char* m, int y) : year(y) {
        model = new char[strlen(m) + 1];
        strcpy(model, m);
    }

    Car(const Car& other) : year(other.year) {
        model = new char[strlen(other.model) + 1];
        strcpy(model, other.model);
    }

    ~Car() {
        delete[] model;
    }

    void display() {
        cout << "Model: " << model << ", Year: " << year << endl;
    }
};

int main() {
    Car c1("Toyota Supra", 2022);
    Car c2 = c1;
    c1.display();
    c2.display();
    return 0;
}
