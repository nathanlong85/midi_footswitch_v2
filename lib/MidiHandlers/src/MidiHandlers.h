#ifndef MIDI_HANDLERS_H
#define MIDI_HANDLERS_H

#include <Arduino.h>
#include <MIDI.h>

void handleControlChange(byte channel, byte number, byte value);

#endif