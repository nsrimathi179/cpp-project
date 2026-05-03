//encapsulation bankaccount promblem

#include<iostream>
using namespace std;
class Bankaccount
{
  private:
  float balance;

  public:
  void setBalance(float b)
  {
    balance = b;
  }
  void deposit(float amount)
  {
    balance = balance + amount;
  }
  void withdraw(float amount){
    if(amount<=balance)
      balance = balance - amount;
    else
      cout<<"balance insufficient"<<endl;
}
void getbalance()
    {
        cout<<"Current data: "<<balance<<endl;
    }

};
int main()
{
    Bankaccount b;
    b.setBalance(1000);
    b.deposit(500);
    b.withdraw(200);
    b.getbalance();

}
