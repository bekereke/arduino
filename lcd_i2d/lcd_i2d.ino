#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); // set the LCD I2C address

String datuak;
char c;

void setup() {
  datuak="";
  //c='';
  
  //abiarazi teklatua (monitor serie delakoa)
  Serial.begin(9600); //9600 baudio
  lcd.begin(16, 2); //pantaila: adierazi 2 lerro dituela bakoitza 8 karaktereduna
}

void loop() {
  while (Serial.available()){
    delay(10);
    if (Serial.available() > 0){
      c = Serial.read();
      datuak = datuak + c;
      lcd.clear(); //datu bat jasotzen den bakoitzeko pnataila ezabatu
    }  
  }
  lcd.setBacklight(HIGH); //distira altua
  lcd.setCursor(0, 0); //kurtsorea 0,0 puntuan (karakterea, lerroa) --> lerroa==0 edo lerroa==1
  lcd.print("Izena: "); //pantailan 
  lcd.setCursor(3, 1); //beheko lerroan (1)
  lcd.print(datuak); //serie portutik jasotako datua inprimatu
  datuak="";
}
