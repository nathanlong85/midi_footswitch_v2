#include "Oled.h"

Oled *Oled::instance_ = 0;

Oled::Oled()
{
  u8g2_.begin();
}

Oled *Oled::getInstance()
{
  if (!instance_)
  {
    instance_ = new Oled;
  }

  return instance_;
}

void Oled::writeText(u8g2_uint_t x, u8g2_uint_t y, const char *text)
{
  u8g2_.clearBuffer();
  u8g2_.setFont(u8g2_font_ncenB08_tr);
  u8g2_.drawStr(x, y, text);
  u8g2_.sendBuffer();
}
