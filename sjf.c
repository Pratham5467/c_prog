#include <stdio.h>

void findWaitingTime(int processes[], int n, int bt[], int wt[]) {
    int rt[n];
    
    for (int i = 0; i < n; i++) {
        rt[i] = bt[i];
    }
    
    int complete = 0, t = 0, minm = 999999, shortest = 0, finish_time;
    wt[0] = 0;
    
    while (complete != n) {
        for (int j = 0; j < n; j++) {
            if (rt[j] > 0 && rt[j] < minm && t >= processes[j]) {
                minm = rt[j];
                shortest = j;
            }
        }
        
        rt[shortest] = 0;
        complete++;
        finish_time = t + bt[shortest];
        wt[shortest] = finish_time - bt[shortest] - processes[shortest];
        
        if (wt[shortest] < 0) {
            wt[shortest] = 0;
        }
        
        t = finish_time;
        minm = 999999;
    }
}

void findTurnaroundTime(int processes[], int n, int bt[], int wt[], int tat[]) {
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }
}

void findAverageTime(int processes[], int n, int bt[], int at[]) {
    int wt[n], tat[n];
    
    findWaitingTime(processes, n, bt, wt);
    findTurnaroundTime(processes, n, bt, wt, tat);
    
    float total_wt = 0, total_tat = 0;
    
    printf("Process\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, at[i], bt[i], wt[i], tat[i]);
    }
    
    float avg_wt = total_wt / n;
    float avg_tat = total_tat / n;
    
    printf("\nAverage Waiting Time = %.2f\n", avg_wt);
    printf("Average Turnaround Time = %.2f\n", avg_tat);
}

int main() {
    int n;
    
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    int processes[n];
    int burst_time[n];
    int arrival_time[n];
    
    printf("Enter the arrival time and burst time for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Arrival time for process %d: ", i + 1);
        scanf("%d", &arrival_time[i]);
        printf("Burst time for process %d: ", i + 1);
        scanf("%d", &burst_time[i]);
        processes[i] = i;
    }
    
    findAverageTime(processes, n, burst_time, arrival_time);
    
    return 0;
}
