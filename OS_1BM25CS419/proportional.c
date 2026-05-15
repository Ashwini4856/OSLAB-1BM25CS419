#include <stdio.h>

int main() {
    int n, i, completed = 0, time = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int burst[n], weight[n], remaining[n];
    int totalWeight = 0;

    for(i = 0; i < n; i++) {
        printf("Enter Burst Time and Weight for Process P%d: ", i + 1);
        scanf("%d %d", &burst[i], &weight[i]);
        remaining[i] = burst[i];
        totalWeight += weight[i];
    }

    printf("\nExecution Order:\n");

    while(completed < n) {
        for(i = 0; i < n; i++) {
            if(remaining[i] > 0) {

                int slice = weight[i];

                if(remaining[i] < slice)
                    slice = remaining[i];

                printf("P%d executes for %d units (Time %d -> %d)\n",
                       i + 1, slice, time, time + slice);

                time += slice;
                remaining[i] -= slice;

                if(remaining[i] == 0)
                    completed++;
            }
        }
    }

    printf("\nAll processes completed at time %d\n", time);

    return 0;
}
