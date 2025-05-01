#include <stdio.h>


char* classifyTemp(float t) {
    if (t > 30) {
        return "Danger Level Heat!";
    } else {
        return "Temperature Normal.";
    }
}
 

    char* classifyHumidity(float h) {
        if (h > 30) {
            return "Danger Level Humidity!";
        } else {
            return "Humidity Normal.";
        }
    }
    

int main(){


        float temp;
        float humidity;

        printf("Enter Your Temperature :");

        if(scanf("%f", &temp)!= 1){

            printf("Invalid Number!");
            return 1;


        }
        
        printf("Enter Your Humidity : ");

        if(scanf("%f", &humidity)!= 1){

            printf("Invalid Number!");
            return 1;

        }

        char* Tempstatus = classifyTemp(temp);
        char* Humiditystatus = classifyHumidity(humidity);


        printf("%s\n", Tempstatus);
        printf("%s\n", Humiditystatus);

        if (temp > 30 && humidity > 30) {
            printf("⚠️ ALERT: Environment Unsafe!\n");
        }
    
    

return 0;

}