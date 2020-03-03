#ifndef LEGCLASS_H
  #define LEGCLASS_H

  #include "ServoClass.h"

  extern int SERVOS[4][3];

  class LegClass
  {
    private:
      int        y;
      int        name;
      bool       isMirroredLeg;
      bool       isBackLeg;
      bool       verbose = true;
      ServoClass servos[3];
      int        delay_between_action = 100;

    public:
      void       init(int id);
      void       reset(int orient, int knee, int foot);
      // void       goTo(int orient, int knee, int foot);
      void       goTo(int orient, int knee, int foot, int* execution_order);
      void       moveTo(int orient, int knee, int foot);
  };

#endif
