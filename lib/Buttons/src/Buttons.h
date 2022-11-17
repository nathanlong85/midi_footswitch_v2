#ifndef BUTTONS_H
#define BUTTONS_H

#include <Arduino.h>    // Basic Arduino lib
#include <ArduinoSTL.h> // C++ STL implementation for Arduino

#include <vector>

// Private
#include <DigitalLed.h>
#include <Switches.h>

// --- Terminology ---
// * LED         - The LED associated with the button. Usually located above
//                 the physical switch on the footswitch
//
// * State       - Whether the button or switch is on or off. Represented by
//                 either HIGH or LOW, respectively
//
// * Switch      - The physical switch on the footswitch
//   * LOW State   - The switch is not physically pressed
//   * HIGH State  - The switch is physically pressed down
//
// * Button      - The "logical" button, including the LED. Separate from
//                 the physical switch
//   * LOW State   - The button is not "on" and the LED is off
//   * HIGH State  - The button is "on" and the LED may or may not be on,
//                   depending on the button type
//
// --- Button Types ---
// * Control Change (CC)  - Derived from the base button. Sends a MIDI CC
//                          message and manages an LED on each state change
//   * LOW State
//     * LED                - Turns off
//     * CC Message         - Sends 0
//   * HIGH State
//     * LED                - Turns on
//     * CC Message         - Sends 127
//
// * Program Change (PC)  - Derived from the base button. Sends a MIDI PC
//                          message and manages an LED on each state change.
//                          Only a single PC button can be HIGH at any time
//   * LOW State
//     * LED                - Turns off
//   * HIGH State
//     * LED                - Turns on
//     * PC Message         - Sends 127
//     * Turns off any other HIGH state PC buttons

template <class T>
class Button
{
protected:
  static std::vector<T> registered;
  MomentaryPushButton switch_; // Physical switch instance

public:
  static void read();

  Button(int pin);
  // void readSwitchState();
};

// Inherit to add LED characteristics to a Button
class LedButton
{
protected:
  DigitalLed led_; // LED instance

public:
  LedButton(int ledPin);
};

// Inherit to add state to a button
class StatefulButton
{
protected:
  bool state_; // Logical button state

public:
  StatefulButton();
};

class ControlChangeButton : public Button<ControlChangeButton>,
                            public LedButton,
                            public StatefulButton
{
private:
  int ccNumber_;

public:
  static void registerNew(int pin, int ledPin, int ccNumber);
  ControlChangeButton(int pin, int ledPin, int ccNumber);
};

#include "Buttons.tpp"
#endif