#include <stdio.h>

int main()
{

    float temps[5];
    int i;

    for (i = 0; i < 5; i++){

        printf("Enter Temperature %d :", i + 1);

        if (scanf("%f", &temps[i]) != 1)
        {

            printf("Invalid input!");
            return 1;
        }

        if (temps[i] < 0.0) {
            printf("Temperature cannot be negative.\n");
            return 1;
        }
        


    }    

    printf("LOGGED TEMPERATURES\n");

    float sum = 0;
    float max = temps[0];
    int maxIndex = 0;
    float min = temps[0];
    int minIndex= 0;

    for (i = 0; i < 5; i++){
        

        printf("Temperature %d: \n  %.2f\n", i + 1, temps[i]);
        sum += temps[i];
        
        if(temps[i] > max){

            max = temps[i];
            maxIndex = i;
        }

        if(temps[i] < min){

            min = temps[i];
            minIndex = i;
        }

        if (temps[i] > 40.0) {
            printf("ALERT: Temp %d is above safe threshold!\n", i + 1);
        }

        


        if (temps[i] > 35){
            

                printf("OVERHEAT DETECTED!\n");
            }
    }

    float avg = sum / 5.0;

    printf("\n--- SYSTEM REPORT ---\n");
    printf("Average Temp: %.2f °C\n", avg);
    printf("Max Temp: %.2f °C (Sensor %d)\n", max, maxIndex + 1);
    printf("Min Temp: %.2f °C (Sensor %d)\n", min, minIndex + 1);   

     return 0;
    }

    