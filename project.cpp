#include <iostream>
#include <string>
#include <unordered_map>

class Account {
private:
    std::string accountNumber;
    std::string name;
    double balance;

public:
    Account(std::string accNum, std::string accName, double initialBalance)
        : accountNumber(accNum), name(accName), balance(initialBalance) {}

    std::string getAccountNumber() const { return accountNumber; }
    std::string getName() const { return name; }
    double getBalance() const { return balance; }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Deposit successful. New balance: " << balance << std::endl;
        } else {
            std::cout << "Invalid deposit amount." << std::endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            std::cout << "Withdrawal successful. New balance: " << balance << std::endl;
        } else {
            std::cout << "Invalid withdrawal amount or insufficient balance." << std::endl;
        }
    }
};

int main() {
    std::unordered_map<std::string, Account> accounts;
    int choice;

    do {
        std::cout << "\n--- Bank Management System ---\n";
        std::cout << "1. Create Account\n";
        std::cout << "2. Deposit Money\n";
        std::cout << "3. Withdraw Money\n";
        std::cout << "4. Check Balance\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

 switch (choice) {
            case 1: {
            std::string accNum, name;
            double initialBalance;
            std::cout << "Enter account number: ";
            std::cin >> accNum;
            std::cout << "Enter name: ";
            std::cin.ignore();  // To ignore the newline character left by std::cin
            std::getline(std::cin, name);
            std::cout << "Enter initial balance: ";
            std::cin >> initialBalance;

            if (accounts.find(accNum) == accounts.end()) {
                accounts[accNum] = Account(accNum, name, initialBalance);
                std::cout << "Account created successfully!" << std::endl;
            } else {
                std::cout << "Account number already exists." << std::endl;
            }
            break;
        }
        case 2: {
            std::string accNum;
            double amount;
            std::cout << "Enter account number: ";
            std::cin >> accNum;
            if (accounts.find(accNum) != accounts.end()) {
                std::cout << "Enter amount to deposit: ";
                std::cin >> amount;
                accounts[accNum].deposit(amount);
            } else {
                std::cout << "Account not found." << std::endl;
            }
            break;
        }
        case 1: {
            std::string accNum, name;
            double initialBalance;
            std::cout << "Enter account number: ";
            std::cin >> accNum;
            std::cout << "Enter name: ";
            std::cin.ignore();  // To ignore the newline character left by std::cin
            std::getline(std::cin, name);
            std::cout << "Enter initial balance: ";
            std::cin >> initialBalance;

            if (accounts.find(accNum) == accounts.end()) {
                accounts[accNum] = Account(accNum, name, initialBalance);
                std::cout << "Account created successfully!" << std::endl;
            } else {
                std::cout << "Account number already exists." << std::endl;
            }
            break;
        }
        case 2: {
            std::string accNum;
            double amount;
            std::cout << "Enter account number: ";
            std::cin >> accNum;
            if (accounts.find(accNum) != accounts.end()) {
                std::cout << "Enter amount to deposit: ";
                std::cin >> amount;
                accounts[accNum].deposit(amount);
            } else {
                std::cout << "Account not found." << std::endl;
            }
            break;
        }
