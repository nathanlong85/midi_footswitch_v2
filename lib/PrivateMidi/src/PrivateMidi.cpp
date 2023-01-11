#include "PrivateMidi.h"
#include "Oled.h"

namespace PrivateMidi
{
  MIDI_CREATE_DEFAULT_INSTANCE();

  namespace CC
  {
    void logCcEvent(int ccNumber, int value)
    {
      char buf[18];
      snprintf(buf, 18, "CC Out: %d -> %d", ccNumber, value);

      Oled::getInstance()->addLogLine(buf);
    }

    void sendOff(int ccNumber)
    {
      MIDI.sendControlChange(ccNumber, midiOffVal, sendChannel);
      logCcEvent(ccNumber, midiOffVal);
    }

    void sendOn(int ccNumber)
    {
      MIDI.sendControlChange(ccNumber, midiOnVal, sendChannel);
      logCcEvent(ccNumber, midiOnVal);
    }
  } // namespace CC
} // namespace PrivateMidi
