#ifndef DIGITAL_LED_H
#define DIGITAL_LED_H

class DigitalLed {
 public:
  DigitalLed(int pin) {
    pin_ = pin;
    pinMode(pin_, OUTPUT);
  }

  int getPin() {
    return pin_;
  }

  void turnOn() {
    digitalWrite(pin_, HIGH);
  }

  void turnOff() {
    digitalWrite(pin_, LOW);
  }

 private:
  int pin_;
};

#endif
