#include <stdio.h>

int main() {
    int balance = 10000, choice, amount, transactions = 0;
    while (transactions < 5) {
        printf("\n1. Check Balance\n2. Deposit\n3. Withdraw\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("Your Current Balance: ₹%d\n", balance);
            transactions++;
        } else if (choice == 2) {
            printf("Enter amount to deposit: ");
            scanf("%d", &amount);
            if (amount > 0) {
                balance += amount;
                printf("Amount Deposited Successfully!\n");
                transactions++;
            } else {
                printf("Invalid Deposit Amount!\n");
            }
        } else if (choice == 3) {
            printf("Enter amount to withdraw: ");
            scanf("%d", &amount);
            if (amount > 0 && (balance - amount) >= 500) {
                balance -= amount;
                printf("Withdrawal Successful! Remaining Balance: ₹%d\n", balance);
                transactions++;
            } else {
                printf("Insufficient balance or minimum balance must be ₹500!\n");
            }
        } else if (choice == 4) {
            printf("Thank you for banking with us!\n");
            break;
        } else {
            printf("Invalid choice!\n");
        }
    }
    printf("\n========= Transaction Summary =========\n");
    printf("Total Transactions: %d\n", transactions);
    printf("Final Balance: ₹%d\nSession Ended.\n", balance);
    return 0;
}
