#include <stdio.h>

int main() {
    int choice, amount;
    float balance = 10000;
    float bonus;
while (1)  {
printf("\n------ Smart Bank Account Manager ------\n");
printf("1. Deposit Money\n");
printf("2. Withdraw Money\n");
printf("3. Check Balance\n");
printf("4. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);

if (choice == 1)
 {
 printf("Enter amount to deposit: ");
scanf("%d", &amount);
if (amount > 25000) 
{
bonus = amount * 0.01;
printf("Bonus of %.0f added!\n", bonus);
amount += bonus;
 }
balance += amount;
balance -= 5; // Service charge
printf("Service charge 5 applied.\n");
printf("Updated Balance: %.0f\n", balance);
 }




else if (choice == 2) {
printf("Enter amount to withdraw: ");
scanf("%d", &amount);
 if (amount > balance)
 {
 printf("Withdrawal not allowed. Insufficient balance!\n");
 }
else {
balance -= amount;
balance -= 5; 
// Service charge
printf("Service charge 5 applied.\n");
 printf("Updated Balance: %.0f\n", balance);
}
 }


else if (choice == 3) {
printf("Current Balance: %.0f\n", balance);
}
else if (choice == 4) {
printf("Thank you for banking with us!\n");
break;
}
 else {
printf("Invalid choice, please try again!\n");
        }
    }
return 0;
}
