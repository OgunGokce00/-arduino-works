int pot = A0;
int trn=9;
int potval ;

void setup() {
  pinMode(trn,OUTPUT);



}

void loop() {
  potval=analogRead(pot) /4;

  analogWrite(trn,potval);

  

}
