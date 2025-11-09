#include <stdio.h>

int main() {
    int n, i, room_type, days, total_rooms = 0;
    char name[50], ch;
    float rate, base_fare, service_charge, subtotal, discount, gst, final_bill;
    float hotel_total = 0, highest = 0, lowest = 999999;
    
    printf("Enter total number of customers: ");
    scanf("%d", &n);
    getchar(); // clear newline
    
    for (i = 1; i <= n; i++) {
        printf("\n--- Customer %d ---\n", i);
        printf("Enter name: ");
        fgets(name, sizeof(name), stdin);
        
        printf("Enter room type (1-Deluxe, 2-Super Deluxe, 3-Suite):\n ");
        scanf("%d", &room_type);
        printf("Enter number of days: \n");
        scanf("%d", &days);
        
// Set rate
if (room_type == 1) rate = 2500;
else if (room_type == 2) rate = 4000;
else rate = 6000;
        
base_fare = rate * days;
service_charge = 0;
       
        printf("Breakfast (Y/N): \n");
        getchar(); // clear newline
        ch = getchar();
        if (ch == 'Y' || ch == 'y') service_charge += 300 * days;
        
        printf("Wi-Fi (Y/N): \n");
        getchar();
        ch = getchar();
        if (ch == 'Y' || ch == 'y') service_charge += 100 * days;
        
        printf("Gym Access (Y/N):\n ");
        getchar();
        ch = getchar();
        if (ch == 'Y' || ch == 'y') service_charge += 200 * days;
        
subtotal = base_fare + service_charge;
discount = 0;
if (subtotal > 10000) discount = 0.10 * subtotal;
gst = 0.12 * (subtotal - discount);
final_bill = subtotal - discount + gst;
        
        hotel_total += final_bill;
        if (final_bill > highest) highest = final_bill;
        if (final_bill < lowest) lowest = final_bill;
        total_rooms++;
        
        printf("\nBase Fare: ₹%.0f\nAdditional Services: ₹%.0f\nSubtotal: ₹%.0f\n", base_fare, service_charge, subtotal);
        printf("Discount: ₹%.0f\nGST (12%%): ₹%.0f\n", discount, gst);
        printf("Final Bill: ₹%.0f\n", final_bill);
        
        getchar(); // read trailing newline for next customer
    }

    // Summary
    printf("\n========= Hotel Summary =========\n");
    printf("Total Rooms Booked: %d\n", total_rooms);
    printf("Total Revenue: ₹%.0f\n", hotel_total);
    printf("Highest Bill: ₹%.0f\n", highest);
    printf("Lowest Bill: ₹%.0f\n", lowest);
    printf("=================================\n");
    return 0;
}
