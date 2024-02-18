#include <Ultrasonic.h>
Ultrasonic u = Ultrasonic(3,4); // Triger,Echo

#include <Servo.h>
 Servo s = Servo();

 int ENA = 11;
 int IN1 = 10;
 int IN2 = 9;

 int ENB = 5;
 int IN3 = 7;
 int IN4 = 6;

void setup() {
  // put your setup code here, to run once:
  s.attach(2); //  Servo Pin

  // Motor A
  pinMode(ENA,OUTPUT);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  analogWrite(ENA,250);

   // Motor B
  pinMode(ENB,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  analogWrite(ENB,250);

  Serial.begin(9600); // Serial Moniter

}

void loop() {
  // put your main code here, to run repeatedly:

  int x = Serial.read();

// Foward
  if(x == '1'){
    s.Write(90);
    delay(300);
    int d = u.read();

   if(d>20){
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);

   }

  }
  // Reverse
   if(x == '2'){
     digitalWrite(IN1,LOW);
    digitalWrite(IN2,HIGH);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);
    delay(500);
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,LOW);
  }

  // Stop
   if(x == '3'){
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,LOW);

  }

  // Turn Right
   if(x == '4'){
    s.Write(45);
    delay(300);
    int d = u.read();

    if(d>20){
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);
    delay(500);
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,LOW);

    }
     s.Write(90);

  }

  // Turn Left
   if(x == '5'){
    s.Write(135);
    delay(300);
    int d = u.read();

    if(d>20){
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,HIGH);
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);
    delay(500);
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,LOW);

    }
     s.Write(90);


  }

}
