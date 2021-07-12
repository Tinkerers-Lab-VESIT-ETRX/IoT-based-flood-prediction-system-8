#include<LiquidCrystal.h>
LiquidCrystal lcd(2,3,4,5,6,7);

float t = 0;
float dist = 0;
void setup() {
   lcd.begin(16,2);
 pinMode(18,OUTPUT); //trigger pin
 pinMode(19,INPUT);  //echo pin
 pinMode(20,OUTPUT); //buzzer
 lcd.setCursor(0,1);
 lcd.print(" Water Level Detector");
 delay(2000);

}

void loop() {
   lcd.clear();
 digitalWrite(20,LOW);
 digitalWrite(18,LOW);
 delayMicroseconds(2);
 digitalWrite(18,HIGH);
 delayMicroseconds(10);
 digitalWrite(18,LOW);
 delayMicroseconds(2);

 t=pulseIn(19,HIGH);
 dist=t*340/20000;

 lcd.clear();
 lcd.setCursor(0,1);
 lcd.print("Distance : ");
 lcd.print(dist/100);
 lcd.print(" m");
 delay(1000);

if(dist<40)
{
 digitalWrite(20,HIGH);
 lcd.clear();
 lcd.setCursor(0,1);
 lcd.print("Water level is rising. Kindly evacuate");
 delay(2000);
}
else
{
 digitalWrite(20,LOW);
 delay(2000);
}

}
