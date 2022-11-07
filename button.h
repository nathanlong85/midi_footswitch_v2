#ifndef BUTTON_H
#define BUTTON_H

#include "digital_led.h"

// Generic button class. Does not manage an LED except to ensure
// that it's turned off when initialized
class Button {
 public: 
  Button(int pin, DigitalLed *led) {
    pin_ = pin;
    led_ = led;
    
    state_ = LOW;
    led_->turnOff();

    pinMode(pin_, INPUT);
  }

  int getPin() {
    return pin_;
  }

  void setState(bool state) {
    state_ = state;
  }

  bool getState() {
    return state_;
  }

 protected:
  int pin_;
  bool state_;
  DigitalLed *led_;
};

#endif
