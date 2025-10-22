//the salary slip generator
#include<stdio.h>
int main()
{
float basic_salary,hra_percent,da_percent,tax_percent;
float hra,da,tax,gross_salary;
int  a;
printf("Enter Basic salary");
scanf("%f",&basic_salary);

printf("Enter HRA percent");
scanf("%f",&hra_percent);

printf("enter DA percent");
scanf("%f",&da_percent);

printf("enter TAX percent");
scanf("%f",&tax_percent);


hra=basic_salary*(hra_percent/100);
da=basic_salary*(da_percent/100);
tax=basic_salary*(tax_percent/100);
gross_salary=basic_salary+hra+da-tax;


a=gross_salary>50000;
//here it is logical operator which gives 1 for true and 0 for false


printf("hra is %.2f\n",hra);
printf("da is %.2f\n",da);
printf("tax is %.2f\n",tax);
printf("gross salary is %.2f\n",gross_salary);
printf("is gross salary above 50000? %d\n",a);

return 0;
}

