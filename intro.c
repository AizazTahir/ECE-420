
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>


int main() {
    int n = 100; // Size of the array
    double a[n]; // Array to hold values
    double sum = 0.0; // Variable to store the final sum

    // Initialize the array with some values
    for(int i = 0; i < n; i++) {
        a[i] = i + 1; // Example values
    }

    // Parallel region begins
    #pragma omp parallel
    {
        double partial_sum = 0.0; // Each thread has its own partial sum

        // Divide the loop among the threads
        #pragma omp for
        for(int i = 0; i < n; i++) {
            partial_sum += a[i]; // Calculate partial sum
        }

        // Critical section to update the global sum
        #pragma omp critical
        sum += partial_sum;
    } // Parallel region ends

    printf("Total sum is %f\n", sum);

    return 0;
}
