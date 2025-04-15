#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
using namespace std;

// Global variables for user account
float balance = 10000.0;  // Initial balance
string phoneNumber = "254712345678";
int pin = 1234;

// Function prototypes
void mainMenu();
void sendMoney();
void withdrawCash();
void buyAirtime();
void loansAndSavings();
void lipaNaMpesa();
void myAccount();
void changePin();
void exitApp();

// Utility functions
void clearScreen() {
    cout << "\033[2J\033[1;1H";  // ANSI escape codes to clear screen
}

void pressEnterToContinue() {
    cout << "\nPress Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    clearScreen();
}

// Main application function
int main() {
    int attempts = 0;
    int inputPin;
    
    clearScreen();
    cout << "================================\n";
    cout << "    WELCOME TO M-PESA SERVICE   \n";
    cout << "================================\n\n";
    
    // PIN verification (max 3 attempts)
    while (attempts < 3) {
        cout << "Enter your M-PESA PIN: ";
        cin >> inputPin;
        
        if (inputPin == pin) {
            clearScreen();
            mainMenu();
            return 0;
        } else {
            attempts++;
            cout << "Incorrect PIN. " << 3-attempts << " attempts remaining.\n";
        }
    }
    
    cout << "\nToo many incorrect attempts. Account locked.\n";
    return 0;
}

void mainMenu() {
    int choice;
    
    do {
        clearScreen();
        cout << "================================\n";
        cout << "    M-PESA MAIN MENU            \n";
        cout << "================================\n";
        cout << "1. Send Money\n";
        cout << "2. Withdraw Cash\n";
        cout << "3. Buy Airtime\n";
        cout << "4. Loans & Savings\n";
        cout << "5. Lipa na M-PESA\n";
        cout << "6. My Account\n";
        cout << "7. Exit\n";
        cout << "================================\n";
        cout << "Enter your choice (1-7): ";
        cin >> choice;
        
        switch(choice) {
            case 1: sendMoney(); break;
            case 2: withdrawCash(); break;
            case 3: buyAirtime(); break;
            case 4: loansAndSavings(); break;
            case 5: lipaNaMpesa(); break;
            case 6: myAccount(); break;
            case 7: exitApp(); break;
            default: 
                cout << "Invalid choice. Please try again.\n";
                pressEnterToContinue();
        }
    } while (choice != 7);
}

void sendMoney() {
    clearScreen();
    string recipient;
    float amount;
    int confirm;
    
    cout << "================================\n";
    cout << "        SEND MONEY              \n";
    cout << "================================\n";
    cout << "Current balance: KES " << fixed << setprecision(2) << balance << "\n\n";
    
    cout << "Enter recipient phone number: ";
    cin >> recipient;
    
    // Validate phone number format
    if (recipient.length() != 12 || recipient.substr(0, 3) != "254") {
        cout << "\nInvalid phone number format. Must start with 254 and be 12 digits.\n";
        pressEnterToContinue();
        return;
    }
    
    cout << "Enter amount to send: KES ";
    cin >> amount;
    
    // Validate amount
    if (amount <= 0) {
        cout << "\nAmount must be positive.\n";
        pressEnterToContinue();
        return;
    }
    
    if (amount > balance) {
        cout << "\nInsufficient funds. Current balance: KES " << balance << "\n";
        pressEnterToContinue();
        return;
    }
    
    cout << "\nSend KES " << amount << " to " << recipient << "?\n";
    cout << "1. Confirm\n2. Cancel\n";
    cout << "Enter choice: ";
    cin >> confirm;
    
    if (confirm == 1) {
        balance -= amount;
        cout << "\nSuccess! KES " << amount << " sent to " << recipient << "\n";
        cout << "New balance: KES " << balance << "\n";
    } else {
        cout << "\nTransaction cancelled.\n";
    }
    
    pressEnterToContinue();
}

void withdrawCash() {
    clearScreen();
    float amount;
    int agentNumber;
    int confirm;
    
    cout << "================================\n";
    cout << "        WITHDRAW CASH           \n";
    cout << "================================\n";
    cout << "Current balance: KES " << balance << "\n\n";
    
    cout << "Enter agent number: ";
    cin >> agentNumber;
    
    cout << "Enter amount to withdraw: KES ";
    cin >> amount;
    
    // Validate amount
    if (amount <= 0) {
        cout << "\nAmount must be positive.\n";
        pressEnterToContinue();
        return;
    }
    
    if (amount > balance) {
        cout << "\nInsufficient funds. Current balance: KES " << balance << "\n";
        pressEnterToContinue();
        return;
    }
    
    cout << "\nWithdraw KES " << amount << " from agent " << agentNumber << "?\n";
    cout << "1. Confirm\n2. Cancel\n";
    cout << "Enter choice: ";
    cin >> confirm;
    
    if (confirm == 1) {
        balance -= amount;
        cout << "\nSuccess! Please collect your cash.\n";
        cout << "New balance: KES " << balance << "\n";
    } else {
        cout << "\nTransaction cancelled.\n";
    }
    
    pressEnterToContinue();
}

void buyAirtime() {
    clearScreen();
    float amount;
    string recipient;
    int confirm;
    
    cout << "================================\n";
    cout << "        BUY AIRTIME             \n";
    cout << "================================\n";
    cout << "Current balance: KES " << balance << "\n\n";
    
    cout << "Enter phone number: ";
    cin >> recipient;
    
    // Validate phone number
    if (recipient.length() != 12 || recipient.substr(0, 3) != "254") {
        cout << "\nInvalid phone number format.\n";
        pressEnterToContinue();
        return;
    }
    
    cout << "Enter amount: KES ";
    cin >> amount;
    
    // Validate amount
    if (amount <= 0) {
        cout << "\nAmount must be positive.\n";
        pressEnterToContinue();
        return;
    }
    
    if (amount > balance) {
        cout << "\nInsufficient funds.\n";
        pressEnterToContinue();
        return;
    }
    
    cout << "\nBuy airtime for KES " << amount << " for " << recipient << "?\n";
    cout << "1. Confirm\n2. Cancel\n";
    cout << "Enter choice: ";
    cin >> confirm;
    
    if (confirm == 1) {
        balance -= amount;
        cout << "\nSuccess! Airtime purchased.\n";
        cout << "New balance: KES " << balance << "\n";
    } else {
        cout << "\nTransaction cancelled.\n";
    }
    
    pressEnterToContinue();
}

void loansAndSavings() {
    clearScreen();
    int choice;
    
    cout << "================================\n";
    cout << "    LOANS & SAVINGS             \n";
    cout << "================================\n";
    cout << "1. Request Loan\n";
    cout << "2. Pay Loan\n";
    cout << "3. Savings\n";
    cout << "4. Back\n";
    cout << "================================\n";
    cout << "Enter choice: ";
    cin >> choice;
    
    // Would implement loan/savings functionality here
    cout << "\nFeature coming soon!\n";
    pressEnterToContinue();
}

void lipaNaMpesa() {
    clearScreen();
    int choice;
    
    cout << "================================\n";
    cout << "    LIPA NA M-PESA              \n";
    cout << "================================\n";
    cout << "1. Pay Bill\n";
    cout << "2. Buy Goods & Services\n";
    cout << "3. Pochi La Biashara\n";
    cout << "4. Back\n";
    cout << "================================\n";
    cout << "Enter choice: ";
    cin >> choice;
    
    // Would implement Lipa na M-PESA functionality here
    cout << "\nFeature coming soon!\n";
    pressEnterToContinue();
}

void myAccount() {
    clearScreen();
    int choice;
    
    do {
        cout << "================================\n";
        cout << "        MY ACCOUNT              \n";
        cout << "================================\n";
        cout << "Phone: " << phoneNumber << "\n";
        cout << "Balance: KES " << balance << "\n\n";
        cout << "1. Change PIN\n";
        cout << "2. Account Statement\n";
        cout << "3. Back\n";
        cout << "================================\n";
        cout << "Enter choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1: changePin(); break;
            case 2: 
                cout << "\nAccount statement feature coming soon!\n";
                pressEnterToContinue();
                break;
            case 3: return;
            default:
                cout << "Invalid choice\n";
                pressEnterToContinue();
        }
    } while (choice != 3);
}

void changePin() {
    clearScreen();
    int oldPin, newPin, confirmPin;
    
    cout << "================================\n";
    cout << "         CHANGE PIN             \n";
    cout << "================================\n";
    
    cout << "Enter current PIN: ";
    cin >> oldPin;
    
    if (oldPin != pin) {
        cout << "\nIncorrect current PIN.\n";
        pressEnterToContinue();
        return;
    }
    
    cout << "Enter new PIN: ";
    cin >> newPin;
    
    cout << "Confirm new PIN: ";
    cin >> confirmPin;
    
    if (newPin != confirmPin) {
        cout << "\nPINs do not match.\n";
        pressEnterToContinue();
        return;
    }
    
    pin = newPin;
    cout << "\nPIN changed successfully!\n";
    pressEnterToContinue();
}

void exitApp() {
    clearScreen();
    cout << "================================\n";
    cout << "  THANK YOU FOR USING M-PESA    \n";
    cout << "================================\n";
    cout << "Goodbye!\n\n";
}