#include "LegClass.h"

void LegClass::init(int id) {
  if(verbose) Serial.println("Leg - Init");
  name = id;
  isMirroredLeg = (name % 2);
  isBackLeg = (name >= 2);
  servos[0].init(SERVOS[id][0], isMirroredLeg, isBackLeg, true);
  servos[1].init(SERVOS[id][1], isMirroredLeg, isBackLeg, false);
  servos[2].init(SERVOS[id][2], isMirroredLeg, isBackLeg, false);
}

void LegClass::reset(int orient, int knee, int foot) {
  if(verbose) Serial.println("Leg - Reset");
  servos[0].reset(orient);
  servos[1].reset(knee);
  servos[2].reset(foot);
}

void LegClass::moveTo(int orient, int knee, int foot) {
  if(verbose) Serial.println("Leg - MoveTo");
  if(isMirroredLeg) {
    servos[1].moveTo(-knee);
    servos[2].moveTo(-foot);
    if(isBackLeg)
      servos[0].moveTo(-orient);
    else
      servos[0].moveTo(orient);
  }
  else {
    servos[1].moveTo(knee);
    servos[2].moveTo(foot);
    if(isBackLeg)
      servos[0].moveTo(orient);
    else
      servos[0].moveTo(-orient);
  }
}

void LegClass::goTo(int orient, int knee, int foot, int* execution_order) {
  if(verbose) Serial.println("Leg - GoTo");

  for(int i = 0; i < 3; i++) {
    for(int y = 0; y < 3; y++) {
      if(execution_order[i] == y) {

        if(isMirroredLeg) {
          if(y == 1) {
            servos[1].goTo(-knee);
            delay(delay_between_action);
          }
          if(y == 2) {
            servos[2].goTo(-foot);
            delay(delay_between_action);
          }
          if(isBackLeg) {
            if(y == 0) {
              servos[0].goTo(-orient);
              delay(delay_between_action);
            }
          }
          else {
            if(y == 0) {
              servos[0].goTo(orient);
              delay(delay_between_action);
            }
          }
        }
        else {
          if(y == 1) {
            servos[1].goTo(knee);
            delay(delay_between_action);
          }
          if(y == 2) {
            servos[2].goTo(foot);
            delay(delay_between_action);
          }
          if(isBackLeg) {
            if(y == 0) {
              servos[0].goTo(orient);
              delay(delay_between_action);
            }
          }
          else {
            if(y == 0) {
              servos[0].goTo(-orient);
              delay(delay_between_action);
            }
          }
        }

      }
    }

  }

}
