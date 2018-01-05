#include <Wire.h>
#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

int trig=3;
int echo=2;
int dist;

void ultrasoinua (int &distantzia) {
  digitalWrite(trig, LOW); //trig pina egonkortzeko LOW balioaz abiarazten da  
  delay(10);
  
  //8 pultso jaurti
  digitalWrite (trig, HIGH); //bidali
  delay(10);
  digitalWrite(trig, LOW); //eten bidalketa
  
  /*seinaleak itzultzeko behar duen denbora neurtuko da. 
  gero, segundu baten milaren partean 58 cm da soinuaren abiadura
  edo, segundu baten milaren partean 148 hatz-bete da soinuaren abiadura*/
  distantzia=pulseIn(echo, HIGH);
   Serial.print(distantzia);
  distantzia=distantzia/58;
  Serial.print(distantzia);
  
  lcd.setBacklight(HIGH);

  lcd.setCursor(0,0);
  lcd.print("Distantzia: ");
  lcd.setCursor(9,1);
  lcd.print(distantzia);
  lcd.print(" cm");
}

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  Serial.begin(9600);
    
  pinMode (trig, OUTPUT);
  pinMode (echo, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  ultrasoinua(dist);
  delay(250);
}
