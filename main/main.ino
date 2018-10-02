/*
–––––––––––––––––––––––––––––––––––––––––––––––––––––––––

  ███████╗  ██████╗   ██╗  ██████╗   ███████╗  ██████╗
  ██╔════╝  ██╔══██╗  ██║  ██╔══██╗  ██╔════╝  ██╔══██╗
  ███████╗  ██████╔╝  ██║  ██║  ██║  █████╗    ██████╔╝
  ╚════██║  ██╔═══╝   ██║  ██║  ██║  ██╔══╝    ██╔══██╗
  ███████║  ██║       ██║  ██████╔╝  ███████╗  ██║  ██║
  ╚══════╝  ╚═╝       ╚═╝  ╚═════╝   ╚══════╝  ╚═╝  ╚═╝
                                            tfrere 2018
–––––––––––––––––––––––––––––––––––––––––––––––––––––––––
*/

#include "SonarClass.h"
#include "Bluetooth.h"
#include "BodyClass.h"

#define DEBUG 9600                 // Serial channel for debugging
#define VERBOSE true               // Verbose mode for debugging

#define BAUD_RATE 400000           // Supported rates are 100kHz, 400, and 1000
#define ADDRESS_PIN B000000        // Address pins A5-A0 set to B000000
#define PWM_FREQUENCY 100          // Default is 200Hz, supports 24 to 1526

#define SONAR_TRIG_PIN 3           // Sonar Trig pin
#define SONAR_ECHO_PIN 2           // Sonar Echo pin

#define BT_BAUD_RATE 115200        // Set at 115200 by default
#define BT_CMD A2                  // Bluetooth cmd
#define BT_STATE A5                // Bluetooth state
#define BT_RX_PIN 11               // Bluetooth RX pin
#define BT_TX_PIN 10               // Bluetooth TX pin

#define THREAD_SPEED 250           // Thread interval rate

int SERVOS[4][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {9, 10, 11}};

bool isConnected = false;
bool isMoving = false;
bool hasToMoveForward = false;
bool hasToMoveBackward = false;
bool hasToTurnLeft = false;
bool hasToTurnRight = false;
bool hasToSleep = false;
bool hasToWakeUp = false;

SonarClass Sonar;
PCA9685    ServoController;
HC05       Bluetooth = HC05(BT_CMD, BT_STATE, BT_RX_PIN, BT_TX_PIN);
Thread     BodyThread = Thread();

BodyClass  Body;

void bodyThreadCallBack() {
  if(hasToMoveForward && !isMoving) {
    isMoving = true;
    Body.forward();
    isMoving = hasToMoveForward = false;
  }
  else if(hasToMoveBackward && !isMoving) {
    isMoving = true;
    Body.backward();
    isMoving = hasToMoveBackward = false;
  }
  else if(hasToTurnLeft && !isMoving) {
    isMoving = true;
    Body.turnLeft();
    isMoving = hasToTurnLeft = false;
  }
  else if(hasToTurnRight && !isMoving) {
    isMoving = true;
    Body.turnRight();
    isMoving = hasToTurnRight = false;
  }
  else if(hasToSleep && !isMoving) {
    isMoving = true;
    Body.sleep();
    isMoving = hasToSleep = false;
  }
  else if(hasToWakeUp && !isMoving) {
    isMoving = true;
    Body.wakeUp();
    isMoving = hasToWakeUp = false;
  }
}

void setup() {

  Serial.begin(DEBUG);
  if(VERBOSE) Serial.println("-- Setup -----------");

  if(VERBOSE) Serial.println("-- Sonar -----------");
  Sonar.init(SONAR_TRIG_PIN, SONAR_ECHO_PIN);

  if(VERBOSE) Serial.println("-- Servo -----------");
  Wire.begin();
  Wire.setClock(BAUD_RATE);
  ServoController.resetDevices();
  ServoController.init(ADDRESS_PIN);
  ServoController.setPWMFrequency(PWM_FREQUENCY);

  if(VERBOSE) Serial.println("-- Bluetooth -------");
  Bluetooth.setBaud(BT_BAUD_RATE);

  if(VERBOSE) Serial.println("-- Thread ----------");
  BodyThread.onRun(bodyThreadCallBack);
  BodyThread.setInterval(THREAD_SPEED);

  if(VERBOSE) Serial.println("-- End of Setup ----");

  Body.init();
}

void loop() {

  BodyThread.run();

  if (Bluetooth.connected()) {

    if(isConnected == false)
      if(VERBOSE) Serial.println("Bluetooth - Connected");
    isConnected = true;

    if (Bluetooth.available()) {
      char read = Bluetooth.read();
      if(VERBOSE) {
        Serial.print("Incoming command -> ");
        Serial.println(read);
      }

      Sonar.getDist();

      if(read == 49) {
        hasToMoveForward = true;
        if(VERBOSE) Bluetooth.println("Executing - Move Forward");
      }
      if(read == 50) {
        hasToMoveBackward = true;
        if(VERBOSE) Bluetooth.println("Executing - Move Backward");
      }
      if(read == 51) {
        hasToTurnLeft = true;
        if(VERBOSE) Bluetooth.println("Executing - Turn Left");
      }
      if(read == 52) {
        hasToTurnRight = true;
        if(VERBOSE) Bluetooth.println("Executing - Turn Right");
      }
      if(read == 53) {
        hasToSleep = true;
        if(VERBOSE) Bluetooth.println("Executing - Sleep");
      }
      if(read == 54) {
        hasToWakeUp = true;
        if(VERBOSE) Bluetooth.println("Executing - Wake Up");
      }
    }

  }

}

