#include "wind.h"

wind_t wind = {0};


wind_t receiveWindSpeed(RH_ASK *driver)
{
    uint8_t buf[RH_ASK_MAX_MESSAGE_LEN];
    uint8_t buflen = sizeof(buf);

    if (driver->recv(buf, &buflen)) {
        memcpy(&wind, buf, sizeof(wind));
        Serial.print("Wind Speed: ");
        Serial.println(wind.currentSpeed);
    }

    return wind;
}
