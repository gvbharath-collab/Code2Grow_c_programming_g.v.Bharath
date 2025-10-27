#include<stdio.h>
int main()
{
int age,health;
char gender;
float premium=0;


//take inputs of age,gender and health condition
printf("Enter age");
scanf("%d",&age);

printf("\nEnter gender (M/F):");

scanf(" %c",&gender);

printf("\nHealth condition (1-Healthy/0-Unhealthy):");
scanf("%d",&health);



//output to show customer details which we have taken
printf("\n Customer Details:\n");
printf("Age: %d\n",age);
printf("Gender : %c \n",gender);
printf("Health: %s", (health==1)?"Healthy" : "Unhealthy");





//premium calculation
if (age<25)
{
 if(health==1)
  premium= 5000;
else
printf("Status: Not Eligilble for Insurance\n");
}
else if(age>=25 && age<=40)
{
  if(health==1)
  premium = 7000;
else
premium=9500;
}

else if (age>=41 && age<=60)
{
if (health==1)
premium=10000;
else
premium=13000;
}
else if (age>60)
{
if(health==1)
premium=15000;
else
{
printf("\nstatus: not Eligible for insurance\n");
return 0;
}
}

//10% discount for female customers
if(premium>0)
{
if(gender == 'F' || gender =='f')
   premium =premium -(premium*0.10);


//output statements
printf("Final Premium: %.2f\n",premium);

return 0;

}
}













