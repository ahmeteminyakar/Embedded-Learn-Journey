#include <stdio.h>

char *classifyTemp(float t)
{

    if (t > 30)
    {
        return "Critical Temperature";
    }
    else
    {

        return "Normal Temperature";
    }
}

char *classifyHumidity(float h)
{

    if (h > 60)
    {

        return "Critical Humidty";
    }
    else
    {

        return "Normal Humidity";
    }
}

char* classifyCO2(float c)
{

    if (c > 800)
    {

        return "Critical CO2";
    }

    else
    {

        return "Normal CO2";
    }
}

int main()
{

    float temp;
    float humidity;
    float co2;

    printf("Enter the temperature: ");

    if (scanf("%f", &temp) != 1)
    {

        printf("Invalid number!");
        return 1;
    }

    printf("Enter the humidity: ");

    if (scanf("%f", &humidity) != 1)
    {

        printf("Invalid number!");
        return 1;
    }

    printf("Enter the CO2: ");

    if (scanf("%f", &co2) != 1)
    {

        printf("Invalid number!");
        return 1;
    }

    char *Tempstatus = classifyTemp(temp);
    char *Humiditystatus = classifyHumidity(humidity);
    char *CO2status = classifyCO2(co2);

    printf("%s\n", Tempstatus);
    printf("%s\n", Humiditystatus);
    printf("%s\n", CO2status);


    int criticalCount = 0;

    if (Tempstatus == "Critical Temperature")
        criticalCount++;
    if (Humiditystatus == "Critical Humidty")
        criticalCount++;
    if (CO2status == "Critical CO2")
        criticalCount++;

    if (criticalCount >= 2)
    {
        printf("⚠️ SYSTEM ALERT: At least two sensors are in critical condition!\n");
    }

return 0;    


}
