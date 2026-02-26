#include <iostream>
using namespace std;

class BankAccount
{
private:
    int accNo;
    float balance;

public:

    BankAccount(int a, float b)
    {
        accNo = a;
        balance = b;
    }

    void deposit(float amount)
    {
        balance += amount;
        cout << "Amount Deposited: " << amount << endl;
    }

    void withdraw(float amount)
    {
        if (amount > balance)
        {
            cout << "Insufficient Balance!" << endl;
        }
        else
        {
            balance -= amount;
            cout << "Amount Withdrawn: " << amount << endl;
        }
    }

    void display()
    {
        cout << "Account No: " << accNo << endl;
        cout << "Balance   : " << balance << endl;
    }
};

int main()
{
    BankAccount acc1(1001, 5000); 

    acc1.display();
    acc1.deposit(2000);
    acc1.withdraw(3000);
    acc1.display();

    return 0;
}


// Output:---
// Account No: 1001
// Balance   : 5000
// Amount Deposited: 2000
// Amount Withdrawn: 3000
// Account No: 1001
// Balance   : 4000