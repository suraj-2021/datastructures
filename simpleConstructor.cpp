#include <iostream>
#include <string>

class BankAccount {
private:
    std::string name;
    int accountNumber;
    double balance;

public:
   
    BankAccount(std::string accName, int accNumber, double accBalance)
        : name(accName), accountNumber(accNumber), balance(accBalance) {
        std::cout << "BankAccount object for " << name << " created.\n";
    }


    ~BankAccount() {
        std::cout << "BankAccount object for " << name << " destroyed.\n";
    }

    void displayBalance() {
        std::cout << "Account Holder: " << name << "\n";
        std::cout << "Account Number: " << accountNumber << "\n";
        std::cout << "Balance: $" << balance << "\n";
    }
};

int main() {
  
    BankAccount account1("Narayan", 123456, 5000.75);

  
    account1.displayBalance();

    // Object account1 will be destroyed when it goes out of scope at the end of the main function
    return 0;
}
