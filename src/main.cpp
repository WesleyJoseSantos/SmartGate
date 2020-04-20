#include <Arduino.h>
#include <HC06.h>

HC06 hc06 = HC06(A1, A2);

void setup(){
  Serial.begin(9600);
  hc06.setup("SmartGate", "1234", 9600);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
}

void loop(){
  if(hc06.available()){
    Serial.println("Data recieved");
    if(hc06.read() == 'a'){
      digitalWrite(12, HIGH);
      delay(500);
      digitalWrite(12, LOW);
    }
  }
}