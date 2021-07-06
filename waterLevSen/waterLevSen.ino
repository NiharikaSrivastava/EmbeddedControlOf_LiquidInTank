#include <LiquidCrystal.h>

 #define trigger 10  //PIN Numbers for Connection
 #define echo 11
 #define motor 12
 #define buzzer 8

LiquidCrystal lcd(7,6,5,4,3,2);

float time=0, distance=0, height=0, temp=100, m=0;

void setup() 
{
  lcd.begin(16,2);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(motor, OUTPUT);
  pinMode(buzzer, OUTPUT);
  lcd.print("  Water Level   ");
  lcd.setCursor(0,1);
  lcd.print("  Controller    ");
  delay(2000);
}

void loop() 
{
  lcd.clear();
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  time=pulseIn(echo, HIGH);
  distance=time*340/20000;
  height=(distance-25)*-1;
  lcd.clear();
  delay(500);
  lcd.print("Water Level In ");
  lcd.setCursor(0,1);
  lcd.print("Tank is: ");
  lcd.print(height);
  lcd.print("cm");
  delay(2000);
  
 //Displaying WATER Level Status of TANK and accordingly turning the Motor ON (for filling more water) and OFF 
 if(distance<=7 && temp==0) //going up - WATER TANK FULL
 {
     digitalWrite(motor, LOW);
     lcd.clear();
     lcd.print("Water Tank Full ");
     lcd.setCursor(0,1);
     lcd.print("Motor Turned OFF");
     temp=100; 
     if (m==0)
     {
       digitalWrite(buzzer, HIGH);
       delay(999);
       digitalWrite(buzzer, LOW);
       delay(1);
       m=1;
     }  
     else
     {
      delay(1000); 
     }
 }

 else if(distance<=7 && temp==100) //returning 
 {
     digitalWrite(motor, LOW);
     lcd.clear();
     lcd.print("Water Tank Full ");
     lcd.setCursor(0,1);
     lcd.print("Motor Turned OFF");
     temp=100;
     if (m==0)
     {
       digitalWrite(buzzer, HIGH);
       delay(999);
       digitalWrite(buzzer, LOW);
       delay(1);
       m=1;
     }  
     else
     {
      delay(1000); 
     }
 }

 else if(distance>7 && distance<=10 && temp==0) //going up - TANK ALMOST FULL
 {
     digitalWrite(motor, HIGH);
     lcd.clear();
     lcd.print("Tank Almost Full");
     lcd.setCursor(0,1);
     lcd.print("Motor Turned ON");
     digitalWrite(buzzer, HIGH);
     delay(100);
     digitalWrite(buzzer, LOW);
     delay(900);
 }

 
 else if(distance>7 && distance<=10 && temp==100) //returning
 {
     m=0;
     digitalWrite(motor, LOW);
     lcd.clear();
     lcd.print("Tank Almost Full");
     lcd.setCursor(0,1);
     lcd.print("Motor Turned OFF");
     delay(1000);
 }

 else if(distance>10 && distance<=12 && temp==100) //going up - TANK HALF FULL
 {
   digitalWrite(motor, HIGH);
   lcd.clear();
   lcd.print("Tank Half Full");
   lcd.setCursor(0,1);
   lcd.print("Motor Turned ON");
   temp=0;
   digitalWrite(buzzer, HIGH);
   delay(100);
   digitalWrite(buzzer, LOW);
   delay(900);
 }


 else if(distance>10 && distance<=12 && temp==0)//returning
 {
   digitalWrite(motor, HIGH);
   lcd.clear();
   lcd.print("Tank Half Full");
   lcd.setCursor(0,1);
   lcd.print("Motor Turned ON");
   temp=0;
   digitalWrite(buzzer, HIGH);
   delay(100);
   digitalWrite(buzzer, LOW);
   delay(900);
 }
 
 else if(distance>12 && distance<=17 && temp==100) //going up - WATER LEVEL LOW
 {
   digitalWrite(motor, HIGH);
   lcd.clear();
   lcd.print("Water Level Low");
   lcd.setCursor(0,1);
   lcd.print("Motor Turned ON");
   digitalWrite(buzzer, HIGH);
   delay(100);
   digitalWrite(buzzer, LOW);
   delay(900);
 }

 else if(distance>12 && distance<=17 && temp==0) //returning 
 {
   digitalWrite(motor, HIGH);
   lcd.clear();
   lcd.print("Water Level Low");
   lcd.setCursor(0,1);
   lcd.print("Motor Turned ON");
   digitalWrite(buzzer, HIGH);
   delay(100);
   digitalWrite(buzzer, LOW);
   delay(900);
 }

 else if(distance>17 && distance<=20 && temp==100) //going up - TANK ALMOST EMPTY
 {
   digitalWrite(motor, HIGH);
   lcd.clear();
   lcd.print("Almost Empty");
   lcd.setCursor(0,1);
   lcd.print("Motor Turned ON");
   digitalWrite(buzzer, HIGH);
   delay(100);
   digitalWrite(buzzer, LOW);
   delay(900);
 }

 else if(distance>17 && distance<=20 && temp==0) //returning
 {
   digitalWrite(motor, HIGH);
   lcd.clear();
   lcd.print("Almost Empty");
   lcd.setCursor(0,1);
   lcd.print("Motor Turned ON");
   digitalWrite(buzzer, HIGH);
   delay(100);
   digitalWrite(buzzer, LOW);
   delay(900);
 }

 else if(distance>20 && temp==100) //going up - TANK EMPTY
 {
   digitalWrite(motor, HIGH);
   lcd.clear();
   lcd.print("Tank is Empty");
   lcd.setCursor(0,1);
   lcd.print("Motor Turned ON");
   digitalWrite(buzzer, HIGH);
   delay(500);
   digitalWrite(buzzer, LOW);
   delay(500);
 }

 else if(distance>20 && temp==0) //returning
 {
   digitalWrite(motor, HIGH);
   lcd.clear();
   lcd.print("Tank is Empty");
   lcd.setCursor(0,1);
   lcd.print("Motor Turned ON");
   digitalWrite(buzzer, HIGH);
   delay(500);
   digitalWrite(buzzer, LOW);
   delay(500);
 }
}
