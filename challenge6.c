#include <stdio.h>

int main() {
// Declare variables
float data_used, base_cost = 0, extra_data = 0, extra_cost = 0, total = 0, discount = 0;
int student, corporate;


// Input
printf("Enter total data used (GB): ");
scanf("%f", &data_used);

// If usage exceeds 100 GB, exit with error message
if (data_used > 100) {
        printf("Excessive Usage – Plan Not Allowed\n");
        return 0;
    }
printf("Are you a student? (1-Yes / 0-No): ");
scanf("%d", &student);

printf("Corporate user? (1-Yes / 0-No): ");
scanf("%d", &corporate);


// Plan selection & cost calculation
if (data_used < 30) 
{
  base_cost = 299;
  extra_data = (data_used > 1 * 30) ? data_used - 30 : 0;
  extra_cost = extra_data * 50;
  printf("Selected Plan: Silver\n");
}
 else if (data_used <= 60) 
{
        base_cost = 499;
        extra_data = (data_used > 2 * 30) ? data_used - 60 : 0;
        extra_cost = extra_data * 40;
        printf("Selected Plan: Gold\n");
}
 else 
{
        base_cost = 799;
        extra_data = (data_used > 3 * 30) ? data_used - 90 : data_used - 60;
        if (extra_data < 0) extra_data = 0;
        extra_cost = extra_data * 30;
        printf("Selected Plan: Platinum\n");
}
total = base_cost + extra_cost;

// Discount logic (apply higher one)
if (student == 1 && corporate == 1) 
{
      discount = (0.15 > 0.10) ? 0.15 : 0.10;
}
else if (student == 1) 
{
        discount = 0.15;
}
else if (corporate == 1) 
{
   discount = 0.10;
} 
else 
{
        discount = 0.0;
}

 // Bill after discount
float final_bill = total * (1 - discount);

// Output summary
printf("User Plan Summary:\n");
printf("Data Used: %.0f GB\n", data_used);
printf("Base Cost: %.2f\n", base_cost);
printf("Extra Data: %.0f GB\n", extra_data);
printf("Total (before discount): %.2f\n", total);
printf("Discount Applied: %.0f%%\n", discount * 100);
printf("Final Bill: %.2f\n", final_bill);

return 0;
}