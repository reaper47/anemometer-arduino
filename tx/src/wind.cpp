#include "wind.h"

byte txBuffer[windsize] = {0};


void readWindSpeed(wind_t *wind)
{
    double outvoltage = analogRead(PIN_WIND)*amperes;
    double speed = outvoltage*toKmph;

    if (speed <= WIND_THRESHOLD) {
        speed = 0.0;
    }

    wind->currentSpeed = speed;
}


void sendWindSpeedRadioTX(RH_ASK *driver, wind_t *wind)
{
    memcpy(txBuffer, &wind, windsize);
    driver->send((uint8_t*)wind, windsize);
    driver->waitPacketSent();
    delay(500);
}
