#ifndef SONARCLASS_H
  #define SONARCLASS_H

  #include <Arduino.h>
  #include <string.h>

  #define CM_DIVIDER 58

  class SonarClass
  {
    private:
      bool verbose = true;
      int  trig;
      int  echo;

    public:
      void init(int trigPin, int echoPin);
      int  getDist();
      int  canIMoveForward();
  };

#endif
