#include <iostream>
using namespace std;

class BankAccount
{
private:
    int accNumber;
    string accHolderName;
    double balance;

public:
    // Constructor
    BankAccount(int num, string name, double bal)
    {
        accNumber = num;
        accHolderName = name;
        balance = bal;
    }
    BankAccount operator+(double amount)
    {
        balance = balance + amount;
        cout << "Amount Deposited: " << amount << endl;
        return *this;
    }
    BankAccount operator-(double amount)
    {
        if (balance - amount >= 0)
        {
            balance = balance - amount;
            cout << "Amount Withdrawn: " << amount << endl;
        }
        else
        {
            cout << "Withdrawal not allowed." << endl;
        }
        return *this;
    }


    friend int operator==(BankAccount a1, BankAccount a2);


    void display()
    {
        cout << "Account Number: " << accNumber << endl;
        cout << "Account Holder: " << accHolderName << endl;
        cout << "Balance: " << balance << endl;

    }
};


int operator==(BankAccount a1, BankAccount a2)
{
    if (a1.balance == a2.balance)
        return 1;
    else
        return 0;
}
int main()
{
    BankAccount acc1(101, "srimathi", 5000);
    BankAccount acc2(102, "priya", 3000);

    cout << "Initial Details:\n";
    acc1.display();
    acc2.display();

    // Deposit using + operator
    acc1 = acc1 + 2000;

    // Withdraw using - operator
    acc2 = acc2 - 1000;

    cout << "\nAfter Transactions:\n";
    acc1.display();
    acc2.display();

    // Compare balances
    if (acc1 == acc2)
        cout << "Both accounts have equal balance." << endl;
    else
        cout << "Balances are not equal." << endl;

    return 0;
}
//Requirements:
//Overload the + operator to deposit an amount into the account.
//Overload the - operator to withdraw an amount (do not allow negative balance).
//Overload the == operator to compare two accounts based on balance.
//Display balance amount
//Tasks:
//Implement all overloaded operators (atleast one using friend functions)
//Demonstrate the operations in the main() function.
