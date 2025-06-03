#include <stdio.h>

typedef enum {
  TEMP_FREEZING,
  TEMP_NORMAL,
  TEMP_OVERHEAT
} TempStatus;

typedef struct {
  float value;
  TempStatus status;
} SensorReading;

TempStatus classifyTemp(float t);
void printstatus(TempStatus s);

int main() {
  SensorReading readings[3];
  float sum = 0;
  float max = -1000;
  int overheatcount = 0; 
   for (int i =0; i <3 ; i++){

    printf("Enter Temperature %d ", i+1);

    scanf("%f" , &readings[i].value);

    sum += readings[i].value;

    readings[i].status = classifyTemp(readings[i].value);
    printstatus(readings[i].status);


    if (readings[i].value > max){

        max = readings[i].value;

    }

    if(readings[i].status == TEMP_OVERHEAT){

        overheatcount++;
    }


   }




    float avg = sum/3;   

    printf("SYSTEM REPORT\n");
    printf("Max Temp : %.2f\n" , max);
    printf("Average Temp : %.2f\n", avg);
    if (overheatcount >= 2){
        printf("Environment Unstable!");

    }

    return 0 ;
}

TempStatus classifyTemp(float t){
    if (t>30){

        return TEMP_OVERHEAT;

    }

    else if (t>= 0){

        return TEMP_NORMAL;

    }
    else {

        return TEMP_FREEZING;

    }

}

void printstatus(TempStatus s){

    switch (s){

        case TEMP_OVERHEAT:
            printf("OVERHEAT!\n");
            break;
        
        
        case TEMP_NORMAL:

            printf("NORMAL TEMP\n");
            break;

        case TEMP_FREEZING:

            printf("FREEZING TEMP\n");
            break;

        }
    }

