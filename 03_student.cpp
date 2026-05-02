#include <iostream>
using namespace std;

class Student {
private:
    string name;
    int rollNumber;
    double marks;

public:
    Student(string n, int roll, double m) : name(n), rollNumber(roll), marks(m) {}

    string getGrade() {
        if (marks >= 90) return "A+";
        else if (marks >= 80) return "A";
        else if (marks >= 70) return "B";
        else if (marks >= 60) return "C";
        else if (marks >= 50) return "D";
        else return "F";
    }

    void display() {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Marks: " << marks << endl;
        cout << "Grade: " << getGrade() << endl;
    }
};

int main() {
    Student s1("John", 101, 85.5);
    Student s2("Jane", 102, 42.0);
    s1.display();
    cout << "---" << endl;
    s2.display();
    return 0;
}
