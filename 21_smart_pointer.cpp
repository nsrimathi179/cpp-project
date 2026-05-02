#include <iostream>
using namespace std;

template <typename T>
class SmartPointer {
private:
    T* ptr;

public:
    explicit SmartPointer(T* p = nullptr) : ptr(p) {}

    SmartPointer(const SmartPointer&) = delete;
    SmartPointer& operator=(const SmartPointer&) = delete;

    SmartPointer(SmartPointer&& other) : ptr(other.ptr) {
        other.ptr = nullptr;
    }

    SmartPointer& operator=(SmartPointer&& other) {
        if (this != &other) {
            delete ptr;
            ptr = other.ptr;
            other.ptr = nullptr;
        }
        return *this;
    }

    ~SmartPointer() {
        delete ptr;
    }

    T& operator*() { return *ptr; }
    T* operator->() { return ptr; }
    T* get() { return ptr; }

    bool isNull() { return ptr == nullptr; }
};

struct Point {
    int x, y;
    Point(int x, int y) : x(x), y(y) {}
    void display() { cout << "Point(" << x << ", " << y << ")" << endl; }
};

int main() {
    SmartPointer<Point> sp(new Point(3, 7));
    sp->display();
    cout << "X: " << (*sp).x << endl;
    return 0;
}
