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

void LegClass::reset() {
  if(verbose) Serial.println("Leg - Reset");
  servos[0].reset();
  servos[1].reset();
  servos[2].reset();
}

void LegClass::moveTo(int orient, int knee, int foot) {
  if(verbose) Serial.println("Leg - MoveTo");
  if(isMirroredLeg) {
    if(isBackLeg)
      servos[0].moveTo(-orient);
    else
      servos[0].moveTo(orient);
    servos[1].moveTo(-knee);
    servos[2].moveTo(-foot);
  }
  else {
    if(isBackLeg)
      servos[0].moveTo(orient);
    else
      servos[0].moveTo(-orient);
    servos[1].moveTo(knee);
    servos[2].moveTo(foot);
  }
}
