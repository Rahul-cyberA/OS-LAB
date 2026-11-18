#include <stdio.h>

int main()
{
    int n, bt[20], wt[20], tat[20];
    float avgwt = 0, avgtat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);
    if (n < 1 || n > 20) return 1;

    for (int i = 0; i < n; i++) {
        printf("Burst time of P%d: ", i + 1);
        scanf("%d", &bt[i]);
        if (bt[i] < 0) return 1;
    }

    wt[0] = 0;
    for (int i = 1; i < n; i++)
        wt[i] = wt[i - 1] + bt[i - 1];

    printf("\nProcess\tBT\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
        avgwt += wt[i];
        avgtat += tat[i];
        printf("P%d\t%d\t%d\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }
    printf("Average waiting time = %.2f\n", avgwt / n);
    printf("Average turnaround time = %.2f\n", avgtat / n);
    return 0;
}
