#include <stdio.h>
#include <omp.h>

int main() {
    int array_size, num_thread = 4;
    printf("Enter the size of the array: ");
    scanf("%d", &array_size);

    int arr[array_size];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < array_size; i++) {
        scanf("%d", &arr[i]);
    }

    int sum = 0;

    #pragma omp parallel num_threads(num_thread)
    {
        int threadID = omp_get_thread_num();
        int lsum = 0;

        #pragma omp for
        for (int i = 0; i < array_size; i++) {
            lsum += arr[i];
        }

        #pragma omp critical
        {
            sum += lsum;
            printf("Thread %d: sum = %d\n", threadID, lsum);
        }
    }

    printf("Sum of the array elements is: %d\n", sum);
    return 0;
}