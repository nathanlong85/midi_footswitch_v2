#ifndef BUTTONS_H
#define BUTTONS_H

#include <Arduino.h>
#include <DigitalLed.h>

// Generic button class. Does not manage an LED except to ensure
// that it's turned off when initialized
class GenericButton {
protected:
  int pin_;
  bool state_;
  DigitalLed led_;

public: 
  GenericButton(int pin, int ledPin);

  int getPin();
  void setState(bool state);
  bool getState();
};

// Control Change button class. Manages an LED.
class ControlChangeButton: public GenericButton {
private:
  int ccNumber_;

public:
  ControlChangeButton(int pin, int ledPin, int ccNumber);

  int getCcNumber();
  void setState(bool state);
};

#endif