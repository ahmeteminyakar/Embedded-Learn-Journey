#include <stdio.h>

int main() {
    float temps[5];  // array to store 5 temps
    int i;

    // Input loop
    for (i = 0; i < 5; i++) {
        printf("Enter temperature %d: ", i + 1);
        if (scanf("%f", &temps[i]) != 1) {
            printf("Invalid input!\n");
            return 1;
        }
    }

    printf("\n--- Logged Temperatures ---\n");

    float sum = 0.0;
    for (i = 4; i >= 0; i--) {
        printf("Temp %d: %.2f °C\n", i + 1, temps[i]);
        sum += temps[i];  // accumulate for average

        if (temps[i] > 35.0) {
            printf("⚠️  ALERT: Temp %d is above safe threshold!\n", i + 1);
        }
    }

    float avg = sum / 5.0;
    printf("\nAverage Temperature: %.2f °C\n", avg);




    return 0;
}

