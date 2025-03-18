#include <Servo.h>
const int trigpin =10;
const int echopin =11;
const int buzzer =7;
const int led =8;
long duration;
int distance;
Servo myServo;


void setup() {
  pinMode(10,OUTPUT);
  pinMode(11,INPUT);
   pinMode(8,OUTPUT);
   pinMode(7, OUTPUT);
  Serial.begin(9600);
  myServo.attach(12);
  pinMode(9, OUTPUT);
  // put your setup code here, to run once:

}

void loop() {
  for(int i=15;i<=165;i++)
  {
  myServo.write(i);
  delay(30);
  distance = calculateDistance();
  Serial.print(i);
  Serial.print(",");
  Serial.print(distance);
  Serial.print(".");
   if (distance > 0 && distance <= 50) { // Intruder detected
      digitalWrite(buzzer, HIGH);
      digitalWrite(led, HIGH);
    } else {
      digitalWrite(buzzer, LOW);
      digitalWrite(led, LOW);
    }
   } // put your main code here, to run repeatedly:

}
int calculateDistance(){
digitalWrite(10,LOW);
delayMicroseconds(2);
digitalWrite(10, HIGH);
duration = pulseIn(11,HIGH);
distance = duration*0.034/2;
return distance;

}