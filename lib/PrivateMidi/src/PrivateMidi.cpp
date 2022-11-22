#include "PrivateMidi.h"

namespace PrivateMidi
{
  MIDI_CREATE_DEFAULT_INSTANCE();

  namespace CC
  {
    void sendOff(int ccNumber)
    {
      MIDI.sendControlChange(ccNumber, midiOffVal, sendChannel);
    }

    void sendOn(int ccNumber)
    {
      MIDI.sendControlChange(ccNumber, midiOnVal, sendChannel);
    }
  } // namespace CC
} // namespace PrivateMidi
