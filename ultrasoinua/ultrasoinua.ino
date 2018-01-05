int trig=2;
int echo=4;
int dist=0;

void setup() {
  pinMode (trig, OUTPUT);
  pinMode (echo, INPUT);
  Serial.begin (9600);
}

void ultrasoinua (int  &distantzia){
  //seinale zaborrak saihestearren
  digitalWrite (trig, LOW);
  delay (10);

  //8 pultsu botako dira
  digitalWrite (trig, HIGH);
  delay (10);
  digitalWrite (trig, LOW);

  //pultsuak itzultzen egiten duten denbora neurtuko da, horrela distantzia lortzeko
  distantzia= pulseIn (echo, HIGH);
  distantzia= distantzia/60;

  delay (100);
}

void loop() {
  ultrasoinua(dist);
  Serial.println ("Distantzia: "+(String)dist+" cm");

  delay (250);
}
