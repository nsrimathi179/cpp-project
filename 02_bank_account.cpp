#include <iostream>
using namespace std;

class BankAccount {
private:
    string owner;
    double balance;

public:
    BankAccount(string name, double initialBalance) : owner(name), balance(initialBalance) {}

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: $" << amount << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient funds." << endl;
        } else {
            balance -= amount;
            cout << "Withdrawn: $" << amount << endl;
        }
    }

    void checkBalance() {
        cout << owner << "'s Balance: $" << balance << endl;
    }
};

int main() {
    BankAccount acc("Alice", 1000.0);
    acc.checkBalance();
    acc.deposit(500.0);
    acc.withdraw(200.0);
    acc.checkBalance();
    acc.withdraw(2000.0);
    return 0;
}
