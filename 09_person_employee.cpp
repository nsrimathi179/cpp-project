#include <iostream>
using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    Person(string n, int a) : name(n), age(a) {}

    virtual void display() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

class Employee : public Person {
private:
    string company;
    double salary;

public:
    Employee(string n, int a, string c, double s)
        : Person(n, a), company(c), salary(s) {}

    void display() override {
        Person::display();
        cout << "Company: " << company << ", Salary: $" << salary << endl;
    }
};

int main() {
    Person p("Alice", 30);
    Employee e("Bob", 28, "TechCorp", 85000);
    p.display();
    cout << "---" << endl;
    e.display();
    return 0;
}
