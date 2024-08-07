#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_ACCOUNTS 100
#define MIN_BALANCE 1000.0
#define INTEREST_RATE 0.05
typedef struct {
    char name[50];
    int accountNumber;
    double balance;
} SavingsAccount;
void deposit(SavingsAccount *account, double amount) {
    if (amount > 0) {
        account->balance += amount;
        printf("Deposited Rs. %.2f to account number %d\n", amount, account->accountNumber);
    } else {
        printf("Invalid deposit amount!\n");
    }
}
void withdraw(SavingsAccount *account, double amount) {
    if (amount > 0 && account->balance - amount >= MIN_BALANCE) {
        account->balance -= amount;
        printf("Withdrew Rs. %.2f from account number %d\n", amount, account->accountNumber);
    } else {
        printf("Invalid or insufficient funds for withdrawal!\n"); }}
void calculateInterest(SavingsAccount *accounts, int count) {
    double totalInterest = 0;
    for (int i = 0; i < count; i++) {
        double interest = accounts[i].balance * INTEREST_RATE;
        accounts[i].balance += interest;
        totalInterest += interest;
    }
    printf("Total interest paid to all accounts: Rs. %.2f\n", totalInterest);
}
void printAccountDetails(const SavingsAccount *account) {
    printf("Account Number: %d, Name: %s, Balance: Rs. %.2f\n",
           account->accountNumber, account->name, account->balance);
}
void printAllAccounts(const SavingsAccount *accounts, int count) {
    for (int i = 0; i < count; i++) {
        printAccountDetails(&accounts[i]);
    }
}
int main() {
    SavingsAccount accounts[MAX_ACCOUNTS];
    int currentAccountNumber = 1000;
    // Seed the random number generator
    srand(time(0));
    // Create 100 SavingsAccount variables with random balances
    for (int i = 0; i < MAX_ACCOUNTS; i++) {
        snprintf(accounts[i].name, sizeof(accounts[i].name), "AccountHolder%d", i + 1);
        accounts[i].accountNumber = currentAccountNumber++;
        accounts[i].balance = MIN_BALANCE + (rand() % 99001); // Random balance between Rs. 1000 and Rs. 100000
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
