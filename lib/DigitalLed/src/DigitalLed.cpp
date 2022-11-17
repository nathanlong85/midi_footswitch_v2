#include "DigitalLed.h"

int DigitalLed::getPin() { return pin_; }

void DigitalLed::setPin(int pin)
{
  pin_ = pin;
  pinMode(pin_, OUTPUT);
}

void DigitalLed::turnOn() { digitalWrite(pin_, HIGH); }

void DigitalLed::turnOff() { digitalWrite(pin_, LOW); }
