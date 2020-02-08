#ifndef __DISPLAY_H
#define __DISPLAY_H

#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include "types.h"

/*
 * LED to  3.3V
 * SCK to  D13
 * SDA to  D11
 * A0  to  D8
 * RST to  D9
 * CS  to  D10
 * GND to  GND
 * VCC to  5.0V
 */
#define TFT_CS   10
#define TFT_RST  9
#define TFT_DC   8

void initScreen();
void updateScreen(wind_t *wind);

#endif /* __DISPLAY_H */
