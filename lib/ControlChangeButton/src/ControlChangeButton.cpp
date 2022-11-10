#include "ControlChangeButton.h"

ControlChangeButton::ControlChangeButton(int pin, int ledPin, int ccNumber) 
: Button(pin, ledPin) {
  ccNumber_ = ccNumber;
}

int ControlChangeButton::getCcNumber() {
  return ccNumber_;
}

void ControlChangeButton::setState(bool state) {
  setState(state);
  state_ == LOW ? led_.turnOff() : led_.turnOn();
}
