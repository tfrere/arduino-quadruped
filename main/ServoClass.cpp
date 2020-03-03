
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

  int end = currentPosition + value;

  if(verbose) {
    Serial.print("Servo - Go From ");
    Serial.print(currentPosition);
    Serial.print(" to ");
    Serial.println(end);
  }
  if(value == 0) {
    if(verbose) Serial.println("--> No move");
    return;
  }
  if((end > MAX) || (end < MIN)) {
    if(verbose) Serial.println("--> Offset reached");
    return;
  }

  ServoController.setChannelPWM(pin, end);
  currentPosition = end;
}

void ServoClass::moveTo(int value) {
  int end = currentPosition + value;

  if(verbose) {
    Serial.print("Servo - Move from ");
    Serial.print(currentPosition);
    Serial.print(" to ");
    Serial.println(end);
  }

  if((end > MAX) || (end < MIN)) {
    if(verbose) Serial.println("--> Offset reached");
    return;
  }

  if (value > 0) {
    while (currentPosition < end) {
     ServoController.setChannelPWM(pin, currentPosition++);
     delayMicroseconds(speed);
    }
  }
  else if(value < 0) {
    while (currentPosition > end) {
     ServoController.setChannelPWM(pin, currentPosition--);
     delayMicroseconds(speed);
    }
  }
}

int ServoClass::getPosition()
{
  return ServoController.getChannelPWM(pin);

  // currentPosition = ServoController.getChannelPWM(pin);
  // return currentPosition

}

void ServoClass::reset(int value)
{
  if(verbose) Serial.println("Servo - Reset");

  // if (isMirrored) {
  //   if(isBack && isOrient)
  //     currentPosition = MAX;
  //   else
  //     currentPosition = MIN;
  // }
  // else {
  //   if(isBack && isOrient)
  //     currentPosition = MIN;
  //   else
  //     currentPosition = MMAX;
  // }

  if(verbose) {
    Serial.print("Servo - Reset to ");
    Serial.println(value);
  }

  if((value > MAX) || (value < MIN)) {
    if(verbose) Serial.println("--> Offset reached");
    return;
  }

  currentPosition = value;
  ServoController.setChannelPWM(pin, value);
}
