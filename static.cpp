#include<iostream>
using namespace std;

class student
{
private:
    static int count;
public:
    student()
    {
        count++;
    }
    static void display()
    {
        cout<<"Total Students: "<<count<<endl;
    }
};
int student::count=0;

int main()
{
    student s1;
    student s2;
    student s3;
    student s4;

    student::display();

    return 0;
}
