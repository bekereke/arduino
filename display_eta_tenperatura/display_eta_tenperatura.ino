#include <Wire.h>
#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
float temperatura;
int analog_pin=0;

byte customChar[8] = { //array 8 lerrotakoa
    B11100,
    B11100,
    B11100,
    B00000,
    B00000,
    B00000,
    B00000,
    B00000
};

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  
  // registro el nuevo caracter
  lcd.createChar(0, customChar); //0-7 bitarteko zenbaki batekin zehaztu! HORREK ADIERAZI 8 KARAKTERE DESBERDIN DEFINI DITZAKEGULA BAKARRIK
  // escribo el nuevo caracter en pantalla: (CHAR)0 
  
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setBacklight(HIGH);
  temperatura=analogRead(analog_pin);
  temperatura=5.0*temperatura*100.0/1024.0;
  lcd.setCursor(0,0);
  lcd.print("Temperatura: ");
  lcd.setCursor(9,1);
  lcd.print(temperatura);
  lcd.println("  C"+(char)0);
  delay(1000);
  
  /* //iluminacion alta lcd pantalline
  lcd.setCursor(0,0); //colocamos el cursor en la posicion 0,0
  lcd.print("Izena: "); //mostremos el texto en pantalla
  lcd.setCursor(3,1); //colocamos el cursor en la posicion 3,1. la manera de mover el cursor
  lcd.print(temperatura); //mostraremos el texto recibido por el puerto serie
  lcd.setCursor(9,1);
  lcd.print((char)0);
  lcd.setCursor(10,1);
  lcd.print("C");*/
}
