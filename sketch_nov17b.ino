#include <SoftwareSerial.h> 
SoftwareSerial blueTooth(3,2); 
int piezoPin= 8;
int ledPin= 9;

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  blueTooth.begin(9600);
  pinMode(piezoPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
}
int sequence = 0;
int   freq[ ] = {440/2, 494/2, 262, 294, 330, 349, 392, 440};

void loop() 
{
  // put your main code here, to run repeatedly:
  if (!blueTooth.available()) return;
  
  int cmd= blueTooth.read();
  Serial.println(cmd);
  if(cmd == 0)  return;

  if(cmd == 1){
    tone(piezoPin, freq[sequence++]);
    digitalWrite(ledPin, HIGH); 
    sequence %=8;
  }
  if(cmd == 2){
    noTone(piezoPin);
    digitalWrite(ledPin, LOW); 
  }
}
