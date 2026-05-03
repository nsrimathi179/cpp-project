#include<iostream>
using namespace std;
class circle{
public:
  int setArea(int l,int b){
  return l*b;
}

  int setArea(int l){
    return 3.14*l*l;
    }

};

int main()
{
    circle c;
    cout<<"area of circle:"<<c.setArea(3)<<endl;
    cout<<"area of rectangle:"<<c.setArea(3,4)<<endl;
}
