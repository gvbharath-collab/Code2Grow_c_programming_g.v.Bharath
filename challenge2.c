//the smart bill splitter
#include<stdio.h>
int main()
{
float meal_cost,tax,tip,total_bill,person1_pays,person2_pays;
//take meal cost as input
printf("enter meal cost");
scanf("%f",&meal_cost);


//given tax=0.05 tip=0.10

tax=meal_cost*0.05;
tip=meal_cost*0.10;

total_bill=meal_cost+tax+tip;

person1_pays=total_bill/2.0;
person2_pays=person1_pays;


printf("Each person should pay as following");
printf("Friend 1:%2f\n",person1_pays);
printf("friend 2:%2f\n",person2_pays);
printf("Friend 3:0.00\n");

return 0;
}
