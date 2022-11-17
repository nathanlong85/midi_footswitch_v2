#include <Arduino.h>

// C++ STL implementation for Arduino
#include <ArduinoSTL.h>
#include <vector>

// Display
#include <SPI.h>
#include <U8g2lib.h>

// MIDI
#include <MIDI.h>

// Private
#include <DigitalLed.h>
#include <Switches.h>
#include <Buttons.h>
#include <MidiHandlers.h>

MIDI_CREATE_DEFAULT_INSTANCE();

void setup()
{
  // Initialize the CC buttons
  ControlChangeButton::registerNew(45, 30, 20); // Row 2 - Button  9
  ControlChangeButton::registerNew(46, 31, 21); // Row 2 - Button 10
  ControlChangeButton::registerNew(47, 32, 22); // Row 2 - Button 11
  ControlChangeButton::registerNew(48, 33, 23); // Row 2 - Button 12
  ControlChangeButton::registerNew(49, 34, 24); // Row 2 - Button 13
  ControlChangeButton::registerNew(50, 35, 25); // Row 2 - Button 14

  // Start listening to MIDI on channel 1 and set callbacks to
  // listen for specific incoming MIDI messages
  MIDI.begin(1);
}

void loop()
{
  MIDI.read();
  ControlChangeButton::read();
}
