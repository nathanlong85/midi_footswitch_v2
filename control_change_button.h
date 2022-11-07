#ifndef CONTROL_CHANGE_BUTTON_H
#define CONTROL_CHANGE_BUTTON_H

#include "button.h"

class ControlChangeButton : public Button {
 public:
  ControlChangeButton(int pin, DigitalLed *led, int ccNumber) : Button(pin, led) {
    ccNumber_ = ccNumber;
  }

  int getCcNumber() {
    return ccNumber_;
  }

  void setState(bool state) {
    Button::setState(state);
    state_ == LOW ? led_->turnOff() : led_->turnOn();
  }

 private:
  int ccNumber_;
};

#endif