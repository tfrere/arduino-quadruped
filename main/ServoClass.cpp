
#include "ServoClass.h"

void ServoClass::init(int id, bool mirror, bool back, bool orient) {
    if(verbose) Serial.println("Servo - Init");
    pin = id;
    isMirrored = mirror;
    isBack = back;
    isOrient = orient;
}

void ServoClass::setSpeed(int newSpeed) {
    if(verbose) {
      Serial.print("Servo - Set Speed to");
      Serial.println(newSpeed);
    }
    speed = newSpeed;
}

void ServoClass::goTo(int value) {
    if(verbose) Serial.println("Servo - Reset");
    ServoController.setChannelPWM(pin, value);
    currentPosition = value;
}

void ServoClass::moveTo(int value) {
  int i = currentPosition;
  int end = currentPosition + value;

  if(verbose) {
    Serial.print("Servo - Move from ");
    Serial.print(currentPosition);
    Serial.print(" to ");
    Serial.println(end);
  }

  if((end >= MAX) || (end <= MIN)) {
    if(verbose) Serial.println("Servo - Offset reached");
    return;
  }

  if (value >= 0) {
    while (i <= end) {
     ServoController.setChannelPWM(pin, i++);
     delayMicroseconds(speed);
    }
  }
  else {
    while (i >= end) {
     ServoController.setChannelPWM(pin, i--);
     delayMicroseconds(speed);
    }
  }

  currentPosition = i;
}

void ServoClass::reset()
{
  if(verbose) Serial.println("Servo - Reset");

  if (isMirrored) {
    if(isBack && isOrient)
      currentPosition = MAX;
    else
      currentPosition = MIN;
  }
  else {
    if(isBack && isOrient)
      currentPosition = MIN;
    else
      currentPosition = MAX;
  }

  ServoController.setChannelPWM(pin, currentPosition);
}
