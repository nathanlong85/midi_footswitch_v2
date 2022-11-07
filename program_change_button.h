#ifndef PROGRAM_CHANGE_BUTTON_H
#define PROGRAM_CHANGE_BUTTON_H

#include "button.h"

class ProgramChangeButton : public Button {
 public:
  ProgramChangeButton(int pin, DigitalLed *led, int pcNumber) : Button(pin, led) {
    pcNumber_ = pcNumber;
  }

  int getPcNumber() {
    return pcNumber_;
  }

 private:
  int pcNumber_;
};

#endif