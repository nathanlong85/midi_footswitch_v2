#include "Switches.h"

PhysicalSwitch::PhysicalSwitch()
{
  lastReadAt_ = 0;
}

void PhysicalSwitch::setPin(int pin)
{
  pin_ = pin;
  pinMode(pin_, INPUT);
}

// A switch is ready to read when it has either never been read
// before or if the minReadInterval has passed
bool PhysicalSwitch::readyToRead()
{
  return lastReadAt_ == 0 ||
         millis() - lastReadAt_ >= minReadInterval_;
}

bool PhysicalSwitch::readState()
{
  if (readyToRead())
  {
    lastState_ = digitalRead(pin_);
    lastReadAt_ = millis();
  }

  return lastState_;
}
