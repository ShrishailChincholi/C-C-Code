#include <iostream>
using namespace std;

class BankAccount {
private:
    int accNo;
    float balance;

public:
    
    BankAccount(int a, float b) {
        accNo = a;
        balance = b;
    }

  
    void deposit(float amount) {
        balance += amount;
        cout << "Amount Deposited: " << amount << endl;
    }

    void withdraw(float amount) {
        if (amount > balance) {
            cout << "Insufficient Balance!" << endl;
        } else {
            balance -= amount;
            cout << "Amount Withdrawn: " << amount << endl;
        }
    }