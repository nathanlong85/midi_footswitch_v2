#include <Arduino.h>

// C++ STL implementation for Arduino
#include <ArduinoSTL.h>
#include <vector>

// Private
#include <PrivateMidi.h>
#include <Buttons.h>
#include <Oled.h>

void setup()
{
  // Initialize the CC buttons. (switchPin, ledPin, ccNumber)
  ControlChangeButton::registerNew(45, 30, 20); // Row 2 - Button  9
  ControlChangeButton::registerNew(46, 31, 21); // Row 2 - Button 10
  ControlChangeButton::registerNew(47, 32, 22); // Row 2 - Button 11
  ControlChangeButton::registerNew(48, 33, 23); // Row 2 - Button 12
  ControlChangeButton::registerNew(49, 34, 24); // Row 2 - Button 13
  ControlChangeButton::registerNew(50, 35, 25); // Row 2 - Button 14

  // Start listening to MIDI on channel 1 and set callbacks to
  // listen for specific incoming MIDI messages
  PrivateMidi::MIDI.begin(1);

  // Initialize the OLED display
  Oled::getInstance()->displayInit();
}

void loop()
{
  // Check for incoming MIDI messages
  PrivateMidi::MIDI.read();

  // Check for any pressed CC buttons
  ControlChangeButton::read();
}
