#include <stdio.h>

int main() {
    int customers, i, j;
    float totalRevenue = 0, highestBill = 0, totalFeedback = 0;
    int feedback;
    

printf("Enter number of customers: ");
scanf("%d", &customers);
    

for (i = 1; i <= customers; i++) {
int items;
float subtotal = 0, finalBill, price;
int qty;
        
printf("\nCustomer %d:\n", i);
printf("Enter number of items: ");
scanf("%d", &items);
        
for (j = 1; j <= items; j++) {
printf("Enter price of item %d: ", j);
scanf("%f", &price);
printf("Enter quantity: ");
scanf("%d", &qty);
subtotal += price * qty;
        }
        
finalBill = subtotal + (0.05 * subtotal); // Add 5% GST
printf("Customer %d Bill: ₹%.2f\n", i, finalBill);
      
totalRevenue += finalBill;
if (finalBill > highestBill)
highestBill = finalBill;
     
// Feedback validation
do {
printf("Enter feedback (1-5): ");
scanf("%d", &feedback);
if (feedback < 1 || feedback > 5) {
printf("Invalid! Please enter a rating between 1 and 5.\n");
}
} while (feedback < 1 || feedback > 5);
       totalFeedback += feedback;
}



printf("\n--- Restaurant Bill Summary ---\n");
printf("Total Revenue Today: ₹%.2f\n", totalRevenue);
printf("Average Feedback Rating: %.2f\n", totalFeedback / customers);
printf("Highest Bill Amount: ₹%.2f\n", highestBill);
    
    return 0;
}

