#include <stdio.h>

#define MAX 20   // maximum products

// Arrays to store product data
int id[MAX], qty[MAX], price[MAX];
int n = 0;   // how many products added

// ---------------------------
// Add Product
// ---------------------------
void addProduct() {
    int pid, q, p;

    if(n == MAX) {
        printf("\nWarehouse is full.\n");
        return;
    }

    printf("\nEnter Product ID: ");
    scanf("%d", &pid);

    // check duplicate ID
    for(int i = 0; i < n; i++) {
        if(id[i] == pid) {
            printf("\nThis ID already exists.\n");
            return;
        }
    }

    printf("Enter Quantity: ");
    scanf("%d", &q);

    printf("Enter Price: ");
    scanf("%d", &p);

    if(q <= 0 || p <= 0) {
        printf("\nQuantity and Price must be positive.\n");
        return;
    }

    id[n] = pid;
    qty[n] = q;
    price[n] = p;

    n++;

    printf("\nProduct added successfully.\n");
}

// ---------------------------
// Search Product
// ---------------------------
void searchProduct() {
    int pid;
    printf("\nEnter ID to search: ");
    scanf("%d", &pid);

    for(int i = 0; i < n; i++) {
        if(id[i] == pid) {
            printf("\nProduct Found:\n");
            printf("ID = %d\n", id[i]);
            printf("Quantity = %d\n", qty[i]);
            printf("Price = %d\n", price[i]);
            return;
        }
    }

    printf("\nProduct Not Found.\n");
}

// ---------------------------
// Update Quantity
// ---------------------------
void updateQuantity() {
    int pid, choice, amount;

    printf("\nEnter Product ID: ");
    scanf("%d", &pid);

    for(int i = 0; i < n; i++) {
        if(id[i] == pid) {

            printf("\n1. Increase\n2. Decrease\nEnter choice: ");
            scanf("%d", &choice);

            if(choice == 1) {
                printf("Enter amount to add: ");
                scanf("%d", &amount);
                qty[i] += amount;
            }
            else if(choice == 2) {
                printf("Enter amount to reduce: ");
                scanf("%d", &amount);

                if(qty[i] - amount < 0) {
                    printf("\nQuantity cannot be negative.\n");
                    return;
                }
                qty[i] -= amount;
            }
            else {
                printf("\nInvalid choice.\n");
            }

            printf("\nQuantity updated.\n");
            return;
        }
    }

    printf("\nProduct ID not found.\n");
}

// ---------------------------
// Rack Report (3x3 Matrix)
// ---------------------------
void rackReport() {
    int a[3][3];
    int max = -1, min = 999999;
    int maxR = 0, maxC = 0;
    int minR = 0, minC = 0;
    int total = 0;

    printf("\nEnter 3x3 Rack values:\n");

    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            scanf("%d", &a[i][j]);
            total += a[i][j];

            if(a[i][j] > max) {
                max = a[i][j];
                maxR = i;
                maxC = j;
            }

            if(a[i][j] < min) {
                min = a[i][j];
                minR = i;
                minC = j;
            }
        }
    }

    printf("\nMax Value = %d at (%d,%d)\n", max, maxR, maxC);
    printf("Min Value = %d at (%d,%d)\n", min, minR, minC);
    printf("Total Items in rack = %d\n", total);
}

// ---------------------------
// Stock Value for each product
// ---------------------------
void stockValue() {
    if(n == 0) {
        printf("\nNo products available.\n");
        return;
    }

    int max = -1, min = 999999, total = 0;
    int maxI = 0, minI = 0;

    printf("\nID\tQty\tPrice\tValue\n");

    for(int i=0; i<n; i++) {
        int v = qty[i] * price[i];
        printf("%d\t%d\t%d\t%d\n", id[i], qty[i], price[i], v);

        if(v > max) {
            max = v;
            maxI = i;
        }
        if(v < min) {
            min = v;
            minI = i;
        }

        total += v;
    }

    printf("\nHighest Value Product ID = %d (%d)\n", id[maxI], max);
    printf("Lowest Value Product ID = %d (%d)\n", id[minI], min);
    printf("Total Warehouse Value = %d\n", total);
}

// ---------------------------
// Display All Products
// ---------------------------
void displayAll() {
    if(n == 0) {
        printf("\nNo products added yet.\n");
        return;
    }

    printf("\nID\tQty\tPrice\tValue\n");

    for(int i=0; i<n; i++) {
        printf("%d\t%d\t%d\t%d\n", id[i], qty[i], price[i], qty[i]*price[i]);
    }
}

// ---------------------------
// MAIN MENU
// ---------------------------
int main() {

    int ch;

    while(1) {
        printf("\n------ MENU ------\n");
        printf("1. Add Product\n");
        printf("2. Search Product\n");
        printf("3. Update Quantity\n");
        printf("4. Rack Report\n");
        printf("5. Stock Value Report\n");
        printf("6. Display All Products\n");
        printf("7. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &ch);

        if(ch == 1) addProduct();
        else if(ch == 2) searchProduct();
        else if(ch == 3) updateQuantity();
        else if(ch == 4) rackReport();
        else if(ch == 5) stockValue();
        else if(ch == 6) displayAll();
        else if(ch == 7) break;
        else printf("\nInvalid choice.\n");
    }

    return 0;
}

