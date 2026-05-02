#include <iostream>
using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

class Fraction {
private:
    int numerator, denominator;

    void simplify() {
        int g = gcd(abs(numerator), abs(denominator));
        numerator /= g;
        denominator /= g;
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

public:
    Fraction(int n, int d) : numerator(n), denominator(d) {
        simplify();
    }

    Fraction operator+(const Fraction& f) {
        return Fraction(numerator * f.denominator + f.numerator * denominator,
                        denominator * f.denominator);
    }

    Fraction operator-(const Fraction& f) {
        return Fraction(numerator * f.denominator - f.numerator * denominator,
                        denominator * f.denominator);
    }

    Fraction operator*(const Fraction& f) {
        return Fraction(numerator * f.numerator, denominator * f.denominator);
    }

    Fraction operator/(const Fraction& f) {
        return Fraction(numerator * f.denominator, denominator * f.numerator);
    }

    void display() {
        cout << numerator << "/" << denominator << endl;
    }
};

int main() {
    Fraction f1(1, 2);
    Fraction f2(1, 3);
    cout << "Sum: ";     (f1 + f2).display();
    cout << "Diff: ";    (f1 - f2).display();
    cout << "Product: "; (f1 * f2).display();
    cout << "Quotient: ";(f1 / f2).display();
    return 0;
}
