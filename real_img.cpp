#include<iostream>
using namespace std;

class num
{
public:
    int real;
    int img;

    num()
    {
        real=0;
        img=0;
    }
    num(int real,int img)
    {
        this->real = real;
        this->img = img;
    }
    void display()
    {
        cout<<"["<<real<<","<<img<<"i"<<"]"<<endl;
    }
friend num operator + (num n);
};
    num operator + (num n,num m)
    {
        num obj;
        obj.real=m.real + n.real;
        obj.img=m.img + n.img;
        return obj;
    }
int main()
{
    num n1(3,5);
    n1.display();

    num n2(7,9);
    n2.display();

    num n3=n1+n2;
    n3.display();

    return 0;

}
