#ifndef BUTTON_H
#define BUTTON_H

#include <Arduino.h>
#include <DigitalLed.h>

// Generic button class. Does not manage an LED except to ensure
// that it's turned off when initialized
class Button {
protected:
  int pin_;
  bool state_;
  DigitalLed led_;

public: 
  Button(int pin, int ledPin);

  int getPin();
  void setState(bool state);
  bool getState();
};

#endif