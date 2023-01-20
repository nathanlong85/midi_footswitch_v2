#ifndef BUTTONS_H
#define BUTTONS_H

#include <Arduino.h>    // Basic Arduino lib
#include <ArduinoSTL.h> // C++ STL implementation for Arduino
#include <vector>

// Private
#include <PrivateMidi.h>
#include <DigitalLed.h>
#include <Switches.h>
#include <Oled.h>

template <class T>
class Button
{
protected:
  static std::vector<T> registered; // Registered button instances

  PhysicalSwitch switch_; // Physical switch instance
  bool previousSwitchState_ = false;

public:
  static void read();
  explicit Button(int switchPin);
};

class LedButton // Inherit to add LED characteristics to a Button
{
protected:
  DigitalLed led_; // LED instance

public:
  explicit LedButton(int ledPin);
};

class StatefulButton // Inherit to add state to a button
{
protected:
  bool currentState_ = LOW; // Button state
};

class ControlChangeButton : public Button<ControlChangeButton>,
                            public LedButton,
                            public StatefulButton
{

private:
  int ccNumber_;

public:
  static void registerNew(int switchPin, int ledPin, int ccNumber);
  static void changeStateAll(bool newState);

  ControlChangeButton(int switchPin, int ledPin, int ccNumber);
  void handlePress();
};

class ProgramChangeButton : public Button<ProgramChangeButton>,
                            public LedButton,
                            public StatefulButton
{

private:
  static ProgramChangeButton *activeButton;
  static int nextAssignableBaseNumber;

  int baseNumber_;

public:
  static void registerNew(int switchPin, int ledPin);

  ProgramChangeButton(int switchPin, int ledPin);
  void handlePress();
};

class ProgramChangeStepButton : public Button<ProgramChangeStepButton>,
                                public LedButton,
                                public StatefulButton
{
private:
int stepMultiplierModifier_;

public:
  static int stepMultiplier;
  static void registerNew(int switchPin, int ledPin, int stepMultiplierModifier);

  ProgramChangeStepButton(int switchPin, int ledPin, int stepMultiplierModifier);
  void handlePress();
};

#include "Buttons.tpp"
#endif
