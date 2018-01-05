String datua;
int tartea;
char c;


void display (int a, int b, int c, int d, int e, int f, int g) {
  digitalWrite (7,a);  
  digitalWrite (8,b);  
  digitalWrite (9,c);  
  digitalWrite (10,d);  
  digitalWrite (11,e);
  digitalWrite (12,f);
  digitalWrite (13,g);
}

void setup() {
  tartea=1000;
  datua="";
  
  Serial.begin(9600);  //display abiarazi
  
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  while (Serial.available()) {
    delay(10);
    if (Serial.available() > 0) {
      c = Serial.read();
      datua = datua + c; //datua +=c;
    }
  }
  if (datua.length() > 0){
    switch (datua.toInt()) {  //casting bat int zenbakietara bihurtzeko
      case 0: 
       Serial.println("Piztu " + datua + " zenbakia"); //LED gorria piztu
        display (1,1,1,1,1,1,0);
        delay(tartea); 
        break;
      case 1: 
       Serial.println("Piztu " + datua + " zenbakia"); //LED gorria piztu
        display (0,1,1,0,0,0,0);
        delay(tartea); 
        break;
      case 2: 
       Serial.println("Piztu " + datua + " zenbakia"); //LED gorria piztu
        display (1,1,0,1,1,0,1);
        delay(tartea); 
        break;  
      case 3: 
       Serial.println("Piztu " + datua + " zenbakia"); //LED gorria piztu
        display (1,1,1,1,0,0,1);
        delay(tartea); 
        break;  
      case 4: 
        Serial.println("Piztu " + datua + " zenbakia"); //LED gorria piztu
        display (0,1,1,0,0,1,1);
        delay(tartea); 
        break; 
      case 5: 
        Serial.println("Piztu " + datua + " zenbakia"); //LED gorria piztu
        display (1,0,1,1,0,1,1);
        delay(tartea); 
        break;   
      case 6: 
        Serial.println("Piztu " + datua + " zenbakia"); //LED gorria piztu
        display (1,0,1,1,1,1,1);
        delay(tartea); 
        break; 
      case 7: 
        Serial.println("Piztu " + datua + " zenbakia"); //LED gorria piztu
        display (1,1,1,0,0,0,0);
        delay(tartea); 
        break;  
      case 8: 
        Serial.println("Piztu " + datua + " zenbakia"); //LED gorria piztu
        display (1,1,1,1,1,1,1);
        delay(tartea); 
        break;  
      case 9: 
        Serial.println("Piztu " + datua + " zenbakia"); //LED gorria piztu
        display (1,1,1,1,0,1,1);
        delay(tartea); 
        break;     
      default: 
        break; 
    }
  }
  datua="";
}
