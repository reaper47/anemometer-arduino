#include "wifi.h"

SoftwareSerial esp(2, 3);

String apiKey = "2I4YMRTKW8IHEBSK";

char error[] = "Error";


void startWifi()
{
    esp.begin(9600);
    esp.println("AT+RST");
}


void sampleToThinkSpeak()
{
    int val = 501;
    float mv=(val/1023.0)*5000;
    float cel=(mv/10);

    char buf[16];
    String strTemp = dtostrf(cel, 4, 1, buf);
    Serial.println(strTemp);

    // TCP connection
    String cmd = "AT+CIPSTART=\"TCP\",\"";
    cmd += "184.106.153.149"; // api.thingspeak.com
    cmd += "\",80";
    esp.println(cmd);

    if(esp.find(error)) {
        Serial.println("AT+CIPSTART error");
        return;
    }

    // prepare GET string
    String getStr = "GET /update?api_key=";
    getStr += apiKey;
    getStr +="&field1=";
    getStr += String(strTemp);
    getStr += "\r\n\r\n";

    // send data length
    cmd = "AT+CIPSEND=";
    cmd += String(getStr.length());
    esp.println(cmd);

    if(esp.find('>')) {
        esp.print(getStr);
    } else {
        esp.println("AT+CIPCLOSE");
        Serial.println("AT+CIPCLOSE");
    }
    delay(20000);  
}