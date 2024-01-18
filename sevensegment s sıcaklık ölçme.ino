float tmp;
float sicaklik;
int int_sicaklik;
int birler;
int onlar;
void setup()
{
  pinMode(A0,INPUT);
  pinMode(4,OUTPUT); pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  tmp = analogRead(A0);        
  sicaklik = (((tmp / 1024)*5)-0.5)*100;   
  int_sicaklik=round(sicaklik);
  if(int_sicaklik>99) int_sicaklik=99;
  delay(500);
  Serial.print("Sicaklik:");
  Serial.println(int_sicaklik);
  if(sicaklik<0) digitalWrite(12,HIGH);
  else digitalWrite(12,LOW);
  birler=abs(int_sicaklik%10);
  Serial.println(birler);
  onlar=abs(int_sicaklik/10);
  Serial.println(onlar);
  if(onlar==0) sifir(4,5,6,7);
  else if(onlar==1) bir(4,5,6,7);
  else if(onlar==2) iki(4,5,6,7);
  else if(onlar==3) uc(4,5,6,7);
  else if(onlar==4) dort(4,5,6,7);
  else if(onlar==5) bes(4,5,6,7);
  else if(onlar==6) alti(4,5,6,7);
  else if(onlar==7) yedi(4,5,6,7);
  else if(onlar==8) sekiz(4,5,6,7);
  else if(onlar==9) dokuz(4,5,6,7);
    
  if(birler==0) sifir(8,9,10,11);
  else if(birler==1) bir(8,9,10,11);
  else if(birler==2) iki(8,9,10,11);
  else if(birler==3) uc(8,9,10,11);
  else if(birler==4) dort(8,9,10,11);
  else if(birler==5) bes(8,9,10,11);
  else if(birler==6) alti(8,9,10,11);
  else if(birler==7) yedi(8,9,10,11);
  else if(birler==8) sekiz(8,9,10,11);
  else if(birler==9) dokuz(8,9,10,11);
   
}

void bir(int a, int b, int c, int d)
{
  digitalWrite(a,HIGH);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,LOW);
}
void iki(int a, int b, int c, int d)
{
  digitalWrite(a,LOW);
  digitalWrite(b,HIGH);
  digitalWrite(c,LOW);
  digitalWrite(d,LOW);
}
void uc(int a, int b, int c, int d)
{
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,LOW);
  digitalWrite(d,LOW);
}
void dort(int a, int b, int c, int d)
{
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(c,HIGH);
  digitalWrite(d,LOW);
}

void bes(int a, int b, int c, int d)
{
  digitalWrite(a,HIGH);
  digitalWrite(b,LOW);
  digitalWrite(c,HIGH);
  digitalWrite(d,LOW);
}
void alti(int a, int b, int c, int d)
{
  digitalWrite(a,LOW);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,LOW);
}
void yedi(int a, int b, int c, int d)
{
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,LOW);
}
void sekiz(int a, int b, int c, int d)
{
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,HIGH);
}
void dokuz(int a, int b, int c, int d)
{
  digitalWrite(a,HIGH);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,HIGH);
}
void sifir(int a, int b, int c, int d)
{
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,LOW);
}
