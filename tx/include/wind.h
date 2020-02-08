#ifndef __WIND_H
#define __WIND_H

#include <RH_ASK.h>
#include <SPI.h>

#define PIN_WIND       A0
#define WIND_THRESHOLD 1.2

struct wind_t {
    double currentSpeed;
};

const byte windsize = sizeof(wind_t);
const float amperes = 5.0/1023.0;
const float toKmph = 6*3.6;

void readWindSpeed(wind_t *wind);
void sendWindSpeedRadioTX(RH_ASK *driver, wind_t *wind);

#endif /* __WIND_H */
