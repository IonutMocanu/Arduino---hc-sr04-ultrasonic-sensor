#include <Servo.h>

int rgb_r = 2;
int rgb_b = 3;
int rgb_g = 4;

int blue = 5;
int green = 6;

int trigger_pin = 10;
int echo_pin = 11;

Servo servo1;

int servo_pin = 9;

int vr_x = A0;

long timp, cm;

void setup() {
  // put your setup code here, to run once:


  pinMode(rgb_r,OUTPUT);
  pinMode(rgb_b,OUTPUT);
  pinMode(rgb_g,OUTPUT);

  pinMode(blue,OUTPUT);
  pinMode(green,OUTPUT);

  pinMode(trigger_pin,OUTPUT);
  pinMode(echo_pin,INPUT);

  servo1.attach(servo_pin);

  pinMode(vr_x,INPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(trigger_pin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigger_pin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger_pin,LOW);

  timp = pulseIn(echo_pin,HIGH);

  cm = (timp *.0343)/2;

  Serial.println(cm);

  int x = analogRead(vr_x);
  x = map(x,0,1023,0,180);
  //Serial.println(x);
  servo1.write(x);

  if(cm>0 && cm<=100)
  {
  digitalWrite(rgb_b,HIGH);
  digitalWrite(rgb_r,LOW);
  digitalWrite(rgb_g,LOW);
  }
  else if(cm>100 && cm<=200)
  {
  digitalWrite(rgb_b,LOW);
  digitalWrite(rgb_r,HIGH);
  digitalWrite(rgb_g,LOW);
  }
  else
  {
  digitalWrite(rgb_b,LOW);
  digitalWrite(rgb_r,LOW);
  digitalWrite(rgb_g,HIGH);
  }
  //servo1.write(0);
}
