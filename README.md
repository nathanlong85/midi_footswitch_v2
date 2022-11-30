# MIDI Footswitch v2

## Components Used

| Type | Count | Brand | Model | Link | Notes |
|------|-------|-------|------|-------|-------|
| Arduino | 1 | Elegoo | Mega2560 | | Chosen for the large number of pins available for buttons |
| AVR Programmer | 1 | HiLetgo | USBTinyISP | https://a.co/d/3sgW6Hk | Necessary for uploading firmware since Hiduino is using the Arduino's USB port for MIDI |
| Connections Board | 1 | Custom | N/A | N/A | Mostly a convenience to make things as modular as possible. Also used in place of a breadboard for components such as resistors for the LEDs and switches |
| Display | 1 | Teyleten Robot | 2.42" 128x64 SSD1309 OLED | https://a.co/d/j11dIGv | Connected via SPI |
| LED | 14 | | | | 5mm |
| LED Holder | 14 | | | | |
| SD Card | 1 | | | | No need for a high capacity as the only things being stored are configs |
| SD Card Module | 1 | | | | Connected via SPI |
| Switch | 1 | | | | |
| TSR Jack | 1 | | | | |

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
