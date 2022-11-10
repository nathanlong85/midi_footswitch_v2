#include "Buttons.h"

// GenericButton functions
GenericButton::GenericButton(int pin, int ledPin) {
  pin_ = pin;
  state_ = LOW;

  led_.setPin(ledPin);
  led_.turnOff();

  pinMode(pin_, INPUT);
}

int GenericButton::getPin() { return pin_; }

void GenericButton::setState(bool state) { state_ = state; }

bool GenericButton::getState() { return state_; }

// ControlChangeButton functions
ControlChangeButton::ControlChangeButton(int pin, int ledPin, int ccNumber) 
: GenericButton(pin, ledPin) {
  ccNumber_ = ccNumber;
}

int ControlChangeButton::getCcNumber() {
  return ccNumber_;
}

void ControlChangeButton::setState(bool state) {
  setState(state);
  state_ == LOW ? led_.turnOff() : led_.turnOn();
}