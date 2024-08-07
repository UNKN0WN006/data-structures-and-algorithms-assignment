#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ACCOUNTS 10
#define MIN_BALANCE 1000.0
#define INTEREST_RATE 0.05
typedef struct {
    int accountNumber;
    double balance;
} SavingsAccount;
void calculateInterest(SavingsAccount accounts[], int count) {
    double totalInterest = 0;
    for (int i = 0; i < count; i++) {
        double interest = accounts[i].balance * INTEREST_RATE;
        accounts[i].balance += interest;
        totalInterest += interest;
    }
    printf("Total interest paid to all accounts: Rs. %.2f\n", totalInterest);
}
void printAllAccounts(SavingsAccount accounts[], int count) {
    for (int i = 0; i < count; i++) {
        printf("Account Number: %d, Balance: Rs. %.2f\n",
               accounts[i].accountNumber, accounts[i].balance);
    }
}

int main() {
    SavingsAccount accounts[MAX_ACCOUNTS];
    int currentAccountNumber = 1000;
    // Seed the random number generator
    srand(time(NULL));
    // Create SavingsAccount variables with random balances
    for (int i = 0; i < MAX_ACCOUNTS; i++) {
        accounts[i].accountNumber = currentAccountNumber++;
        accounts[i].balance = MIN_BALANCE + (rand() % (100000 - 1000 + 1)); // Random balance between Rs. 1000 and Rs. 100000
    }
    // Print all accounts before interest calculation
    printf("All accounts before interest calculation:\n");
    printAllAccounts(accounts, MAX_ACCOUNTS);
    // Calculate interest and update balances
    calculateInterest(accounts, MAX_ACCOUNTS);
    // Print all accounts after interest calculation
    printf("All accounts after interest calculation:\n");
    printAllAccounts(accounts, MAX_ACCOUNTS);
    return 0;
}
