#include <stdio.h>  


typedef enum {
    TEMP_FREEZING,
    TEMP_NORMAL,
    TEMP_OVERHEAT
  } TempStatus;

TempStatus  classifyTemp(float t){

    if(t >30){
        return TEMP_OVERHEAT;
    }
    else if (t >= 0 && t <= 30){

        TEMP_NORMAL;
    }
    else {
        return TEMP_FREEZING;
    }
}

void printstatus(TempStatus s){

    switch (s){

        case TEMP_FREEZING:
        printf("FREEZING \n");
        break;

        case TEMP_NORMAL:

        printf("TEMP NORMAL\n");
        break;

        case TEMP_OVERHEAT:
        printf("TEMP OVERHEAT!\n");
        break;

    }




}


int main(){

    float testTemp = 42.0;
    TempStatus result = classifyTemp(testTemp);
    printstatus(result);
}


