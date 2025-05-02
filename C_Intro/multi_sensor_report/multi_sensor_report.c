#include <stdio.h>
#include <string.h>



char* classifyTemp(float t){

    if( t> 30){

        return "OVERHEAT!";

    }

    else if (t >= 0 && t <= 30){

        return "NORMAL TEMP";

    }

    else {

        return "FREEZING";


    }
}

char* classifyHumidity(float h){

    if (h >60){

        return "HUMIDITY CRITICAL!";
    }
    

    else if (h >= 20 && h <= 60){

        return "NORMAL HUMIDITY";

    }

    else {


        return "DRY AIR"; 

    }
}
char* classifyCo2(float co2){

    if (co2 > 800){
    
        return "CO2 DANGER!";
        }
        
    
    else if (co2 >= 400 && co2 <= 800){
    
        return "SAFE";
    
    }
    
    else {
    
    
            return "FRESH AIR"; 
    
    }    
}



int main(){

    float temps[3], humidity[3], co2[3];

    int tempsensorfailurecount = 0;
    int humiditysensorfailurecount = 0;
    int co2sensorfailurecount = 0;
    
    int criticalSensorCount = 0;

    for(int i = 0; i<3 ; i++){


        printf("Enter Temperature %d : " , i+1);

        if(scanf("%f" , &temps[i]) != 1){

            printf("INVALID TEMPERATURE!");
            return 1;

        }

        printf("Enter Humidity %d: " , i+1);

        if(scanf("%f" , &humidity[i]) != 1){

            printf("INVALID HUMIDITY!");
            return 1;
        }
        
        printf("Enter CO2 %d: " , i+1);

        if(scanf("%f" , &co2[i]) != 1){

            printf("INVALID CO2!");
            return 1;
        }

        char * tempstatus = classifyTemp(temps[i]);
        char * humiditystatus = classifyHumidity(humidity[i]);
        char * co2status = classifyCo2(co2[i]);


        if(strcmp(tempstatus , "OVERHEAT!") == 0){
            tempsensorfailurecount++;

        }
        
        if(strcmp(humiditystatus , "HUMIDITY CRITICAL!") == 0){
            humiditysensorfailurecount++;

        }
        
        if(strcmp(co2status , "CO2 DANGER!") == 0){
            co2sensorfailurecount++;

        }

        printf("%s \n", tempstatus);
        printf("%s \n", humiditystatus);
        printf("%s \n", co2status);
        

        

    }

    printf("\n--- SYSTEM SUMMARY ---\n");
    printf("🔥 Overheat Count: %d\n", tempsensorfailurecount);
    printf("💧 Humidity Critical Count: %d\n", humiditysensorfailurecount);
    printf("🫁 CO2 Danger Count: %d\n", co2sensorfailurecount);
    
    if (tempsensorfailurecount >= 2) criticalSensorCount++;
    if (humiditysensorfailurecount >= 2) criticalSensorCount++;
    if (co2sensorfailurecount >= 2) criticalSensorCount++;

    if (criticalSensorCount >= 2) {
    printf("\nSYSTEM FAILURE: MULTIPLE CRITICAL CONDITIONS\n");
}






return 0;

}

