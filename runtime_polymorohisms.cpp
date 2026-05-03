#include<iostream>
using namespace std;
class base
{
public:
    virtual void display()
    {
        cout<<"This is base class"<<endl;
    }
};
class derived : public base
{
public:
    void display() override
    {
        cout<<"This is derived class"<<endl;
    }
};
int main()
{
base *ptr;
derived obj;
ptr = &obj;
ptr->display();

return 0;

}

