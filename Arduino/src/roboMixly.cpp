#include<music.h>

volatile int distance;
volatile int flag;
volatile int mus;
volatile int sensor_L;
volatile int sensor_R;
volatile int val_C;
volatile int val_L;
volatile int val_R;

char bluetooth_val;

int buzzer_pin = 11;
music Music(buzzer_pin);
void Back() {
  digitalWrite(4,HIGH);
  analogWrite(5,255);
  digitalWrite(2,HIGH);
  analogWrite(9,);
  delay(200);
  digitalWrite(4,LOW);
  analogWrite(5,255);
  digitalWrite(2,HIGH);
  analogWrite(9,);
  delay(700);
  digitalWrite(4,HIGH);
  analogWrite(5,255);
  digitalWrite(2,HIGH);
  analogWrite(9,);
  bluetooth_val = 0;
}

void avoid() {
  flag = 0;
  while (flag == 0) {
    distance = checkdistance();
    sensor_L = digitalRead(A0);
    sensor_R = digitalRead(A2);
    if (sensor_L == 0 && sensor_R == 0) {
      digitalWrite(4,LOW);
      analogWrite(5,150);
      digitalWrite(2,LOW);
      analogWrite(9,);
      delay(1000);
      digitalWrite(4,LOW);
      analogWrite(5,200);
      digitalWrite(2,HIGH);
      analogWrite(9,);
      delay(500);

    } else if (sensor_L == 1 && sensor_R == 0) {
      digitalWrite(4,LOW);
      analogWrite(5,200);
      digitalWrite(2,HIGH);
      analogWrite(9,);
    } else if (sensor_L == 0 && sensor_R == 1) {
      digitalWrite(4,HIGH);
      analogWrite(5,200);
      digitalWrite(2,LOW);
      analogWrite(9,);
    } else if (distance <= 10 && (sensor_L == 1 && sensor_R == 1)) {
      digitalWrite(4,HIGH);
      analogWrite(5,200);
      digitalWrite(2,LOW);
      analogWrite(9,);
    } else if (distance > 10 && (sensor_L == 1 && sensor_R == 1)) {
      digitalWrite(4,HIGH);
      analogWrite(5,200);
      digitalWrite(2,HIGH);
      analogWrite(9,);
    }
    if (Serial.available())
    {
      bluetooth_val = Serial.read();
      if (bluetooth_val == 'S') {
        flag = 1;

      }
    }
  }
}

float checkdistance() {
  digitalWrite(12, LOW);
  delayMicroseconds(2);
  digitalWrite(12, HIGH);
  delayMicroseconds(10);
  digitalWrite(12, LOW);
  float distance = pulseIn(13, HIGH) / 58.00;
  delay(10);
  return distance;
}

void follow() {
  flag = 0;
  while (flag == 0) {
    distance = checkdistance();
    sensor_L = digitalRead(A0);
    sensor_R = digitalRead(A2);
    if (distance <= 5 || sensor_L == 0 && sensor_R == 0) {
      digitalWrite(4,LOW);
      analogWrite(5,200);
      digitalWrite(2,LOW);
      analogWrite(9,);

    } else if (distance > 5 && (sensor_L == 0 && sensor_R == 1)) {
      digitalWrite(4,LOW);
      analogWrite(5,200);
      digitalWrite(2,HIGH);
      analogWrite(9,);
    } else if (distance > 5 && (sensor_L == 1 && sensor_R == 0)) {
      digitalWrite(4,HIGH);
      analogWrite(5,200);
      digitalWrite(2,LOW);
      analogWrite(9,);
    } else if ((distance > 5 && distance <= 15) && (sensor_L == 1 && sensor_R == 1)) {
      digitalWrite(4,LOW);
      analogWrite(5,0);
      digitalWrite(2,LOW);
      analogWrite(9,0);
    } else if ((distance > 15 && distance <= 35) && (sensor_L == 1 && sensor_R == 1)) {
      digitalWrite(4,HIGH);
      analogWrite(5,255);
      digitalWrite(2,HIGH);
      analogWrite(9,);
    } else if (distance > 35 && (sensor_L == 1 && sensor_R == 1)) {
      digitalWrite(4,LOW);
      analogWrite(5,0);
      digitalWrite(2,LOW);
      analogWrite(9,0);
    }
    if (Serial.available())
    {
      bluetooth_val = Serial.read();
      if (bluetooth_val == 'S') {
        flag = 1;

      }
    }
  }
}

void tracking() {
  flag = 0;
  while (flag == 0) {
    val_L = digitalRead(6);
    val_C = digitalRead(7);
    val_R = digitalRead(8);
    if (val_C == 1) {
      digitalWrite(4,HIGH);
      analogWrite(5,200);
      digitalWrite(2,HIGH);
      analogWrite(9,);

    } else {
      if (val_L == 1 && val_R == 0) {
        digitalWrite(4,LOW);
        analogWrite(5,200);
        digitalWrite(2,HIGH);
        analogWrite(9,);

      } else if (val_L == 0 && val_R == 1) {
        digitalWrite(4,HIGH);
        analogWrite(5,200);
        digitalWrite(2,LOW);
        analogWrite(9,);
      } else {
        digitalWrite(4,LOW);
        analogWrite(5,0);
        digitalWrite(2,LOW);
        analogWrite(9,0);

      }

    }
    if (Serial.available())
    {
      bluetooth_val = Serial.read();
      if (bluetooth_val == 'S') {
        flag = 1;

      }
    }
  }
}

void setup(){
  Serial.begin(9600);
  val_L = 0;
  val_R = 0;
  val_C = 0;
  distance = 0;
  flag = 0;
  mus = 0;
  sensor_L = 0;
  sensor_R = 0;
  Serial.begin(9600);
  Serial.begin(9600);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(buzzer_pin, OUTPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(12, OUTPUT);
  pinMode(13, INPUT);
  pinMode(A0, INPUT);
  pinMode(A2, INPUT);
}

void loop(){
  if (Serial.available())
  {
    bluetooth_val = Serial.read();
    Serial.println(bluetooth_val);
  }
  switch (bluetooth_val) {
   case 'F':
    digitalWrite(4,HIGH);
    analogWrite(5,200);
    digitalWrite(2,HIGH);
    analogWrite(9,);
    break;
   case 'B':
    digitalWrite(4,LOW);
    analogWrite(5,200);
    digitalWrite(2,LOW);
    analogWrite(9,);
    break;
   case 'L':
    digitalWrite(4,HIGH);
    analogWrite(5,100);
    digitalWrite(2,HIGH);
    analogWrite(9,180);
    break;
   case 'R':
    digitalWrite(4,HIGH);
    analogWrite(5,180);
    digitalWrite(2,HIGH);
    analogWrite(9,100);
    break;
   case 'S':
    digitalWrite(4,LOW);
    analogWrite(5,0);
    digitalWrite(2,LOW);
    analogWrite(9,0);
    noTone(11);
    break;
   case 'Q':
    digitalWrite(4,LOW);
    analogWrite(5,200);
    digitalWrite(2,HIGH);
    analogWrite(9,);
    break;
   case 'E':
    digitalWrite(4,HIGH);
    analogWrite(5,200);
    digitalWrite(2,LOW);
    analogWrite(9,);
    break;
   case 'W':
    digitalWrite(4,HIGH);
    analogWrite(5,255);
    digitalWrite(2,HIGH);
    analogWrite(9,);
    break;
   case 'Z':
    Back();
    break;
   case 'U':
    follow();
    break;
   case 'X':
    tracking();
    break;
   case 'Y':
    avoid();
    break;
   case '1':
    tone(11,262);
    break;
   case '2':
    tone(11,294);
    break;
   case '3':
    tone(11,330);
    break;
   case '4':
    tone(11,349);
    break;
   case '5':
    tone(11,392);
    break;
   case '6':
    tone(11,440);
    break;
   case '7':
    tone(11,494);
    break;
   case '8':
    tone(11,532);
    break;
   case 'P':
    mus = 0;
    while (mus < 1) {
      Music.birthday();
      noTone(11);
      mus = mus + 1;
    }
    break;
  }

}