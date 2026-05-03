#include<iostream>
using namespace std;

class Animals
{
public:
    void alive()
    {
        cout<<"This animal is alive."<<endl;
    }
    void eat()
    {
        cout<<"It is eating."<<endl;
    }

};
class cat : public Animals
{
public:
    void meow()
    {
        cout<<"The cat meow"<<endl;
    }

};
class dog : public Animals
{
public:
    void bark()
    {
        cout<<"The dog barks."<<endl;
    }

};
int main()
{
    cat tommy;
    dog shiro;

    tommy.alive();
    tommy.eat();
    tommy.meow();

    cout<<endl;

    shiro.alive();
    shiro.eat();
    shiro.bark();


    cout<<endl;
}
