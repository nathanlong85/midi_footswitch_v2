#include "Switches.h"

PhysicalSwitch::PhysicalSwitch()
{
  pin_ = 0;
  lastState_ = LOW;
  lastReadAt_ = 0;
}

void PhysicalSwitch::setPin(int pin)
{
  pin_ = pin;
  pinMode(pin_, INPUT);
}

// A switch is ready to read when it has either never been read
// before or if the minReadInterval has passed
bool PhysicalSwitch::readyToRead(const unsigned long *currentTime)
{
  return lastReadAt_ == 0 ||
         *currentTime - lastReadAt_ >= minReadInterval_;
}

bool PhysicalSwitch::read()
{
  unsigned long currentTime = millis();

  if (readyToRead(&currentTime))
  {
    lastState_ = digitalRead(pin_);
    lastReadAt_ = currentTime;
  }

  return lastState_;
}
