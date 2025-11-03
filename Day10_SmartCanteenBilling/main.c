//smart canteen billing system
#include <stdio.h>
int main() {
int num_customers, items, code, qty, i, j;
int total_revenue = 0;
printf("Enter total number of customers: ");
 scanf("%d", &num_customers);


for(i = 1; i <= num_customers; i++) {
int customer_total = 0;
printf("\n--- Customer %d ---\n", i);
printf("Menu:\n");
printf("1. Sandwich - ₹80\n2. Burger - ₹120\n3. Pizza Slice - ₹150\n4. Coffee - ₹60\n5. Juice - ₹50\n");
printf("Enter number of items: ");
scanf("%d", &items);



for(j = 1; j <= items; j++) {
   printf("Enter item code: ");
   scanf("%d", &code);
 printf("Enter quantity: ");
scanf("%d", &qty);

            int price = 0;
            char name[20];
            if (code == 1) {
                price = 80 * qty;
                printf("Sandwich x %d = %d\n", qty, price);
            } else if (code == 2) {
                price = 120 * qty;
                printf("Burger x %d = %d\n", qty, price);
            } else if (code == 3) {
                price = 150 * qty;
                printf("Pizza Slice x %d = %d\n", qty, price);
            } else if (code == 4) {
                price = 60 * qty;
                printf("Coffee x %d = %d\n", qty, price);
            } else if (code == 5) {
                price = 50 * qty;
                printf("Juice x %d = %d\n", qty, price);
            } else {
                printf("Invalid item code.\n");
                price = 0;
            }
            customer_total += price;
}printf("Total: %d\n", customer_total);
  if(customer_total > 500) {
    int discount = customer_total * 0.10;
   printf("Discount (10%%): %d\n", discount);
 customer_total -= discount;
        }
printf("Final Bill: %d\n", customer_total);
       total_revenue += customer_total;
    }
    printf("\n======= Canteen Summary =======\n");
    printf("Total Customers Served: %d\n", num_customers);
    printf("Total Revenue: %d\n", total_revenue);
    printf("===============================\n");
    return 0;
}

