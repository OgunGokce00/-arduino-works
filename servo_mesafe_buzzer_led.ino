#include <Servo.h>

Servo ogun;
int pot = A0;
int echo = 11;
int tring = 12;
int sari = 8;
int mavi = 9;
int yesil = 10;
int buzer = 7;
int motor = 13;

void setup() 
{
  pinMode(sari, OUTPUT);
  pinMode(mavi, OUTPUT);
  pinMode(yesil, OUTPUT);
  pinMode(buzer, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(tring, OUTPUT);
  Serial.begin(9600);
  ogun.attach(motor);
}

void loop()
{
  int oku = analogRead(pot); 
  int servokontrol = map(oku, 0, 1023, 0, 180); 
  ogun.write(servokontrol); 
  int mesafe = mesafesensoru(); // Mesafe ölçümünü al
  LEDveBuzzerKontrolEt(mesafe); // Mesafeye bağlı olarak LED'leri ve buzzer'ı kontrol et
}

int mesafesensoru()
{
  int sure, uzaklik;
  digitalWrite(tring, HIGH);
  delay(1000);
  digitalWrite(tring, LOW);
  sure = pulseIn(echo, HIGH);
  uzaklik = (sure / 58);
  Serial.print("Uzaklık(cm)=");
  Serial.println(uzaklik);
  
  return uzaklik;
}
void LEDveBuzzerKontrolEt(int mesafe)
{
  if (mesafe <= 20) 
  {
    digitalWrite(sari, HIGH);
    digitalWrite(mavi, LOW);
    digitalWrite(yesil, LOW);

    // Buzzer'dan ses çal ve frekansı artır
    for (int i = 1000; i <= 2000; i += 50) 
    {
      tone(buzer, i);
      delay(20); // Küçük bir gecikme ekleyerek sesin daha yavaş artmasını sağlayabilirsiniz
    }
  } 
  else if (mesafe > 20 && mesafe <= 200) 
  {
    digitalWrite(sari, LOW);
    digitalWrite(mavi, HIGH);
    digitalWrite(yesil, LOW);
    tone(buzer, map(mesafe, 20, 200, 1000, 2000)); // Mesafe ile orantılı ton frekansı
  } 
  else if (mesafe > 200 && mesafe <= 400)
  {
    digitalWrite(sari, LOW);
    digitalWrite(mavi, LOW);
    digitalWrite(yesil, HIGH);
    tone(buzer, 2000); // Yüksek ton frekansı
  }
  else
  {
    // Mesafe 400 cm'den büyükse, tüm LED'leri kapat ve buzzer'ı kapat
    digitalWrite(sari, LOW);
    digitalWrite(mavi, LOW);
    digitalWrite(yesil, LOW);
    noTone(buzer);
  }
}







