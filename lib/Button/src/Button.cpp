#include "button.h"

Button::Button(int pin, int ledPin) {
  pin_ = pin;
  state_ = LOW;

  led_.setPin(ledPin);
  led_.turnOff();

  pinMode(pin_, INPUT);
}

int Button::getPin() { return pin_; }

void Button::setState(bool state) { state_ = state; }

bool Button::getState() { return state_; }