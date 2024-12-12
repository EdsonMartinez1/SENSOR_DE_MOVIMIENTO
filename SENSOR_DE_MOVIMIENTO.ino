#include <EEPROM.h>  

int pirPin = 2;       
int ledPin = 13;      
int ledPin2 = 12;     
int motionCount = 0;        
void setup() {
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  Serial.begin(9600);
  motionCount = EEPROM.read(0) | (EEPROM.read(1) << 8);
  Serial.print("Movimiento inicial detectado: ");
  Serial.println(motionCount);
}
void loop() {
  int val = digitalRead(pirPin);

  if (val == HIGH) {
    digitalWrite(ledPin, HIGH);
    digitalWrite(ledPin2, LOW);

    motionCount++;  
    Serial.print("eeeyyyy al tiro padre! llevas total: ");
    Serial.print(motionCount);
    Serial.println(" movimientos");
    EEPROM.write(0, motionCount & 0xFF);   
    EEPROM.write(1, (motionCount >> 8) & 0xFF);
    delay(2000);
  } else {
    digitalWrite(ledPin, LOW); 
    digitalWrite(ledPin2, HIGH);
  }

  delay(500);  
}