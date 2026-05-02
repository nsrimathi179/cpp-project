#include <iostream>
#include <stdexcept>
using namespace std;

enum class Type { INT, DOUBLE, STRING };

class Variant {
private:
    Type type;
    union {
        int iVal;
        double dVal;
    };
    string sVal;

public:
    Variant(int v) : type(Type::INT), iVal(v) {}
    Variant(double v) : type(Type::DOUBLE), dVal(v) {}
    Variant(const string& v) : type(Type::STRING), sVal(v) {}

    int asInt() {
        if (type != Type::INT) throw runtime_error("Not an int");
        return iVal;
    }

    double asDouble() {
        if (type != Type::DOUBLE) throw runtime_error("Not a double");
        return dVal;
    }

    string asString() {
        if (type != Type::STRING) throw runtime_error("Not a string");
        return sVal;
    }

    void display() {
        switch (type) {
            case Type::INT:    cout << "int: " << iVal << endl; break;
            case Type::DOUBLE: cout << "double: " << dVal << endl; break;
            case Type::STRING: cout << "string: " << sVal << endl; break;
        }
    }
};

int main() {
    Variant v1(42);
    Variant v2(3.14);
    Variant v3(string("hello"));

    v1.display();
    v2.display();
    v3.display();

    cout << "Int value: " << v1.asInt() << endl;

    try {
        v1.asDouble();
    } catch (exception& e) {
        cout << "Error: " << e.what() << endl;
    }
    return 0;
}
