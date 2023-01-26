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

int ProgramChangeButton::programValue()
{
  return baseNumber_ +
         (registeredCount() * ProgramChangeStepButton::stepMultiplier);
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

int ProgramChangeStepButton::stepMultiplier = 0;

ProgramChangeStepButton::ProgramChangeStepButton(int switchPin, int ledPin, int stepMultiplierAddend)
    : Button<ProgramChangeStepButton>(switchPin), LedButton(ledPin)
{
  stepMultiplierAddend_ = stepMultiplierAddend;
}

void ProgramChangeStepButton::registerNew(int switchPin, int ledPin, int stepMultiplierAddend)
{
  registered.push_back(
      ProgramChangeStepButton(switchPin, ledPin, stepMultiplierAddend));
}

void ProgramChangeStepButton::handlePress()
{
  bool switchState = switch_.read();

  if (switchState != previousSwitchState_)
  {
    previousSwitchState_ = switchState;

    if (switchState == HIGH)
    {
      int newStepMultiplier = stepMultiplier + stepMultiplierAddend_;

      if (newStepMultiplier >= 0 && newStepMultiplier < )
      {
        stepMultiplier = newStepMultiplier;

        int rangeMin = ProgramChangeButton::registeredCount() * stepMultiplier;
        int rangeMax = (rangeMin + ProgramChangeButton::registeredCount()) - 1;

        Oled::getInstance()->updatePresetRange(rangeMin, rangeMax);
      }
      else
      {
        return;
      }
    }
  }
}
