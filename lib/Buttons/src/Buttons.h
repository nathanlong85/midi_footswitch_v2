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

  ControlChangeButton(int switchPin, int ledPin, int ccNumber);
  void handlePress();
};

#include "Buttons.tpp"
#endif
