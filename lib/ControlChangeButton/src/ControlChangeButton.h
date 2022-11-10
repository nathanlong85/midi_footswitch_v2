#ifndef CONTROL_CHANGE_BUTTON_H
#define CONTROL_CHANGE_BUTTON_H

#include <Arduino.h>
#include <DigitalLed.h>
#include <Button.h>

class ControlChangeButton: public Button {
private:
  int ccNumber_;

public:
  ControlChangeButton(int pin, int ledPin, int ccNumber);

  int getCcNumber();
  void setState(bool state);
};

#endif