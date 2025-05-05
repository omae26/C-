// simple bank account in c++
#include <iostream>
using namespace std;

// Class representing a bank account
class BankAccount {
private:
    double balance; // Private member variable to store the account balance
public:
    // Constructor to initialize the account balance
    BankAccount(double b) { balance = b; }

    // Method to deposit money into the account
    void deposit(double amount) {
        if (amount > 0) // Ensure the deposit amount is positive
            balance += amount;
    }

    // Method to withdraw money from the account
    void withdraw(double amount) {
        if (amount <= balance) // Ensure sufficient balance for withdrawal
            balance -= amount;
    }

    // Method to display the current account balance
    void display() { 
        cout << "Balance: $" << balance << endl; 
    }
};

int main() {
    // Create a BankAccount object with an initial balance of $1000
    BankAccount acc(1000);

    // Deposit $500 into the account
    acc.deposit(500);

    // Withdraw $200 from the account
    acc.withdraw(200);

    // Display the current balance
    acc.display(); // Output: Balance: $1300

    return 0; // Indicate successful program termination
}