int buzz = 13;
int Echo = 4;
int Trigger = 3;
int VCC = 2;
int GND = 5;
long timer;
float distance;

void setup() {
  pinMode(VCC, OUTPUT);
  pinMode(GND, OUTPUT);
  digitalWrite(VCC, HIGH);
  digitalWrite(GND, LOW);
  pinMode(Trigger, OUTPUT); 
  pinMode(Echo, INPUT); 
  //Serial.begin(9600); 
  pinMode(buzz, OUTPUT); 
}
void loop() {
  digitalWrite(Trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trigger, LOW);
  timer = pulseIn(Echo, HIGH);
  distance = timer * 0.034 / 2;
  buzzfun(distance);
  //Serial.print(distance);
  //Serial.println(" cm");
  delay(100);
}

void buzzfun(float distance){
    if (distance<10){tone(buzz, 261.6, 100);} //C
    else if (distance<15 && distance>10){tone(buzz, 277.2, 100);} //C#
    else if (distance<20 && distance>15){tone(buzz, 293.7, 100);} //D
    else if (distance<25 && distance>20){tone(buzz, 311.1, 100);} //D#
    else if (distance<30 && distance>25){tone(buzz, 329.6, 100);} //E
    else if (distance<35 && distance>30){tone(buzz, 349.2, 100);} //F
    else if (distance<40 && distance>35){tone(buzz, 370, 100);} //F#
    else if (distance<45 && distance>40){tone(buzz, 392, 100);} //G
    else if (distance<50 && distance>45){tone(buzz, 415.3, 100);} //G#
    else if (distance<55 && distance>50){tone(buzz, 440, 100);} //A
    else if (distance<60 && distance>55){tone(buzz, 466.2, 100);} //A#
    else if (distance<65){tone(buzz, 493.9, 100);} //B
    else{noTone(buzz);}
  }
