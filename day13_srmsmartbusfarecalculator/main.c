#include <stdio.h>

int main() {
    int n, i, age, time;
    char name[30];
    float dist, fare, base_fare, total = 0, highest = 0, lowest = 0;
    
    printf("Enter number of passengers: ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++) {
        printf("\n--- Passenger %d ---\n", i);
        printf("Enter name: ");
        scanf("%s", name);
        printf("Enter age: ");
        scanf("%d", &age);
        printf("Enter distance (in km): ");
        scanf("%f", &dist);
        printf("Enter travel time (24-hour format): ");
        scanf("%d", &time);

        base_fare = dist * 10;
        fare = base_fare;

        // Apply discounts
        if(age < 12)
            fare = fare * 0.5; // Child
        else if(age >= 60)
            fare = fare * 0.7; // Senior

        // Peak hour surcharge
        if((time >= 8 && time < 10) || (time >= 17 && time < 20))
            fare = fare * 1.2;

        // Minimum fare check
        if(fare < 20)
            fare = 20;

        // Store lowest/highest fare
        if(i == 1 || fare < lowest)
            lowest = fare;
        if(i == 1 || fare > highest)
            highest = fare;

        total += fare;

        printf("Passenger: %s | Base Fare: ₹%.0f | Final Fare: ₹%.0f\n", name, base_fare, fare);
    }

    printf("\n========= Daily Summary =========\n");
    printf("Total Passengers: %d\n", n);
    printf("Total Revenue Collected: ₹%.0f\n", total);
    printf("Highest Fare: ₹%.0f\n", highest);
    printf("Lowest Fare: ₹%.0f\n", lowest);
    printf("==================================\n");
    return 0;
}


