#ifndef BUTTONS_H
#define BUTTONS_H

#include <Arduino.h>
#include <DigitalLed.h>

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

// Base button class to derive from. Does not manage state or an LED
class Button {
protected:
  int pin_;                // Arduino pin that the switch is connected to
  unsigned long lastRead;  // When the switch state was last read

public: 
  Button(int pin);
};

// Basic button with an LED to derive from
class LedButton: public Button {
protected:
  DigitalLed led_;  // LED instance

public:
  LedButton(int pin, int ledPin);
};

// Basic button with an LED that does not have any state
class StatelessLedButton: public LedButton {
public:
  StatelessLedButton(int pin, int ledPin);
};

// Basic button with an LED that manages state as well
class StatefulLedButton: public LedButton {
protected:
  bool state_;      // Button state

public:
  StatefulLedButton(int pin, int ledPin);
  virtual void setState() = 0;
  void manageState();
};

// ControlChange button. Stateful with an LED
class ControlChangeButton: public StatefulLedButton {
private:
  int ccNumber_;

public:
  ControlChangeButton(int pin, int ledPin, int ccNumber);
  void setState();
};

#endif