# Anemometer Arduino

![Anemometer Overview](/images/overview.jpg)

The goals of this project are to:

1. Display live wind speed data onto an SPI screen
1. Set up a server to give access to the wind speed variable.

[Short video overview](https://drive.google.com/open?id=1yNKfoHhbNAwHX3za7skcFMAHot8nph72)

## Required Libraries

- Adafruit GFX Library by Adafruit
- Adafruit ST7735 and ST7789 Library by Adafruit
- ESP Async WebServer by Hristo Gochkov
- AsyncTCP by Hristo Gochkov
- ESPAsyncTCP by Hristo Gochkov

## Material

1. [Anemometer](https://wiki.dfrobot.com/Wind_Speed_Sensor_Voltage_Type_0-5V__SKU_SEN0170)
1. [WeMos MCU](https://www.banggood.com/Geekcreit-D1-R2-V2_1_0-WiFi-Uno-Module-Based-ESP8266-Module-For-Arduino-Nodemcu-Compatible-p-1085610.html?rmmds=search&cur_warehouse=CN) or an Arduino with a [ESP8266](https://www.banggood.com/ESP-01S-ESP8266-Serial-to-WiFi-Module-Wireless-Transparent-Transmission-Industrial-Grade-Smart-Home-Internet-of-Things-IOT-p-1471346.html?rmmds=search&cur_warehouse=CN) module.
1. [ST7735 Display](https://www.banggood.com/Geekcreit-0_96-Inch-7Pin-HD-Color-IPS-Screen-TFT-LCD-Display-SPI-ST7735-Module-p-1370911.html?rmmds=search&cur_warehouse=CN) (or any other screen of your choice)
1. [TTP226 (8  touch buttons)](https://www.banggood.com/TTP226-8-Channel-Digital-Capacitive-Switch-Touch-Sensor-Module-p-1557893.html?rmmds=search&cur_warehouse=CN) or [TTP224 (4 touch buttons)](https://www.banggood.com/TTP224-4CH-Channel-Capacitive-Touch-Switch-Digital-Touch-Sensor-Module-p-1540570.html?rmmds=search&cur_warehouse=CN)
1. Two Arduinos
1. [One LED](https://www.banggood.com/50Pcs-5mm-Round-Red-Green-Blue-Yellow-White-Color-Diffused-LED-Light-Diode-Lamp-p-1077190.html?rmmds=search&ID=228&cur_warehouse=CN)

## Wiring

### Anemometer

- The voltage wire is attached to the wires of a 12V supply.
- The data wire is inserted into the *Pin 12* of the Arduino with the transmitter module.
- The ground wire is inserted into the *Ground Pin* of the same Arduino.

### FS1000A

- [Pinout for the Arduino with the transmitter module](https://cdn.instructables.com/FZH/IW05/HM8DG0TI/FZHIW05HM8DG0TI.LARGE.jpg?auto=webp&frame=1&width=625&fit=bounds)
- [Pinout for the Arduino with the receiver module](https://cdn.instructables.com/FIT/MUZG/HM8DG0TF/FITMUZGHM8DG0TF.LARGE.jpg?auto=webp&frame=1&width=575&fit=bounds)

### ST7735

| Name  | Arduino Pin  |
|-------|--------------|
| LED   | 3.3V         |
| SCK   | 13           |
| SDA   | 11           |
| A0    | 9            |
| RESET | 8 (optional) |
| CS    | 10           |
| GND   | Ground       |
| VCC   | 5V           |

### TTP22X Touch Pad

| Name  | Arduino Pin  |
|-------|--------------|
| VCC   | 5V           |
| GND   | Ground       |
| OUTX  | Digital Pin  |




