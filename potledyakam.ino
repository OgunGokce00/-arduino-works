int pot = A0;
int val;
// değişken oluşturun

void setup() {
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(pot, INPUT); // Potansiyometrenin okuma modunu INPUT olarak ayarlayın
  Serial.begin(9600);
}

void loop() {
  val = analogRead(pot);
  val = map(val, 0, 1023, 0, 179);

  if (val >= 100) { // Eğer val değişkeni 100'den büyükse
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW); // Diğer pin'i düşük yap
    delay(1000);
  } else {
    digitalWrite(8, LOW); // Birinci pin'i düşük yap
    digitalWrite(9, HIGH);
    delay(1000);
  }
}
