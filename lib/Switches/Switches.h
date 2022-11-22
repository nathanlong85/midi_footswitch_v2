#ifndef SWITCHES_H
#define SWITCHES_H

#include <Arduino.h>
#include <ArduinoSTL.h> // C++ STL implementation for Arduino

class PhysicalSwitch
{
protected:
  const unsigned int minReadInterval_ = 10; // Minimum time (ms) between switch reads

  int pin_;        // The physical pin on the Arduino that the switch connects to
  bool lastState_; // The last state read from the switch

  // The time the state was last read and lastState_ was updated. Will not be
  // updated if the state was not read due to it being too soon
  unsigned long lastReadAt_;

  bool readyToRead(const unsigned long *currentTime);

public:
  PhysicalSwitch();

  void setPin(int pin);
  bool read();
};

#endif
