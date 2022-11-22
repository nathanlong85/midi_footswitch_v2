#ifndef DIGITAL_LED_H
#define DIGITAL_LED_H

#include <Arduino.h>

class DigitalLed
{
private:
  int pin_;

public:
  DigitalLed();

  int getPin();

  void setPin(int pin);
  void turnOn();
  void turnOff();
};

#endif
