#include <stdio.h>

int main() {
    int prices[5] = {50, 30, 80, 120, 60};
    int quantitiesSold[5] = {0, 0, 0, 0, 0};
    int numCustomers, numItems, itemNumber, quantity;
    int totalRevenue = 0;
    int totalItemsSold = 0;

    printf("\nCafe Order Management System");

    // Display menu
    printf("\nMenu:");
    printf("\n1. Coffee - 50");
    printf("\n2. Tea - 30");
    printf("\n3. Sandwich - 80");
    printf("\n4. Burger - 120");
    printf("\n5. Pastry - 60");

    // Input number of customers (max 10)
    do {
        printf("\nEnter total number of customers (max 10): ");
        scanf("%d", &numCustomers);
    } while (numCustomers < 1 || numCustomers > 10);

    for (int c = 1; c <= numCustomers; c++) {
        printf("\n--- Customer %d ---", c);

        // Input number of items for each customer
        printf("\nEnter number of items: ");
        scanf("%d", &numItems);

        int customerBill = 0;

        for (int i = 0; i < numItems; i++) {
            printf("\nEnter item number and quantity: ");
            scanf("%d %d", &itemNumber, &quantity);

            if (itemNumber >= 1 && itemNumber <= 5 && quantity > 0) {
                customerBill += prices[itemNumber - 1] * quantity;
                quantitiesSold[itemNumber - 1] += quantity;
                totalItemsSold += quantity;
            }
            else {
                printf("\nInvalid item number or quantity. Try again.");
                i--; // Repeat this iteration
            }
        }
        printf("\nTotal Bill for Customer %d: %d", c, customerBill);
        totalRevenue += customerBill;
    }

    // Find most ordered and least ordered items
    int maxQuantity = quantitiesSold[0];
    int minQuantity = quantitiesSold[0];
    int mostOrderedIndex = 0;
    int leastOrderedIndex = 0;

    for (int i = 1; i < 5; i++) {
        if (quantitiesSold[i] > maxQuantity) {
            maxQuantity = quantitiesSold[i];
            mostOrderedIndex = i;
        }
        if (quantitiesSold[i] < minQuantity) {
            minQuantity = quantitiesSold[i];
            leastOrderedIndex = i;
        }
    }

    // Display summary
    printf("\nCafe Summary");
    printf("\nTotal Revenue: %d", totalRevenue);
    printf("\nTotal Items Sold: %d", totalItemsSold);

    char *itemNames[5] = {"Coffee", "Tea", "Sandwich", "Burger", "Pastry"};

    printf("\nMost Ordered Item: %s", itemNames[mostOrderedIndex]);
    printf("\nLeast Ordered Item: %s", itemNames[leastOrderedIndex]);
}
