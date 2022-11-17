#include "Buttons.h"

template <class T>
Button<T>::Button(int pin)
{
  switch_.setPin(pin);
}

LedButton::LedButton(int ledPin)
{
  led_.setPin(ledPin);
  led_.turnOff();
}

StatefulButton::StatefulButton()
{
  state_ = LOW;
}

ControlChangeButton::ControlChangeButton(int pin, int ledPin, int ccNumber)
    : Button<ControlChangeButton>(pin), LedButton(ledPin), StatefulButton()
{
  ccNumber_ = ccNumber;
}

void ControlChangeButton::registerNew(int pin, int ledPin, int ccNumber)
{
  registered.push_back(
      ControlChangeButton(pin, ledPin, ccNumber));
}

// void ControlChangeButton::setState()
// {
//   state_ == LOW ? led_.turnOff() : led_.turnOn();
// }

// void StatefulButton::manageState()
// {
// Ensure the button state isn't being read too quickly in succession
// if (millis() - lastRead <= 350)
// {
//   return;
// }

// bool switchState = digitalRead(pin_);
// if (switchState == HIGH)
// {
//   setState();
// }
// }
