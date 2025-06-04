#include <DHT.h>
#include <EEPROM.h>
#define LEDPIN 9
#define BUZZERPIN 10
#define DHTPIN 2
#define DHTTYPE DHT11
#define VENT_COUNTER_ADDR 0

DHT dht(DHTPIN , DHTTYPE);


enum state {IDLE , VENT_WAIT, VENT_ACTIVE};
state currentState = IDLE;

int ventCycleCounter = 0;

unsigned long stateEntryTime = 0;
const long threshold = 10000;
const long globalreset = 30000;



void setup (){

    Serial.begin(9600);
    dht.begin();
    pinMode(LEDPIN ,OUTPUT);
    pinMode(BUZZERPIN , OUTPUT);
    ventCycleCounter = EEPROM.read(VENT_COUNTER_ADDR);
    Serial.print("VENT CYCLE COUNT: ");
    Serial.println(ventCycleCounter);

}

void loop (){

    unsigned long now = millis();
    float temp = dht.readTemperature();
  

    if(isnan(temp)){

      Serial.println("SENSOR ERROR!");
      return;
    }


    Serial.print("TEMP :");
    Serial.println(temp);




    if(currentState == IDLE){

      digitalWrite(LEDPIN, LOW);
      digitalWrite(BUZZERPIN, LOW);

      if (temp >= 28){

        currentState= VENT_WAIT;
        stateEntryTime = now;
        Serial.println("transition : IDLE --> VENT_WAIT");

      }   
    }

    else if (currentState == VENT_WAIT){

      if(temp < 28 ){
        currentState = IDLE;
        Serial.println("transition : VENT_WAIT --> IDLE");
      }
      else if(temp >=  28){
        blinkLed();

        if(now - stateEntryTime >= threshold){
          currentState = VENT_ACTIVE;
          stateEntryTime = now;
          ventCycleCounter++;
          EEPROM.update(VENT_COUNTER_ADDR, ventCycleCounter);
          digitalWrite(BUZZERPIN , HIGH);
          Serial.println("transition : VENT_WAIT --> VENT_ACTIVE");
        }

      }

    }

    else if (currentState == VENT_ACTIVE){

      if(temp < 28){
        currentState = IDLE;
        stateEntryTime = now ;
        Serial.println("transition : VENT_ACTIVE --> IDLE");


      }
      else {

        digitalWrite(LEDPIN, HIGH);

      }

    }

if(now - stateEntryTime >= globalreset) {

    currentState= IDLE;
    Serial.println("transition : GLOBAL RESET --> IDLE");

}



}



void blinkLed() {
  if ((millis() / 500) % 2 == 0) {
    digitalWrite(LEDPIN, HIGH);
  } else {
    digitalWrite(LEDPIN, LOW);
  }
}