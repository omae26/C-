#include <iostream>
#include <string>
using namespace std;

int main() {
    string pin = "1234";          // Default PIN
    string enteredPin;
    double balance = 10000.0;     // Starting balance
    int choice;

    // Welcome Screen
    cout << "==============================" << endl;
    cout << "      Welcome to M-PESA      " << endl;
    cout << "==============================" << endl;

    // PIN verification
    cout << "Enter your M-PESA PIN: ";
    cin >> enteredPin;

    if (enteredPin == pin) {
        do {
            // Main Menu
            cout << "\n--------- M-PESA MENU ---------" << endl;
            cout << "1. Send Money" << endl;
            cout << "2. Withdraw Cash" << endl;
            cout << "3. Buy Airtime" << endl;
            cout << "4. Loans & Savings" << endl;
            cout << "5. Lipa na M-PESA" << endl;
            cout << "6. My Account" << endl;
            cout << "7. Exit" << endl;
            cout << "Select an option (1-7): ";
            cin >> choice;

            // Send Money
            if (choice == 1) {
                string number;
                double amount;
                cout << "Enter recipient phone number: ";
                cin >> number;
                cout << "Enter amount to send: ";
                cin >> amount;

                if (amount > 0) {
                    if (amount <= balance) {
                        balance -= amount;
                        cout << "Successfully sent Ksh " << amount << " to " << number << "." << endl;
                        cout << "New Balance: Ksh " << balance << endl;
                    } else {
                        cout << "Error: Insufficient balance!" << endl;
                    }
                } else {
                    cout << "Error: Invalid amount entered!" << endl;
                }

            // Withdraw Cash
            } else if (choice == 2) {
                string agent;
                double amount;
                cout << "Enter Agent Number: ";
                cin >> agent;
                cout << "Enter amount to withdraw: ";
                cin >> amount;

                if (amount > 0) {
                    if (amount <= balance) {
                        balance -= amount;
                        cout << "Withdrawn Ksh " << amount << " from agent " << agent << "." << endl;
                        cout << "New Balance: Ksh " << balance << endl;
                    } else {
                        cout << "Error: Insufficient balance!" << endl;
                    }
                } else {
                    cout << "Error: Invalid amount!" << endl;
                }

            // Buy Airtime
            } else if (choice == 3) {
                double airtime;
                cout << "Enter amount of airtime to buy: ";
                cin >> airtime;

                if (airtime > 0) {
                    if (airtime <= balance) {
                        balance -= airtime;
                        cout << "Airtime of Ksh " << airtime << " purchased successfully." << endl;
                        cout << "New Balance: Ksh " << balance << endl;
                    } else {
                        cout << "Error: Insufficient balance!" << endl;
                    }
                } else {
                    cout << "Error: Invalid amount!" << endl;
                }

            // Loans & Savings
            } else if (choice == 4) {
                int subChoice;
                cout << "\n--- Loans & Savings ---" << endl;
                cout << "1. Request Loan" << endl;
                cout << "2. Check Loan Limit" << endl;
                cout << "Select option: ";
                cin >> subChoice;

                if (subChoice == 1) {
                    double loan;
                    cout << "Enter loan amount to request: ";
                    cin >> loan;
                    if (loan > 0) {
                        balance += loan;
                        cout << "Loan of Ksh " << loan << " approved and added to your balance." << endl;
                        cout << "New Balance: Ksh " << balance << endl;
                    } else {
                        cout << "Error: Invalid loan amount!" << endl;
                    }
                } else if (subChoice == 2) {
                    cout << "Your current loan limit is: Ksh 5,000" << endl;
                } else {
                    cout << "Invalid option under Loans & Savings." << endl;
                }

            // Lipa na M-PESA
            } else if (choice == 5) {
                int subChoice;
                cout << "\n--- Lipa na M-PESA ---" << endl;
                cout << "1. Paybill" << endl;
                cout << "2. Buy Goods" << endl;
                cout << "Select option: ";
                cin >> subChoice;

                string tillOrBusiness;
                double amount;
                if (subChoice == 1) {
                    cout << "Enter Business Number: ";
                    cin >> tillOrBusiness;
                    cout << "Enter amount to pay: ";
                    cin >> amount;

                } else if (subChoice == 2) {
                    cout << "Enter Till Number: ";
                    cin >> tillOrBusiness;
                    cout << "Enter amount to pay: ";
                    cin >> amount;

                } else {
                    cout << "Invalid option under Lipa na M-PESA." << endl;
                    continue;
                }

                if (amount > 0 && amount <= balance) {
                    balance -= amount;
                    cout << "Payment of Ksh " << amount << " made successfully to " << tillOrBusiness << "." << endl;
                    cout << "New Balance: Ksh " << balance << endl;
                } else {
                    cout << "Error: Invalid or insufficient amount!" << endl;
                }

            // My Account Section
            } else if (choice == 6) {
                int subChoice;
                cout << "\n--- My Account ---" << endl;
                cout << "1. Check Balance" << endl;
                cout << "2. Change PIN" << endl;
                cout << "Select option: ";
                cin >> subChoice;

                if (subChoice == 1) {
                    cout << "Your current balance is: Ksh " << balance << endl;
                } else if (subChoice == 2) {
                    string newPin;
                    cout << "Enter new PIN: ";
                    cin >> newPin;
                    if (newPin.length() == 4) {
                        pin = newPin;
                        cout << "PIN changed successfully!" << endl;
                    } else {
                        cout << "Error: PIN must be 4 digits!" << endl;
                    }
                } else {
                    cout << "Invalid option under My Account." << endl;
                }

            // Exit
            } else if (choice == 7) {
                cout << "Thank you for using M-PESA. Goodbye!" << endl;

            } else {
                cout << "Invalid choice. Please try again." << endl;
            }

        } while (choice != 7);

    } else {
        cout << "Incorrect PIN. Access denied!" << endl;
    }

    return 0;
}