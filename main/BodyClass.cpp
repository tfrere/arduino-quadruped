#include "BodyClass.h"

void BodyClass::init() {
  if(verbose) Serial.println("Body - Init");

  Legs[FRONT_RIGHT].init(FRONT_RIGHT);
  Legs[FRONT_LEFT].init(FRONT_LEFT);
  Legs[BACK_RIGHT].init(BACK_RIGHT);
  Legs[BACK_LEFT].init(BACK_LEFT);

  reset();
}

void BodyClass::reset() {
  Legs[FRONT_RIGHT].reset(450, 500, 500);
  Legs[BACK_RIGHT].reset(450, 500, 500);
  Legs[FRONT_LEFT].reset(450, 500, 500);
  Legs[BACK_LEFT].reset(450, 500, 500);
}

void BodyClass::forward() {

  if(verbose) Serial.println("Body - Forward");

  Legs[FRONT_LEFT].goTo(-100, -100, -100, test);
  Legs[FRONT_LEFT].goTo(0, 100, 100, r_test);

  Legs[BACK_RIGHT].goTo(100, -100, -100, test);
  Legs[BACK_RIGHT].goTo(0, 100, 100, r_test);

  Legs[FRONT_RIGHT].goTo(-100, -100, -100, test);
  Legs[FRONT_RIGHT].goTo(0, 100, 100, r_test);

  Legs[BACK_LEFT].goTo(100, -100, -100, test);
  Legs[BACK_LEFT].goTo(0, 100, 100, r_test);

  Legs[FRONT_LEFT].goTo(100, 0, 0, test);
  Legs[BACK_RIGHT].goTo(-100, 0, 0, test);
  Legs[FRONT_RIGHT].goTo(100, 0, 0, test);
  Legs[BACK_LEFT].goTo(-100, 0, 0, test);

}

void BodyClass::backward() {

  if(verbose) Serial.println("Body - Forward 2");

  Legs[FRONT_LEFT].goTo(-100, -100, -100, test);
  Legs[FRONT_LEFT].goTo(100, 100, 100, r_test);

  Legs[BACK_RIGHT].goTo(100, -100, -100, test);
  Legs[BACK_RIGHT].goTo(-100, 100, 100, r_test);


  Legs[FRONT_RIGHT].goTo(-100, -100, -100, test);
  Legs[FRONT_RIGHT].goTo(100, 100, 100, r_test);

  Legs[BACK_LEFT].goTo(100, -100, -100, test);
  Legs[BACK_LEFT].goTo(-100, 100, 100, r_test);
}

void BodyClass::turnLeft() {
  if(verbose) Serial.println("Body - Turn Left");
  Legs[FRONT_RIGHT].moveTo(50, 0, 0);
  Legs[FRONT_LEFT].moveTo(50, 0, 0);
  Legs[BACK_RIGHT].moveTo(50, 0, 0);
  Legs[BACK_LEFT].moveTo(50, 0, 0);
}

void BodyClass::turnRight() {
  if(verbose) Serial.println("Body - Turn Right");
  Legs[FRONT_RIGHT].moveTo(-50, 0, 0);
  Legs[FRONT_LEFT].moveTo(-50, 0, 0);
  Legs[BACK_RIGHT].moveTo(-50, 0, 0);
  Legs[BACK_LEFT].moveTo(-50, 0, 0);
}

void BodyClass::sleep() {
  if(verbose) Serial.println("Body - Sleep");

  // Legs[FRONT_LEFT].goTo(0, -150, -150, test);
  // Legs[FRONT_LEFT].goTo(100, 0, 0, test);
  // Legs[FRONT_LEFT].goTo(-100, 0, 0, test);
  // Legs[FRONT_LEFT].goTo(100, 0, 0, test);
  // Legs[FRONT_LEFT].goTo(-100, 0, 0, test);
  // Legs[FRONT_LEFT].goTo(0, 150, 150, r_test);

  Legs[FRONT_RIGHT].reset(450, 350, 300);
  Legs[FRONT_LEFT].reset(450, 550, 600);
  Legs[BACK_RIGHT].reset(450, 350, 300);
  Legs[BACK_LEFT].reset(450, 550, 600);
}

void BodyClass::wakeUp() {
  if(verbose) Serial.println("Body - Wake Up");
  Legs[FRONT_RIGHT].moveTo(300, 300, 300);
  Legs[FRONT_LEFT].moveTo(300, 300, 300);
  Legs[BACK_RIGHT].moveTo(300, 300, 300);
  Legs[BACK_LEFT].moveTo(300, 300, 300);
}
//
// void BodyClass::printLegsPositions() {
//   if(verbose) Serial.println("Body - Get legs positions");
//
//   Serial.print("Front right: ");
//   Serial.print(ServoController.getChannelPWM(0));
//   Serial.print(", ");
//   Serial.print(ServoController.getChannelPWM(1));
//   Serial.print(", ");
//   Serial.print(ServoController.getChannelPWM(2));
//   Serial.print("|| Front left: ");
//   Serial.print(ServoController.getChannelPWM(3));
//   Serial.print(", ");
//   Serial.print(ServoController.getChannelPWM(4));
//   Serial.print(", ");
//   Serial.print(ServoController.getChannelPWM(5));
//   Serial.print("|| Back right: ");
//   Serial.print(ServoController.getChannelPWM(6));
//   Serial.print(", ");
//   Serial.print(ServoController.getChannelPWM(7));
//   Serial.print(", ");
//   Serial.print(ServoController.getChannelPWM(8));
//   Serial.print("|| Back left: ");
//   Serial.print(ServoController.getChannelPWM(9));
//   Serial.print(", ");
//   Serial.print(ServoController.getChannelPWM(10));
//   Serial.print(", ");
//   Serial.println(ServoController.getChannelPWM(11));
//
// }
