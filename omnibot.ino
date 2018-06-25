const byte trig1 = 2;
const byte echo1 = 3;
const byte trig2 = 4;
const byte echo2 = 5;
const byte trig3 = 6;
const byte echo3 = 7;
int m1_in1 = 8;
int m1_in2 = 9;
int m2_in1 = 10;
int m2_in2 = 11;
int m3_in1 = 12;
int m3_in2 = 13;

unsigned long range(byte trig, byte echo){
  digitalWrite(trig, LOW);
  delayMicroseconds(5);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  unsigned long duration = pulseIn(echo, HIGH);
  return duration/58.2;
}

void activeM1_H(){
  digitalWrite(m1_in1, HIGH);
  digitalWrite(m1_in2, LOW);
}

void activeM1_AH(){
  digitalWrite(m1_in1, LOW);
  digitalWrite(m1_in2, HIGH);
}

void activeM2_H(){
  digitalWrite(m2_in1, HIGH);
  digitalWrite(m2_in2, LOW);
}

void activeM2_AH(){
  digitalWrite(m2_in1, LOW);
  digitalWrite(m2_in2, HIGH);  
}

void activeM3_H(){
  digitalWrite(m3_in1, HIGH);
  digitalWrite(m3_in2, LOW);
}

void activeM3_AH(){
  digitalWrite(m3_in1, LOW);
  digitalWrite(m3_in2, HIGH);  
}

void stopAll(){
  digitalWrite(m1_in1, HIGH);
  digitalWrite(m1_in2, HIGH);
  digitalWrite(m2_in1, HIGH);
  digitalWrite(m2_in2, HIGH);
  digitalWrite(m3_in1, HIGH);
  digitalWrite(m3_in2, HIGH);
}

void setup() {
  pinMode(trig1, OUTPUT);
  pinMode(echo1, INPUT);
  pinMode(trig2, OUTPUT);
  pinMode(echo2, INPUT);
  pinMode(trig3, OUTPUT);
  pinMode(echo3, INPUT);
  pinMode(m1_in1, OUTPUT);
  pinMode(m1_in2, OUTPUT);
  pinMode(m2_in1, OUTPUT);
  pinMode(m2_in2, OUTPUT);
  pinMode(m3_in1, OUTPUT);
  pinMode(m3_in2, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  //A distância é em centímetros.
  float distance1, distance2, distance3;
  delay(30);
  distance1 = range(trig1, echo1);
  delay(30);
  distance2 = range(trig2, echo2);
  delay(30);
  distance3 = range(trig3, echo3);

  if(distance1 < 10){
    stopAll();
    activeM2_AH();
    activeM3_H();
  }
  if(distance2 < 10){
    stopAll();
    activeM1_H();
    activeM3_AH();
  }
  if(distance3 < 10){
    stopAll();
    activeM1_AH();
    activeM2_H();
  }
}
