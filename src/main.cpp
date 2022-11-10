#include <Arduino.h>

// Display
#include <SPI.h>
#include <U8g2lib.h>

// MIDI
#include <MIDI.h>

// Private
#include <DigitalLed.h>
#include <Buttons.h>
#include <MidiHandlers.h>

ControlChangeButton ccButtons[] = {
  ControlChangeButton(45, 30, 20), // Row 2 - Button 9
  ControlChangeButton(46, 31, 21), // Row 2 - Button 10
  ControlChangeButton(47, 32, 22), // Row 2 - Button 11
  ControlChangeButton(48, 33, 23), // Row 2 - Button 12
  ControlChangeButton(49, 34, 24), // Row 2 - Button 13
  ControlChangeButton(50, 35, 25)  // Row 2 - Button 14
};

MIDI_CREATE_DEFAULT_INSTANCE();

void setup() {
  // Start listening to MIDI on channel 1 and set callbacks to
  // listen for specific incoming MIDI messages
  MIDI.begin(1);
}

void loop() {
  MIDI.read();

  for(size_t i = 0, size = sizeof(ccButtons); i < size; i++) {
    // ControlChangeButton button = ccButtons[i];
  }
}
