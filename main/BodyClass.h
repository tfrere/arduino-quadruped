#ifndef BODYCLASS_H
  #define BODYCLASS_H

  #include <ThreadController.h>
  #include <StaticThreadController.h>
  #include <Thread.h>

  #include "LegClass.h"

  #define FRONT_RIGHT 0
  #define BACK_RIGHT 2
  #define FRONT_LEFT 1
  #define BACK_LEFT 3

  extern Thread BodyThread;

  class BodyClass
  {
    private:
      bool     verbose = true;
      LegClass Legs[4];
      int test[3] = {1, 2, 0};
      int r_test[3] = {2, 1, 0};

    public:
      void     init();
      void     reset();
      void     forward();
      void     backward();
      void     turnLeft();
      void     turnRight();
      void     sleep();
      void     wakeUp();
      // void     printLegsPositions();
  };

#endif
