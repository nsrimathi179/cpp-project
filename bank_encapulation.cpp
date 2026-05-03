#include <iostream>
using namespace std;

class BankAccount {
private:
    double balance;   // hidden data

public:
    // Set initial balance
    void setBalance(double b) {
        balance = b;
    }

    // Deposit money
    void deposit(double amount) {
        balance = balance + amount;
    }

    // Withdraw money
    void withdraw(double amount) {
        if(amount <= balance)
            balance = balance - amount;
        else
            cout << "Insufficient balance" << endl;
    }

    // Display balance
    void getBalance() {
        cout << "Current Balance: " << balance << endl;
    }
};

int main() {
    BankAccount acc;

    acc.setBalance(1000);
    acc.deposit(500);
    acc.withdraw(300);
    acc.getBalance();

    return 0;
}

example code for encapsulation

