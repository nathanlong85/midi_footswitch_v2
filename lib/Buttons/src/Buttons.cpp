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

  if (switchState != previousSwitchState_)
  {
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
}

void ControlChangeButton::changeStateAll(bool newState)
{
  for (size_t i = 0; i < registered.size(); i++)
  {
    ControlChangeButton *button = &registered[i];

    button->currentState_ = newState;
    newState == HIGH ? button->led_.turnOn() : button->led_.turnOff();
  }
}

int ProgramChangeButton::nextAssignableBaseNumber = 0;
ProgramChangeButton *ProgramChangeButton::activeButton = NULL;

ProgramChangeButton::ProgramChangeButton(int switchPin, int ledPin)
    : Button<ProgramChangeButton>(switchPin), LedButton(ledPin)
{
  baseNumber_ = nextAssignableBaseNumber;
  nextAssignableBaseNumber++;
}

void ProgramChangeButton::registerNew(int switchPin, int ledPin)
{
  registered.push_back(
      ProgramChangeButton(switchPin, ledPin));
}

void ProgramChangeButton::handlePress()
{
  bool switchState = switch_.read();

  if (switchState != previousSwitchState_)
  {
    previousSwitchState_ = switchState;

    if (switchState == HIGH)
    {
      if (activeButton && activeButton != this)
      {
        activeButton->currentState_ = LOW;
        activeButton->led_.turnOff();
      }

      activeButton = this;
      activeButton->currentState_ = HIGH;
      activeButton->led_.turnOn();

      ControlChangeButton::changeStateAll(LOW);

      PrivateMidi::PC::send(baseNumber_);
      Oled::getInstance()->updateActivePreset(baseNumber_);
    }
  }
}

int ProgramChangeStepButton::stepMultiplier = 1;

ProgramChangeStepButton::ProgramChangeStepButton(int switchPin, int ledPin, int stepMultiplierModifier)
    : Button<ProgramChangeStepButton>(switchPin), LedButton(ledPin)
{
  stepMultiplierModifier_ = stepMultiplierModifier;
}

void ProgramChangeStepButton::registerNew(int switchPin, int ledPin, int stepMultiplierModifier)
{
  registered.push_back(
      ProgramChangeStepButton(switchPin, ledPin, stepMultiplierModifier));
}

void ProgramChangeStepButton::handlePress()
{
  bool switchState = switch_.read();

  if (switchState != previousSwitchState_)
  {
    previousSwitchState_ = switchState;

    if (switchState == HIGH)
    {
      if (stepMultiplier + stepMultiplierModifier_ >= 1)
      {
        stepMultiplier += stepMultiplierModifier_;
      }
      else
      {
        return;
      }

      
    }
  }
}
