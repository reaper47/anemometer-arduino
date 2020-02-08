#include "main.h"

RH_ASK driver(2000, 2, 4, 5);


void setup()
{
    Serial.begin(9600);
    if (!driver.init()) {
        Serial.println("init failed");
    }
    initScreen();
}


void loop()
{
    wind_t wind = receiveWindSpeed(&driver);
    updateScreen(&wind);
    delay(500);
}
