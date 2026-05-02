#include <iostream>
#include <cmath>
using namespace std;

class Circle {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double area() {
        return M_PI * radius * radius;
    }

    double circumference() {
        return 2 * M_PI * radius;
    }

    void display() {
        cout << "Radius: " << radius << endl;
        cout << "Area: " << area() << endl;
        cout << "Circumference: " << circumference() << endl;
    }
};

int main() {
    Circle c(7.0);
    c.display();
    return 0;
}
