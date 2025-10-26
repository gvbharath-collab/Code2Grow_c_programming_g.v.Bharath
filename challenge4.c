//smart studennt grading system
#include<stdio.h>
int main()
{

int tel,hin,eng,mat,sci,total;
float percentage,attendance_percentage;

//take input of five marks
printf("\n max marks is 100 for each subject");
printf("\n enter telugu marks");
scanf("%d",&tel);

printf("enter hindi marks");
scanf("%d",&hin);

printf("enter English marks");
scanf("%d",&eng);

printf("enter maths marks");
scanf("%d",&mat);

printf("enter science marks");
scanf("%d",&sci);

//take attendance as input
printf("\nenter attendace percentage");
scanf("%f",&attendance_percentage);


total=tel+hin+eng+mat+sci;

printf("\ntotal marks is %d",total);
percentage=total/5.0;

printf("\nTotal percentage is %f",percentage);

//checking attendance percent
if(attendance_percentage<75)
{
printf("marked as failed due to low attendance");
}
else if(percentage>=45 && percentage<50 && attendance_percentage>=90)
total+=5;



printf("\n Attendance percentage is %f",attendance_percentage);


//declaring grade according to marks
if(percentage>=90)
{
printf("\nGrade :A+");
printf("\nRermarks:Excellent");
}
else if(percentage<=89 && percentage>=80)
{
printf("\nGrade:A");
printf("\nRemarks:Very good");
}
else if(percentage<=79 || percentage>=70)
{
printf("\nGrade:B");
printf("\nRemarks:Good");
}
else if (percentage<=69 || percentage>=60)
{
printf("\nGrade:C");
printf("\nRemarks:Average");
}
else if(percentage<=59 || percentage>=50)
{
printf("\nGrade:D");
printf("\nRemarks:Pass");
}
else
{
printf("\nGrade:F");
printf("\nRemarks:Fail");
}

return 0;

}






























