#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>
#include <stdbool.h>

void transpose(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[i]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void transposition_sort(int arr[], int size) {
    bool sorted = false;
    int cycle = 0;

    while (!sorted) {
        sorted = true;

        #pragma omp parallel for shared(arr, size, sorted)
        for (int i = 0; i < size - cycle; i++) {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                sorted = false;
            }
        }

        cycle++;
    }
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    srand(time(NULL));

    printf("Populating the array with random numbers...\n");
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 1000;  // Random numbers between 0 and 999
    }

    double start_time = omp_get_wtime();

    transposition_sort(arr, size);

    double end_time = omp_get_wtime();
    double execution_time = end_time - start_time;

    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Execution time: %f seconds\n", execution_time);

    return 0;
}