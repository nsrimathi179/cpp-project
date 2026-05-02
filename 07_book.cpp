#include <iostream>
using namespace std;

class Book {
private:
    string title;
    string author;
    double price;

public:
    Book(string t, string a, double p) : title(t), author(a), price(p) {}

    friend ostream& operator<<(ostream& os, const Book& b) {
        os << "Title: " << b.title << ", Author: " << b.author << ", Price: $" << b.price;
        return os;
    }
};

int main() {
    Book b1("The Pragmatic Programmer", "Andy Hunt", 45.99);
    Book b2("Clean Code", "Robert Martin", 39.99);
    cout << b1 << endl;
    cout << b2 << endl;
    return 0;
}
