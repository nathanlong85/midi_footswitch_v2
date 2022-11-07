#include <MIDI.h>

#include "digital_led.h"
#include "button.h"
#include "control_change_button.h"
#include "program_change_button.h"

int activePreset;

Button PresetStepDownButton = Button(43, &DigitalLed(28)); // Row 1 - Button 7
Button PresetStepUpButton   = Button(44, &DigitalLed(29)); // Row 1 - Button 8

ProgramChangeButton pcButtons[] = {
  ProgramChangeButton(37, &DigitalLed(22), 20), // Row 1 - Button 1
  ProgramChangeButton(38, &DigitalLed(23), 21), // Row 1 - Button 2
  ProgramChangeButton(39, &DigitalLed(24), 22), // Row 1 - Button 3
  ProgramChangeButton(40, &DigitalLed(25), 23), // Row 1 - Button 4
  ProgramChangeButton(41, &DigitalLed(26), 24), // Row 1 - Button 5
  ProgramChangeButton(42, &DigitalLed(27), 25), // Row 1 - Button 6
};

ControlChangeButton ccButtons[] = {
  ControlChangeButton(45, &DigitalLed(30), 20), // Row 2 - Button 9
  ControlChangeButton(46, &DigitalLed(31), 21), // Row 2 - Button 10
  ControlChangeButton(47, &DigitalLed(32), 22), // Row 2 - Button 11
  ControlChangeButton(48, &DigitalLed(33), 23), // Row 2 - Button 12
  ControlChangeButton(49, &DigitalLed(34), 24), // Row 2 - Button 13
  ControlChangeButton(50, &DigitalLed(35), 25)  // Row 2 - Button 14
};

void setup() {
  activePreset = 1;
}

void loop() {
  
}
