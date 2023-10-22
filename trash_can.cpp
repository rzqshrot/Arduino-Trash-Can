#define ECHO_PIN 2
#define TRIG_PIN 3
int servoPin = 6;
#include <Servo.h>
Servo s;
void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  s.attach(servoPin);
  s.write(0);
}

float readDistanceCM() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  long duration = pulseIn(ECHO_PIN, HIGH);
  return duration * 0.034 / 2;
}

void loop() {
 float distance = readDistanceCM();
  if(distance > 0 && distance <= 20){
    if(s.read() <= 65)
    s.write(65);
    Serial.println(s.read());
  }
  else if(distance >= 10){
    if(s.read() == 75){
      for(int i = 75;i>=0;i-=4){
        distance = readDistanceCM();
        if(distance <= 20)
        break;
        s.write(i);
        delay(100);
      }
    }
  }
}
