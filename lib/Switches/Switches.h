#ifndef SWITCHES_H
#define SWITCHES_H

#include <Arduino.h>

class PhysicalSwitch
{
protected:
  int pin_;                                  // The physical pin on the Arduino that the switch connects to
  bool lastState_;                           // The last state read from the switch
  const unsigned int minReadInterval_ = 350; // Minimum time (ms) between switch reads

  // The time the state was last read and lastState_ was updated. Will not be
  // updated if the state was not read due to it being too soon
  unsigned long lastReadAt_;

  bool readyToRead();

public:
  PhysicalSwitch();

  void setPin(int pin);
  bool readState();
};

class MomentaryPushButton : public PhysicalSwitch
{
};

#endif
