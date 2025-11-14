// Name: G.V.BHARATH
// Registration Number: AP25110090146
// Section: C
// Challenge Day 18 – Inventory Management System

#include <stdio.h>

int main() {
    // Arrays to store product information
    int productID[10];
    char productName[10][50];
    int quantity[10];
    float price[10];

    int n, i, choice;
    float totalValue, maxValue, minValue;
    int maxIndex, minIndex, searchID, found;

    printf("******** INVENTORY MANAGEMENT SYSTEM ********\n");
    
    // Step 1: Input number of products
    printf("Enter the number of products (max 10): ");
    scanf("%d", &n);

if (n <= 0 || n > 10) {
printf("Invalid number of products! Program exiting...\n");
return 0;
}
    
// Step 2: Enter details for each product
    for (i = 0; i < n; i++) {
        printf("\nEnter details for Product %d\n", i + 1);
        printf("Product ID: ");
        scanf("%d", &productID[i]);
        printf("Product Name: ");
        scanf(" %[^\n]", productName[i]);
        printf("Quantity in stock: ");
        scanf("%d", &quantity[i]);
        printf("Price per item: ");
        scanf("%f", &price[i]);
}

 
do {
    printf("\n=========== MENU ===========\n");
    printf("1. Display All Products\n");
    printf("2. Show Total Inventory Value\n");
    printf("3. Show Highest & Lowest Value Products\n");
    printf("4. Search Product by ID\n");
    printf("5. Exit\n");
    printf("============================\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

   switch (choice) {
   case 1:
                printf("\n--- Product List ---\n");
                printf("ID\tName\t\tQuantity\tPrice\tValue\n");
                for (i = 0; i < n; i++) {
                    printf("%d\t%-10s\t%d\t\t%.2f\t%.2f\n",
                           productID[i], productName[i], quantity[i],
                           price[i], quantity[i] * price[i]);
  }
                 break;
   case 2:
                totalValue = 0;
                for (i = 0; i < n; i++) {
                    totalValue += quantity[i] * price[i];
                }
                printf("\nTotal Inventory Value = %.2f\n", totalValue);
                break;

   case 3:
                maxValue = minValue = quantity[0] * price[0];
                maxIndex = minIndex = 0;

                for (i = 1; i < n; i++) {
                    float value = quantity[i] * price[i];
                    if (value > maxValue) {
                        maxValue = value;
                        maxIndex = i;
}
                    if (value < minValue) {
                        minValue = value;
                        minIndex = i;
} 
}

                printf("\nProduct with Highest Value:\n");
                printf("ID: %d | Name: %s | Value: %.2f\n",
                       productID[maxIndex], productName[maxIndex], maxValue);

                printf("\nProduct with Lowest Value:\n");
                printf("ID: %d | Name: %s | Value: %.2f\n",
                       productID[minIndex], productName[minIndex], minValue);
                break;

    case 4:
                printf("Enter Product ID to search: ");
                scanf("%d", &searchID);
                found = 0;

                for (i = 0; i < n; i++) {
                    if (productID[i] == searchID) {
                        printf("\nProduct Found!\n");
                        printf("ID: %d\nName: %s\nQuantity: %d\nPrice: %.2f\nValue: %.2f\n",
                               productID[i], productName[i], quantity[i],
                               price[i], quantity[i] * price[i]);
                        found = 1;
                        break;
                    }
  }

                if (!found)
                  printf("No product found with ID %d.\n", searchID);
                  break;

    case 5:
               printf("Exiting Inventory System... Thank you!\n");
               break; 

    default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 5);

printf("\n===== End of Program =====\n");
printf("Submitted by: G.V.BHARATH | Reg No: AP25110090146 | Section: C\n");
printf("Challenge Day 18  Code2Grow Program\n");
return 0;
}
