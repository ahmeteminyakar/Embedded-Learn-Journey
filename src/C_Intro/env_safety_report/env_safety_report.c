#include <stdio.h>
#include <string.h>


char* classifyTemp(float t){

    if(t >30){
        return "OVERHEAT!";
    }
    else if (t >= 0 && t <= 30){

        return "NORMAL TEMPERATURE";
    }
    else {

        return "FREEZING";

    }

}


int main(){

    int overheatCount = 0;
    float temps[5];

    float max = -1000.0;
    float sum = 0;

    for(int i = 0; i< 5 ;i++){


        printf("Enter Temperature %d :" , i+1);

        if(scanf("%f" , &temps[i]) != 1){

            printf("Invalid Input!");
            return 1;

        }
        sum+= temps[i];

        char* tempstatus = classifyTemp(temps[i]);

        if (strcmp(tempstatus, "OVERHEAT!") == 0) {
            overheatCount++;
        }


        

        if(temps[i] > max){

            max = temps[i];
        }

        printf("%s\n" , tempstatus);

    }

    float avg = sum/5;

    printf("Average Temperature : %.2f \n" ,avg);

    printf("Max Temperature : %.2f \n" , max);
    if(overheatCount >= 2){

        printf("UNSTABLE ENVIRONMENT!\n");
    }



return 0;
}