#include <iostream>
#include <stdexcept>
#include <tuple>
#include <gtest/gtest.h>
#include "BankAccount.h"

using namespace std;


bool isPrime(int number) {
    // Numbers less than 2 are not prime
    if (number < 2) return false;

    // Check divisibility up to square root
    for (int i = 2; i * i <= number; ++i) {
        if (number % i == 0) return false;
    }
    return true;
}

double getReciprocal(double number) {
    if (number == 0.0) {
        throw invalid_argument("Cannot calculate reciprocal of zero");
    }
    return 1.0 / number;
}


TEST(PrimeTest, BasicAssertions) {
    // Test basic prime numbers
    EXPECT_TRUE(isPrime(2));
    EXPECT_TRUE(isPrime(3));
    EXPECT_TRUE(isPrime(5));
    EXPECT_TRUE(isPrime(7));
    EXPECT_TRUE(isPrime(11));

    // Test non-prime numbers
    EXPECT_FALSE(isPrime(0));
    EXPECT_FALSE(isPrime(1));
    EXPECT_FALSE(isPrime(4));
    EXPECT_FALSE(isPrime(6));
    EXPECT_FALSE(isPrime(8));
    EXPECT_FALSE(isPrime(9));
}

TEST(ReciprocalTest, BasicAssertions) {
    // Test positive numbers
    EXPECT_DOUBLE_EQ(getReciprocal(2.0), 0.5);
    EXPECT_DOUBLE_EQ(getReciprocal(4.0), 0.25);

    // Test negative numbers
    EXPECT_DOUBLE_EQ(getReciprocal(-2.0), -0.5);

    // Test exception for zero
    EXPECT_THROW({
        getReciprocal(0.0);
    }, invalid_argument);
}



// Test fixture for parametric tests
class BankAccountTest : public testing::TestWithParam<tuple<string, string, double>> {
protected:
    BankAccount* account;

    void SetUp() override {
        auto params = GetParam();
        account = new BankAccount(
            get<0>(params),  // last_name
            get<1>(params),  // account_number
            get<2>(params)   // initial_balance
        );
    }

    void TearDown() override {
        delete account;
    }
};

// Parametric test for account creation
TEST_P(BankAccountTest, ValidateInitialState) {
    auto params = GetParam();
    EXPECT_EQ(account->getLastName(), get<0>(params));
    EXPECT_EQ(account->getAccountNumber(), get<1>(params));
    EXPECT_EQ(account->getBalance(), get<2>(params));
}
// Define test parameters
INSTANTIATE_TEST_SUITE_P(
    DefaultAccounts,
    BankAccountTest,
    testing::Values(
        make_tuple("Smith", "ACC001", 1000.0),
        make_tuple("Johnson", "ACC002", 500000.0),
        make_tuple("Williams", "ACC003", 1500000.0)
    )
);
// Regular test cases
TEST(BankAccountBasicTest, AddFunds) {
    BankAccount account("Test", "ACC123", 1000.0);
    account.add(500.0);
    EXPECT_EQ(account.getBalance(), 1500.0);
    EXPECT_THROW(account.add(-100.0), invalid_argument);
}
TEST(BankAccountBasicTest, WithdrawFunds) {
    BankAccount account("Test", "ACC123", 1000.0);
    account.withdraw(300.0);
    EXPECT_EQ(account.getBalance(), 700.0);
    EXPECT_THROW(account.withdraw(1000.0), runtime_error);
    EXPECT_THROW(account.withdraw(-100.0), invalid_argument);
}
TEST(BankAccountBasicTest, IsMillionaire) {
    BankAccount rich("Rich", "ACC999", 1500000.0);
    BankAccount poor("Poor", "ACC888", 100000.0);
    EXPECT_TRUE(rich.isMillionaire());
    EXPECT_FALSE(poor.isMillionaire());
}


int main(int argc, char **argv) {
    // Initialize Google Test
    testing::InitGoogleTest(&argc, argv);

    int zadN = 1;
    while(zadN != 0){
        printf("n?: ");
        cin >> zadN;

        switch(zadN){
        case 1: // tests isPrime
            testing::GTEST_FLAG(filter) = "PrimeTest.*";
            RUN_ALL_TESTS();
        break;
        case 2: // tests getReciprocal
            testing::GTEST_FLAG(filter) = "ReciprocalTest.*";
            RUN_ALL_TESTS();
        break;
        case 3:
            testing::GTEST_FLAG(filter) = "DefaultAccounts.*:BankAccountBasicTest.*";
            RUN_ALL_TESTS();
        break;
        case 31:    // Only parametric tests
            testing::GTEST_FLAG(filter) = "DefaultAccounts.*";
            RUN_ALL_TESTS();
        break;
        case 32:    // Only basic tests
            testing::GTEST_FLAG(filter) = "BankAccountBasicTest.*";
            RUN_ALL_TESTS();
        break;
        default: // nothing
        break;
        }

        if(zadN != 0) {
            cout << "\n\n*-*-*-*-{-----<*****[-----|-\\_/-|-----]*****>-----}-*-*-*-*\n\n" << endl;
        }
    }

    return 0;
}
