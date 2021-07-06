#include <Arduino.h>

uint8_t powerOutput;
boolean butState;

void setup() {
  pinMode(A0, INPUT);
  pinMode(12, INPUT_PULLUP);
  pinMode(3, OUTPUT);
  butState = false;

  Serial.begin(9600);
}

void loop() {
  if(digitalRead(12) == LOW && butState == false){
    ;;Serial.println(digitalRead(12));
    while(digitalRead(12) == LOW){
      ;
    }
    delay(100);
    butState = true;
    while(butState == true){
      powerOutput = analogRead(A0) / 4;
      analogWrite(3, powerOutput);
      butState = digitalRead(12);
      Serial.println(powerOutput);
    }
    analogWrite(3, 0);
    Serial.println("STOP");
    while(digitalRead(12) == LOW){
      ;
    }
    delay(100);
  }
}