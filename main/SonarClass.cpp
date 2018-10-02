#include "sonarClass.h"

void SonarClass::init(int trigPin, int echoPin)
{
  if(verbose) Serial.println("Sonar - Init");
  trig = trigPin;
  echo = echoPin;
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

int SonarClass::getDist()
{
  long pulse_width = 0;
  long cm = 0;

  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  pulse_width = pulseIn(echo, HIGH);
  cm = pulse_width / CM_DIVIDER;
  if(verbose) {
    Serial.print("Sonar - getDist : ");
    Serial.print(cm);
    Serial.println(" cm");
  }
  return (cm);
}
