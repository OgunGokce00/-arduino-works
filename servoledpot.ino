 #include<Servo.h>

 int mavi=8;
 int pot=A0;
 //nesne oluştur
  Servo servo;
  int val=0;



void setup() 
{ 
  servo.attach(9);
  pinMode(mavi,OUTPUT);
 

}

void loop()
 {
  
   val=analogRead(pot);
   val=map(val,0,1023,0,179);
   servo.write(val);
     if(val>50)
    {
    
     digitalWrite(mavi,HIGH);
    
    }
    if(val<50)
    {
     
      digitalWrite(mavi,LOW);
    }

   delay(15);
   

  

}
