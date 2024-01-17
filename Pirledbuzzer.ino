int led = 8;
int buzzer = 9;
int pir = 10;
int deger;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(pir, INPUT);
}

void loop() {
  deger = digitalRead(pir);

  if (deger == LOW) {
    digitalWrite(led, LOW);
    digitalWrite(buzzer, LOW);
  } else {
    digitalWrite(led,HIGH);
    digitalWrite(buzzer,HIGH);
  }

  delay(200); 
}

