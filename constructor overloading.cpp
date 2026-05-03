#include<iostream>
using namespace std;
class pizza
{
public:
    string topping1;
    string topping2;

    pizza()
    {


    }
    pizza(string topping1)
    {
      this->topping1 = topping1;
    }
    pizza(string topping1,string topping2)
    {
      this->topping1 = topping1;
      this->topping2 = topping2;
    }

};
int main()
{
    pizza pizza1("chicken");
    pizza pizza2("panner","pork");
    pizza pizza3;

    cout<<pizza1.topping1<<endl;
    cout<<pizza2.topping1<<endl;
    cout<<pizza2.topping2<<endl;


    return 0;


}
