#ifndef OLED_H
#define OLED_H

#include <SPI.h>
#include <U8g2lib.h>

class Oled // Singleton Class
{
  static Oled *instance_;

  const uint8_t sckPin = 13;
  const uint8_t sdaPin = 11;
  const uint8_t resPin = 8;
  const uint8_t dcPin = 7;
  const uint8_t csPin = 10;

  U8G2_SSD1309_128X64_NONAME2_1_4W_SW_SPI u8g2_{
      U8G2_R0, sckPin, sdaPin, csPin, dcPin, resPin};

  Oled();

public:
  static Oled *getInstance();
  void writeText(u8g2_uint_t x, u8g2_uint_t y, const char *text);
};

#endif
