#include<stdio.h>
int main()
{
int units;
float total_bill,meter_charge=50.0;

//taking input of how many units consumed
printf("enter total no of units consumed");
scanf("%d",&units);

//now bill calculation based on units

if(units<=100)
{
total_bill=units*3.0;
}
else if (units<=200)
{
total_bill=units*4.50;
}
else if(units<=300)
{
total_bill=units*6.0;
}
else
{
total_bill=units*8.0;
}

total_bill+=meter_charge;

//output statements
printf("\n Electricity Bill summary:\n");
printf("units consumed :%d\n",units);
printf("total bill is:%2f\n",total_bill);

return 0;

}

