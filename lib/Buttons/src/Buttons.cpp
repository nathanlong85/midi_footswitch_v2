#include "Buttons.h"

// START Button::Button 
Button::Button(int pin) {
  pin_ = pin;
  pinMode(pin_, INPUT);
}
// END Button::Button 

// START LedButton
LedButton::LedButton(int pin, int ledPin)
: Button(pin) {
  led_.setPin(ledPin);
  led_.turnOff();
}
// END LedButton

// START StatelessLedButton
StatelessLedButton::StatelessLedButton(int pin, int ledPin)
: LedButton(pin, ledPin) {}
// END StatelessLedButton

// START StatefulLedButton
StatefulLedButton::StatefulLedButton(int pin, int ledPin)
: LedButton(pin, ledPin) {
  state_ = LOW;
}

void StatefulLedButton::manageState() {
  // Ensure the button state isn't being read too quickly in succession
  if (millis() - lastRead <= 350) { return; }

  bool switchState = digitalRead(pin_);  
  if (switchState == HIGH) { setState(); }
}
// END StatefulLedButton

// START ControlChangeButton
ControlChangeButton::ControlChangeButton(int pin, int ledPin, int ccNumber) 
: StatefulLedButton(pin, ledPin) {
  ccNumber_ = ccNumber;
}

void ControlChangeButton::setState() {
  state_ == LOW ? led_.turnOff() : led_.turnOn();
}
// END ControlChangeButton