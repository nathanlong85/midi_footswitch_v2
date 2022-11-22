#include "Buttons.h"

LedButton::LedButton(int ledPin)
{
  led_.setPin(ledPin);
  led_.turnOff();
}

ControlChangeButton::ControlChangeButton(int switchPin, int ledPin, int ccNumber)
    : Button<ControlChangeButton>(switchPin), LedButton(ledPin)
{
  ccNumber_ = ccNumber;
}

void ControlChangeButton::registerNew(int switchPin, int ledPin, int ccNumber)
{
  registered.push_back(
      ControlChangeButton(switchPin, ledPin, ccNumber));
}

void ControlChangeButton::handlePress()
{
  bool switchState = switch_.read();

  if (switchState == previousSwitchState_)
  {
    return;
  }

  previousSwitchState_ = switchState;

  if (switchState == HIGH)
  {
    if (currentState_ == LOW)
    {
      currentState_ = HIGH;
      led_.turnOn();
      PrivateMidi::CC::sendOn(ccNumber_);
    }
    else if (currentState_ == HIGH)
    {
      currentState_ = LOW;
      led_.turnOff();
      PrivateMidi::CC::sendOff(ccNumber_);
    }
  }
}
