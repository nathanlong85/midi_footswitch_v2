#include "Oled.h"

Oled *Oled::instance_ = 0;

Oled::Oled()
{
  u8g2_.begin();

  u8g2log_.begin(u8g2logWidth, u8g2logHeight, u8g2logBuffer_);
  u8g2log_.setLineHeightOffset(1);
  u8g2log_.setRedrawMode(0);
}

Oled *Oled::getInstance()
{
  if (!instance_)
  {
    instance_ = new Oled;
  }

  return instance_;
}

void Oled::displayInit(bool clearBuffer)
{
  if (clearBuffer)
  {
    u8g2_.clearBuffer();
  }

  // Preset headers
  u8g2_.setFont(u8g2_font_6x12_tf);
  u8g2_.drawStr(0, 10, "Active");
  u8g2_.drawStr(48, 10, "Range");

  // Horizontal log divider
  u8g2_.drawHLine(0, 31, 93);

  // Draw the expression pedal frame
  u8g2_.setFont(u8g2_font_5x7_tf);
  u8g2_.drawStr(109, 6, "EXP");
  u8g2_.drawFrame(111, 7, 10, 50);

  u8g2_.sendBuffer();

  updateActivePreset();
  updatePresetRange();
  updateExpressionPedalLevel();
}

void Oled::updateActivePreset()
{
  u8g2_.clearBuffer();

  u8g2_.setFont(u8g2_font_6x12_tf);
  u8g2_.drawStr(0, 23, "127");
  u8g2_.updateDisplayArea(0, 2, 3, 1);
}

void Oled::updatePresetRange()
{
  u8g2_.clearBuffer();

  u8g2_.setFont(u8g2_font_6x12_tf);
  u8g2_.drawStr(48, 23, "108-127");
  u8g2_.updateDisplayArea(6, 2, 6, 1);
}

void Oled::updateExpressionPedalLevel()
{
  u8g2_.clearBuffer();

  u8g2_.drawBox(112, 30, 8, screenHeight - 7);
  u8g2_.updateDisplayArea(14, 1, 1, 6);
}

void Oled::addLogLine(char *message)
{
  u8g2log_.print(message);
  u8g2log_.print("\n");

  u8g2_.clearBuffer();
  u8g2_.setFont(u8g2_font_tom_thumb_4x6_mf);
  u8g2_.drawLog(0, 41, u8g2log_);
  u8g2_.updateDisplayArea(0, 4, 12, 4);
}
