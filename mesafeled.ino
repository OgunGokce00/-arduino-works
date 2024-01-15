int krmz=8;
int mavi=9;
int trig=10;
int echo=11;



void setup() 
{
   Serial.begin(9600);
  pinMode(krmz,OUTPUT);
  pinMode(mavi,OUTPUT);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
 
}

void loop() 
{
    // Ultrasonik sensörü tetikle
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  
  // Echo pin'inden gelen süreyi ölç
  long gelen = pulseIn(echo, HIGH);
  // Sesin hava ortamında hızı yaklaşık 0.034 cm/mikrosaniye olduğundan,
  // mesafeyi cm cinsinden hesaplayın
  int  hesap = gelen * 0.034 / 2;
  Serial.print("Mesafe: ");
  Serial.print(hesap);
  Serial.println(" cm");

  // Mesafe eşiği (örneğin, 20 cm) aşıldığında LED'i yak
  if (hesap <5) {
    digitalWrite(krmz, HIGH);
    digitalWrite(mavi, LOW);
  } 
  else{
    digitalWrite(mavi, HIGH);
    digitalWrite(krmz, LOW);
  }

  delay(200);  // Mesafe ölçümünü saniyede bir kez yapmak için bekleyin
   
 
}
