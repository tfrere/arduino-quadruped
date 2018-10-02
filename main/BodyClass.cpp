#include "BodyClass.h"

void BodyClass::init() {
  if(verbose) Serial.println("Body - Init");
  Legs[FRONT_RIGHT].init(FRONT_RIGHT);
  Legs[FRONT_RIGHT].reset();
  Legs[FRONT_LEFT].init(FRONT_LEFT);
  Legs[FRONT_LEFT].reset();
  Legs[BACK_RIGHT].init(BACK_RIGHT);
  Legs[BACK_RIGHT].reset();
  Legs[BACK_LEFT].init(BACK_LEFT);
  Legs[BACK_LEFT].reset();
}

void BodyClass::forward() {
  if(verbose) Serial.println("Body - Forward");
  Legs[FRONT_RIGHT].moveTo(50, 50, 50);
  Legs[FRONT_LEFT].moveTo(50, 50, 50);
  Legs[BACK_RIGHT].moveTo(50, 50, 50);
  Legs[BACK_LEFT].moveTo(50, 50, 50);
}

void BodyClass::backward() {
  if(verbose) Serial.println("Body - Backward");
  Legs[FRONT_RIGHT].moveTo(-50, -50, -50);
  Legs[FRONT_LEFT].moveTo(-50, -50, -50);
  Legs[BACK_RIGHT].moveTo(-50, -50, -50);
  Legs[BACK_LEFT].moveTo(-50, -50, -50);
}

void BodyClass::turnLeft() {
  if(verbose) Serial.println("Body - Turn Left");
  Legs[FRONT_RIGHT].moveTo(50, 50, 50);
  Legs[FRONT_LEFT].moveTo(50, 50, 50);
  Legs[BACK_RIGHT].moveTo(50, 50, 50);
  Legs[BACK_LEFT].moveTo(50, 50, 50);
}

void BodyClass::turnRight() {
  if(verbose) Serial.println("Body - Turn Right");
  Legs[FRONT_RIGHT].moveTo(50, 50, 50);
  Legs[FRONT_LEFT].moveTo(50, 50, 50);
  Legs[BACK_RIGHT].moveTo(50, 50, 50);
  Legs[BACK_LEFT].moveTo(50, 50, 50);
}

void BodyClass::sleep() {
  if(verbose) Serial.println("Body - Sleep");
  Legs[FRONT_RIGHT].reset();
  Legs[FRONT_LEFT].reset();
  Legs[BACK_RIGHT].reset();
  Legs[BACK_LEFT].reset();
}

void BodyClass::wakeUp() {
  if(verbose) Serial.println("Body - Wake Up");
  Legs[FRONT_RIGHT].moveTo(100, -300, -300);
  // Legs[FRONT_LEFT].moveTo(100, 300, 300);
  // Legs[BACK_RIGHT].moveTo(100, -300, -300);
  // Legs[BACK_LEFT].moveTo(100, 300, 300);
}
