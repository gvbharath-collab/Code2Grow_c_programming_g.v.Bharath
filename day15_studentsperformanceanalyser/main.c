#include <stdio.h>
int main() {
    int n, i;
    int marks[10];
    int sum = 0, highest = -1, lowest = 101;
    int countAplus = 0, countA = 0, countB = 0, countC = 0, countD = 0, countFail = 0;
    int passCount = 0, failCount = 0;

    printf("========= Student Performance Analyzer =========\n");
    printf("Enter total number of students: ");
    scanf("%d", &n);

    if(n < 1 || n > 10) {
        printf("Number of students must be between 1 and 10.\n");
        return 1;
}
printf("Enter marks for each student:\n");
for(i = 0; i < n; i++) {
        printf("Student %d: ", i+1);
        scanf("%d", &marks[i]);
        sum += marks[i];

// Track highest and lowest
if(marks[i] > highest) highest = marks[i];
if(marks[i] < lowest) lowest = marks[i];

        // Grade counts and pass/fail
        if(marks[i] >= 90) { countAplus++; passCount++; }
        else if(marks[i] >= 80) { countA++; passCount++; }
        else if(marks[i] >= 70) { countB++; passCount++; }
        else if(marks[i] >= 60) { countC++; passCount++; }
        else if(marks[i] >= 50) { countD++; passCount++; }
        else { countFail++; failCount++; }
}

    

float avg = (float)sum / n;

   printf("========= Result Summary =========\n");
   printf("Average Marks: %.2f\n", avg);
   printf("Highest Marks: %d\n", highest);
   printf("Lowest Marks: %d\n", lowest);
   printf("Total Passed Students: %d\n", passCount);
   printf("Total Failed Students: %d\n", failCount);
   printf("Grade Distribution:\n");
   printf("A+ : %d\n", countAplus);
   printf("A  : %d\n", countA);
   printf("B  : %d\n", countB);
   printf("C  : %d\n", countC);
   printf("D  : %d\n", countD);
   printf("Fail: %d\n", countFail);
   printf("==================================\n");


return 0;
}
