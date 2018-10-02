#ifndef SERVOCLASS_H
  #define SERVOCLASS_H

  #include <Wire.h>
  #include "PCA9685.h"

  extern PCA9685 ServoController;

  #define MIN 300
  #define MAX 600
  #define MAX_OFFSET MAX - MIN
  #define BASE_SPEED 1000

  class ServoClass
  {
    private:
      int  pin;
      bool isMirrored;
      bool isOrient;
      bool isBack;
      int  speed = BASE_SPEED;
      int  currentPosition;
      int  oldPosition;
      int  verbose = 1;

    public:
      void init(int id, bool mirror, bool back, bool orient);
      void reset();
      void moveTo(int newPosition);
      void goTo(int newPosition);
      void setSpeed(int newSpeed);
  };

#endif
