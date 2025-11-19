#include <stdio.h>

#define MAX 30

// Function to take input
void inputData(int id[], int speed[], int lane[], int *n) {
    int i;
    printf("How many vehicles? (max 30): ");
    scanf("%d", n);

    if (*n > MAX) *n = MAX;

    for (i = 0; i < *n; i++) {
        printf("\nVehicle %d ID: ", i+1);
        scanf("%d", &id[i]);

        printf("Speed: ");
        scanf("%d", &speed[i]);

        printf("Lane (1-4): ");
        scanf("%d", &lane[i]);
    }
}

// Count speed violations
int countSpeedViolations(int speed[], int n) {
    int i, count = 0;
    for (i = 0; i < n; i++)
        if (speed[i] > 80)
            count++;
    return count;
}

// Count lane violations
int countLaneViolations(int id[], int lane[], int n) {
    int i, count = 0;
    for (i = 0; i < n; i++)
        if (id[i] % 4 != lane[i])
            count++;
    return count;
}

// Find busiest lane
int busiestLane(int count[]) {
    int i, max = 0;
    for (i = 1; i < 4; i++)
        if (count[i] > count[max])
            max = i;
    return max + 1;
}

// Find least busy lane
int leastBusyLane(int count[]) {
    int i, min = 0;
    for (i = 1; i < 4; i++)
        if (count[i] < count[min])
            min = i;
    return min + 1;
}

// Display report
void displayReport(int id[], int speed[], int lane[], int n) {
    int i;
    printf("\nVehID  Speed  Lane  SpeedV  LaneV\n");
    for (i = 0; i < n; i++) {
        int sp = (speed[i] > 80) ? 1 : 0;
        int ln = (id[i] % 4 != lane[i]) ? 1 : 0;

        printf("%d   %d     %d      %d       %d\n",
               id[i], speed[i], lane[i], sp, ln);
    }
}

int main() {
    int id[MAX], speed[MAX], lane[MAX];
    int laneCount[4] = {0};
    int n, i;

    inputData(id, speed, lane, &n);

    // Count per lane
    for (i = 0; i < n; i++) {
        laneCount[lane[i] - 1]++;
    }

    int spV = countSpeedViolations(speed, n);
    int lnV = countLaneViolations(id, lane, n);

    int busy = busiestLane(laneCount);
    int least = leastBusyLane(laneCount);

    displayReport(id, speed, lane, n);

    printf("\nTotal Speed Violations = %d", spV);
    printf("\nTotal Lane Violations  = %d", lnV);
    printf("\nBusiest Lane = %d", busy);
    printf("\nLeast Busy Lane = %d", least);
    printf("\nTotal Vehicles = %d\n", n);

    return 0;
}

