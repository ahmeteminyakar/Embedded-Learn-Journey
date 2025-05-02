#include <stdio.h>


int main(){

    float temps[3];

    int overheatCount = 0;
    
    for(int i = 0; i < 3 ; i++){
        
        
        printf("Enter Temperature %d: " , i+1);

        if(scanf("%f" , &temps[i]) != 1){

            printf("Invalid Temperature!");
            return 1;

        }

        if (temps[i] > 30 ){

            printf("OVERHEAT! \n");
            overheatCount++;

        }

        if (temps[i] >=0 && temps[i] <= 30 ){

            printf("NORMAL \n");

        }

        if (temps[i] < 0 ){

            printf("FREEZING \n");

        }



    }

    if (overheatCount >= 2){

        printf("ENVIRONMENT UNSTABLE!");

    }
    


    



    return 0;
}