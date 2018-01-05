// the setup function runs once when you press reset or power the board
int egoera=0;
void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT); //LED irteera digitalera
  pinMode(4, INPUT);
  digitalWrite(13, LOW);
}

// the loop function runs over and over again forever
void loop() {
  if (digitalRead(13)==1){ //pultsadorea sakatu bada
    if (egoera == 0){
      digitalWrite(13, HIGH); //piztu
      Serial.println  
    }
  }
}
