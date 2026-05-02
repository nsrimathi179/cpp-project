#include <iostream>
using namespace std;

class Temperature {
private:
    double celsius;

public:
    Temperature(double c) : celsius(c) {}

    double toCelsius() {
        return celsius;
    }

    double toFahrenheit() {
        return (celsius * 9.0 / 5.0) + 32;
    }

    double toKelvin() {
        return celsius + 273.15;
    }

    void display() {
        cout << "Celsius: " << toCelsius() << endl;
        cout << "Fahrenheit: " << toFahrenheit() << endl;
        cout << "Kelvin: " << toKelvin() << endl;
    }
};

int main() {
    Temperature t(100.0);
    t.display();
    return 0;
}
