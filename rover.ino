#include <Servo.h>

Servo myservo; 
int pos = 90;  
long duration; 
int distance,right,left; 
int trigPin=8;
int echoPin=9;
int drogo();
int chech();


int drogo()
{digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  
  distance = duration * 0.034 / 2; 
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");return(distance);}


void setup() {
  myservo.attach(10); 
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT); 
  Serial.begin(9600); 
 pinMode(2, OUTPUT);
 pinMode(3, OUTPUT);
 
 pinMode(4, OUTPUT);
 pinMode(5, OUTPUT);
 pinMode(6, OUTPUT);
 pinMode(7, OUTPUT); 
}

void loop() {int k,L,R;
distance= drogo(); 
if(distance >= 40)  
{digitalWrite(2,210);
digitalWrite(3,210);
digitalWrite(5,HIGH);
digitalWrite(4,LOW);  

digitalWrite(6,HIGH);
digitalWrite(7,LOW);
}
else
{digitalWrite(2,0);
digitalWrite(3,0);
for (pos = 90; pos >= 0; pos -= 3) { 
    myservo.write(pos);              
   delay(15);                       
  }  delay(15);  
  R=drogo();  
for (pos = 90; pos <= 170; pos += 3) { 
    myservo.write(pos);              
   delay(15);                       
  } delay(15);  
  L=drogo();delay(15); 
 for (pos = 170; pos >= 90; pos -= 3) { 
    myservo.write(pos);              
   delay(15);                       
  }
if(R >=35 && L >=35){
for(int i=0;i<300;i++)
  {Serial.println(":::::") ;
    digitalWrite(2,0);
digitalWrite(3,210);
digitalWrite(5,LOW);
digitalWrite(4,LOW);  

digitalWrite(6,HIGH);
digitalWrite(7,LOW);}

}
   
if(R >=35 && L<=34){
for(int i=0;i<300;i++)
  {Serial.println(":::::") ;
    digitalWrite(2,0);
digitalWrite(3,210);
digitalWrite(5,LOW);
digitalWrite(4,LOW);  

digitalWrite(6,HIGH);
digitalWrite(7,LOW);}

}
if(L >=35 && R<=34){
for(int i=0;i<300;i++)
  {Serial.println(":::::") ;
    digitalWrite(2,210);
digitalWrite(3,0);
digitalWrite(5,HIGH);
digitalWrite(4,LOW);  

digitalWrite(6,LOW);
digitalWrite(7,LOW);}


}
if(L <=35 && R<=34){
for(int i=0;i<300;i++)
  {Serial.println(":::::") ;
    digitalWrite(2,0);
digitalWrite(3,0);
digitalWrite(5,LOW);
digitalWrite(4,LOW);  

digitalWrite(6,LOW);
digitalWrite(7,LOW);}


}
}

}