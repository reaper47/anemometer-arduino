#ifndef __WIFI_H
#define __WIFI_H

#include <Arduino.h>
#include <SoftwareSerial.h>

#define SERVER_PORT 8091
#define SSID        "VIDEOTRON6379"
#define PASS        "XY7XY7VCW3UVV"

#define JSON_LENGTH      1024
#define WIFI_COUNTER_MAX 1000

void startWifi();
void sampleToThinkSpeak();

#endif /* __WIFI_H */
