#include <Arduino.h>
#include <SoftwareSerial.h>
#include <RH_ASK.h>
#include <SPI.h>

#define SERVER_PORT 8091
#define SSID "VIDEOTRON6379"
#define PASS "XY7XY7VCW3UVV"
#define JSON_LENGTH 1024
#define WIFI_COUNTER_MAX 1000

#define PIN_WIND A0
#define WIND_THRESHOLD 1.2

/*
 * WIND
 */
struct wind_t
{
    double currentSpeed;
};

const byte windsize = sizeof(wind_t);
const float amperes = 5.0 / 1023.0;
const float toKmph = 6 * 3.6;
byte txBuffer[windsize] = {0};

wind_t wind;
RH_ASK driver;

/*
 * WIFI
 */
String apiKey = "2I4YMRTKW8IHEBSK";
char error[] = "Error";
SoftwareSerial esp(2, 3);

void readWindSpeed(wind_t *wind);
void sendWindSpeedRadioTX(RH_ASK *driver, wind_t *wind);
void startWifi();
void sampleToThinkSpeak();

void setup()
{
    Serial.begin(9600);
    if (!driver.init())
    {
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

/*
 * WIFI
 */
void startWifi()
{
    esp.begin(9600);
    esp.println("AT+RST");
}

void sampleToThinkSpeak()
{
    int val = 501;
    float mv = (val / 1023.0) * 5000;
    float cel = (mv / 10);

    char buf[16];
    String strTemp = dtostrf(cel, 4, 1, buf);
    Serial.println(strTemp);

    // TCP connection
    String cmd = "AT+CIPSTART=\"TCP\",\"";
    cmd += "184.106.153.149"; // api.thingspeak.com
    cmd += "\",80";
    esp.println(cmd);

    if (esp.find(error))
    {
        Serial.println("AT+CIPSTART error");
        return;
    }

    // prepare GET string
    String getStr = "GET /update?api_key=";
    getStr += apiKey;
    getStr += "&field1=";
    getStr += String(strTemp);
    getStr += "\r\n\r\n";

    // send data length
    cmd = "AT+CIPSEND=";
    cmd += String(getStr.length());
    esp.println(cmd);

    if (esp.find('>'))
    {
        esp.print(getStr);
    }
    else
    {
        esp.println("AT+CIPCLOSE");
        Serial.println("AT+CIPCLOSE");
    }
    delay(20000);
}

/*
 * WIND
 */
void readWindSpeed(wind_t *wind)
{
    double outvoltage = analogRead(PIN_WIND) * amperes;
    double speed = outvoltage * toKmph;

    if (speed <= WIND_THRESHOLD)
    {
        speed = 0.0;
    }

    wind->currentSpeed = speed;
}

void sendWindSpeedRadioTX(RH_ASK *driver, wind_t *wind)
{
    memcpy(txBuffer, &wind, windsize);
    driver->send((uint8_t *)wind, windsize);
    driver->waitPacketSent();
    delay(500);
}
