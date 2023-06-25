# MIDI Footswitch v2

## The General Idea

The idea behind this is to be a customizable, solid footswitch for sending and receiving MIDI commands via USB. The following buttons will be implemented:

| Button | Count | Function |
|--------|-------|----------|
| MIDI PC  | 5 | Send a Program Change MIDI command to switch between presets, snapshots, etc. |
| MIDI CC  | 6 | Send a Control Change MIDI command to switch pedals on/off |
| PC StepDown | 1 | Lower the range of PC numbers corresponding with the buttons (e.g. 6-10 to 1-5) |
| PC StepUp | 1 | Raise the range of PC numbers corresponding with the buttons (e.g. 1-5 to 6-10) |
| TempoTap | 1 | This'll probably just end up being a CC button |

The main purpose of this footswitch is to control guitar plugins and presets, specifically in LiveProfessor, but the MIDI out features should all still work fine in another program. Additionally, the footswitch accepts MIDI input. This allows LiveProfessor to send (for example) CC commands when switching presets that will control the button states and have them match up with the plugin states in the preset.

For example, if I switch to a preset that has only a TS808 plugin enabled, the footswitch will first switch all CC buttons off. Then LiveProfessor can send a CC command back to the footswitch to let it know that the button that corresponds with the TS808 should be on.


## Components Used

| Type | Count | Brand | Model | Link | Notes |
|------|-------|-------|------|-------|-------|
| Arduino | 1 | Elegoo | Mega2560 | | Chosen for the large number of pins available for buttons |
| Connections Board | 1 | Custom | N/A | N/A | Mostly a convenience to make things as modular as possible. Also used in place of a breadboard for components such as resistors for the LEDs and switches |
| Display | 1 | Teyleten Robot | 2.42" 128x64 SSD1309 OLED | https://a.co/d/j11dIGv | Connected via SPI |
| LED | 14 | N/A | N/A | N/A | Red 5mm |
| LED Holder | 14 | DaierTek | 5MM LED Lamp Holder | https://a.co/d/9saOy9M | |
| SD Card Module | 1 | HiLetgo | Micro SD TF Card Adater Reader Module | https://a.co/d/amf9kn3 | Connected via SPI |
| SD Card | 1 | | | | No need for a high capacity as the only things being stored are configs |
| FootSwitch | 14 | ESUPPORT | Momentary SPST Button | https://a.co/d/4z8qo4Z | |
| TSR Jack | 1 | Kingsing | N/A | https://a.co/d/iaOluce | For the expression pedal |
| Switch | 1 | uxcell | SS12F32-G7 | https://a.co/d/9ZpxkgF | Mini slider switch to change USB modes from Midi to Arduino for uploads |
| USB Jack | 1 | QIANRENON | N/A | https://a.co/d/0RwaqkX | USB-A to USB-C converter and passthrough plate |

Additionally, various electrical components, connector wires, header pins, etc. were used. Those should be available in the KiCad schematics.


## Arduino Pin Assignments

| Number | Purpose | Notes |
|--------|---------|-------|
| 2 | SD Card SPI - CS | Ran out of pins to use near the other SPI pins |
| 22-26 | MIDI PC Button LEDs | Bottom row: buttons 1-5 |
| 27 | StepDown Button LED | Bottom row: button 6 |
| 28 | StepUp Button LED | Bottom row: button 7 |
| 29 | TempoTap Button LED | Bottom row: button 8 |
| 30-35 | MIDI CC Button LEDs | Top row: buttons 1-6 |
| 36-40 | MIDI PC Button Switches | Bottom row: buttons 1-5 |
| 41 | StepDown Button Switch | Bottom row: button 6 |
| 42 | StepUp Button Switch | Bottom row: button 7 |
| 43 | TempoTap Button Switch | Bottom row: button 8 |
| 44-49 | MIDI CC Button Switches | Top row: buttons 1-6 |
| 50 | SPI - MISO | Dictated by Arduino board |
| 51 | SPI - MOSI | Dictated by Arduino board |
| 52 | SPI - SCK | Dictated by Arduino board |
| 53 | Display SPI - CS | Conventional pin for first SPI device |
