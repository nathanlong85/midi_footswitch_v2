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
  // Temp dev button assignments
  ProgramChangeButton::registerNew(45, 30);        // Row 1 - Button 1
  ProgramChangeButton::registerNew(46, 31);        // Row 1 - Button 2
  ProgramChangeStepButton::registerNew(47, 32, 1); // Row 1 - Button 7 - Step Up
  // ControlChangeButton::registerNew(47, 32, 22); // Row 2 - Button 11

  // Initialize the PC buttons (switchPin, ledPin)
  // ProgramChangeButton::registerNew(36, 22); // Row 1 - Button 1
  // ProgramChangeButton::registerNew(37, 23); // Row 1 - Button 2
  // ProgramChangeButton::registerNew(38, 24); // Row 1 - Button 3
  // ProgramChangeButton::registerNew(39, 25); // Row 1 - Button 4
  // ProgramChangeButton::registerNew(40, 26); // Row 1 - Button 5

  // Initialize the CC buttons (switchPin, ledPin, ccNumber)
  // ControlChangeButton::registerNew(45, 30, 20); // Row 2 - Button  9
  // ControlChangeButton::registerNew(46, 31, 21); // Row 2 - Button 10
  // ControlChangeButton::registerNew(47, 32, 22); // Row 2 - Button 11
  // ControlChangeButton::registerNew(48, 33, 23); // Row 2 - Button 12
  // ControlChangeButton::registerNew(49, 34, 24); // Row 2 - Button 13
  // ControlChangeButton::registerNew(50, 35, 25); // Row 2 - Button 14

  // Initialize the PC Step buttons
  // ProgramChangeStepButton::registerNew(41, 27, -1); // Row 1 - Button 6 - Step Down
  // ProgramChangeStepButton::registerNew(42, 28, 1);  // Row 1 - Button 7 - Step Up

  // Start listening to MIDI on channel 1 and set callbacks to
  // listen for specific incoming MIDI messages
  PrivateMidi::MIDI.begin(1);

  // Initialize the OLED display
  Oled::getInstance()->displayInit(false);
  Oled::getInstance()->addLogLine("MIDI controller ready");
}

void loop()
{
  // Check for incoming MIDI messages
  PrivateMidi::MIDI.read();

  // Check for any pressed CC buttons
  ControlChangeButton::read();

  // Check for any pressed PC buttons
  ProgramChangeButton::read();

  // Check for a pressed PC StepUp or PC StepDown button
  ProgramChangeStepButton::read();
}
