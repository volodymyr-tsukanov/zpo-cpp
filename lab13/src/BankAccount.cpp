#include "BankAccount.h"

using namespace std;


BankAccount::BankAccount(const string& lastName, const string& accountNum, double initialBalance)
    : last_name(lastName), account_number(accountNum), balance(initialBalance) {
    if (initialBalance < 0) {
        throw invalid_argument("Initial balance cannot be negative");
    }
}


void BankAccount::add(double amount) {
    if (amount <= 0) {
        throw invalid_argument("Amount to add must be positive");
    }
    balance += amount;
}

void BankAccount::withdraw(double amount) {
    if (amount <= 0) {
        throw invalid_argument("Amount to withdraw must be positive");
    }
    if (balance - amount < 0) {
        throw runtime_error("Insufficient funds");
    }
    balance -= amount;
}

bool BankAccount::isMillionaire() const {
    return balance >= 1000000.0;
}
