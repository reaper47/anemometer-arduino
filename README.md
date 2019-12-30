# Anemometer Arduino

![Anemometer Overview](/images/overview.jpg)

The goals of this project are to:

1. Display live wind speed data onto a SPI screen
1. Send the data from the transmitter Arduino to the receiver Arduino

[Short overview video](https://drive.google.com/open?id=1yNKfoHhbNAwHX3za7skcFMAHot8nph72)

## Required Libraries

- Adafruit GFX Library by Adafruit
- Adafruit ST7735 and ST7789 Library by Adafruit
- VirtualWire by Mike McCauley

## Material

1. [Anemometer](https://wiki.dfrobot.com/Wind_Speed_Sensor_Voltage_Type_0-5V__SKU_SEN0170)
1. [FS1000A RF Transmitter and Receiver Modules](https://www.aliexpress.com/item/32896035786.html?spm=2114.search0302.3.23.7165161bYrCHQ0&ws_ab_test=searchweb0_0,searchweb201602_0,searchweb201603_0,ppcSwitch_0&algo_pvid=722cfee0-dc60-48e2-b453-23c4ac2dda30&algo_expid=722cfee0-dc60-48e2-b453-23c4ac2dda30-3)
1. [ST7735 Display](https://www.banggood.com/Geekcreit-0_96-Inch-7Pin-HD-Color-IPS-Screen-TFT-LCD-Display-SPI-ST7735-Module-p-1370911.html?rmmds=search&cur_warehouse=CN) (or any other screen of your choice)
1. [TTP226 (8  touch buttons)](https://www.banggood.com/TTP226-8-Channel-Digital-Capacitive-Switch-Touch-Sensor-Module-p-1557893.html?rmmds=search&cur_warehouse=CN) or [TTP224 (4 touch buttons)](https://www.banggood.com/TTP224-4CH-Channel-Capacitive-Touch-Switch-Digital-Touch-Sensor-Module-p-1540570.html?rmmds=search&cur_warehouse=CN)
1. Two Arduinos

## Wiring

### Anemometer

- The voltage wire is attached to the wires of a 12V supply.
- The data wire is inserted into the *Pin 12* of the Arduino with the transmitter module.
- The ground wire is inserted into the ground pin of the same Arduino.

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




