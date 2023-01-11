#ifndef OLED_H
#define OLED_H

#include <SPI.h>
#include <U8g2lib.h>

class Oled // Singleton Class
{
  static Oled *instance_;

  // Physical connections to the Arduino
  static const uint8_t resPin = 8;
  static const uint8_t dcPin = 9;
  static const uint8_t csPin = 53;

  // Physical pixel dimensions are 128x64. The library starts at 0 instead of 1
  static const int screenWidth = 63;
  static const int screenHeight = 127;

  // Logger dimensions. Uses character dimensions, not pixels
  static const int u8g2logWidth = 24;
  static const int u8g2logHeight = 4;

  U8G2LOG u8g2log_;

  U8G2_SSD1309_128X64_NONAME0_F_4W_HW_SPI u8g2_{
      U8G2_R0, csPin, dcPin, resPin};

  uint8_t u8g2logBuffer_[u8g2logWidth * u8g2logHeight];

public:
  static Oled *getInstance();

  // Clear and (re)draw the static display components
  void displayInit(bool clearBuffer = false);

  // Update the screen section for "Active"
  void updateActivePreset();

  // Update the screen section for "Range"
  void updatePresetRange();

  // Update the expression pedal bar
  void updateExpressionPedalLevel();

  // Adds a new log line to the logger section of the screen
  void addLogLine(char *message);

private:
  // Hide the constructor since this is a Singleton Class
  Oled();
};

#endif
