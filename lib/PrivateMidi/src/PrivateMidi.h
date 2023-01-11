#ifndef PRIVATE_MIDI_H
#define PRIVATE_MIDI_H

#include <MIDI.h>

namespace PrivateMidi
{
  extern midi::MidiInterface<midi::SerialMIDI<HardwareSerial>> MIDI;

  const int sendChannel = 1;
  const int receiveChannel = 1;
  const int midiOffVal = 0;
  const int midiOnVal = 127;

  namespace CC
  {
    void logCcEvent(int ccNumber, int value);
    void sendOff(int ccNumber);
    void sendOn(int ccNumber);
  } // namespace CC
} // namespace PrivateMidi

#endif
