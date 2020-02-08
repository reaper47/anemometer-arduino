#include "main.h"

wind_t wind;
RH_ASK driver;


void setup()
{
    Serial.begin(9600); 
    if (!driver.init()) {
         Serial.println("init failed");
    }
    startWifi();
}


void loop()
{
    readWindSpeed(&wind);
    sendWindSpeedRadioTX(&driver, &wind);
    //sampleToThinkSpeak();
}
