#include<iostream>
using namespace std;
class vector
{

public:
    int x;
    int y;
    vector()
    {
        x=0;
        y=0;
    }
    vector(int x,int y)
    {
        this->x = x;
        this->y = y;
    }
    vector operator +(vector v)
    {
        vector obj;
        obj.x = x + v.x;
        obj.y = y + v.y;
        return obj;

    }

    void display()
    {
        cout<< "(" <<x<< "," <<y<< ")" << endl;

    }
    friend vector operator *(vector n);

};
    vector operator *(vector n,vector m)
    {
        vector obj;
        obj.x = m.x * n.x;
        obj.y = m.y * n.y;
        return obj;
    }

int main()
{
    vector v1(2,3);
    v1.display();


    vector v2(4,5);
    v2.display();

    vector v3=v1+v2;
    v3.display();



    return 0;



}
