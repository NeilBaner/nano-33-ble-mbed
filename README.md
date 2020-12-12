# nano-33-ble-mbed

This repository contains some sample sketches that demonstrate the use of ARM Mbed OS on the new Arduino Nano 33 BLE/BLE Sense microcontrollers. There's very little documentation and even fewer examples of how to use mbed OS with this particular board, so I thought I would share my own experiments for others to learn from. 

## Using the sketches

1. Make sure you have the [latest version of the Arduino IDE](https://www.arduino.cc/en/software/) installed on your computer. For Windows, I recommend using the downloadable .exe/.zip installer, and not using the Windows Store version, as the latter is known to have problems sometimes. 

1. Make sure you have the latest version of "Arduino mbed-enabled boards" installed in the Boards Manager. Follow [this guide](https://www.arduino.cc/en/Guide/NANO33BLE/) to do so. It also has some other useful information that might be worth reading too. 

1. **IMPORTANT** To put the Arduino Nano 33 BLE/BLE Sense into Bootloader Mode, double-press the reset button while it is plugged into your computer. This will allow you to program your board. Once a program has been uploaded to your board, it will no longer appear as a programmable device in the Arduino IDE, until you put the board into Bootloader Mode again. 
