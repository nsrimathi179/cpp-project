#include <iostream>
#include <cmath>
using namespace std;

class Shape {
public:
    virtual double area() = 0;
    virtual void display() = 0;
    virtual ~Shape() {}
};

class Triangle : public Shape {
private:
    double base, height;

public:
    Triangle(double b, double h) : base(b), height(h) {}

    double area() override {
        return 0.5 * base * height;
    }

    void display() override {
        cout << "Triangle area: " << area() << endl;
    }
};

class Rectangle : public Shape {
private:
    double length, width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double area() override {
        return length * width;
    }

    void display() override {
        cout << "Rectangle area: " << area() << endl;
    }
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double area() override {
        return M_PI * radius * radius;
    }

    void display() override {
        cout << "Circle area: " << area() << endl;
    }
};

int main() {
    Shape* shapes[] = { new Triangle(5, 8), new Rectangle(4, 6), new Circle(3) };
    for (Shape* s : shapes) {
        s->display();
        delete s;
    }
    return 0;
}
