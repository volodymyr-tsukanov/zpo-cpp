#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H
#include <string>
#include <stdexcept>

class BankAccount {
private:
    std::string last_name;
    std::string account_number;
    double balance;

public:
    // Constructor
    BankAccount(const std::string& lastName, const std::string& accountNum, double initialBalance);

    // Methods
    void add(double amount);
    void withdraw(double amount);
    bool isMillionaire() const;

    // Getters
    std::string getLastName() const { return last_name; }
    std::string getAccountNumber() const { return account_number; }
    double getBalance() const { return balance; }

    // Setters
    void setLastName(const std::string& lastName) { last_name = lastName; }
    void setAccountNumber(const std::string& accountNum) { account_number = accountNum; }
    void setBalance(double bal) { balance = bal; }
};

#endif // BANK_ACCOUNT_H
