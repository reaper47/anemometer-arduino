#ifndef __MAIN_H
#define __MAIN_H

#include <Arduino.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <string.h>

#define PIN_TOUCH_1 D3
#define PIN_TOUCH_2 D4

#define TFT_CS      D1
#define TFT_RST     D0 
#define TFT_DC      D2

#define LED_PIN     D8
#define PIN_WIND    A0
#define WIND_LENGTH 4
#define WIND_THRESHOLD 1.3

#define SERVER_PORT 8091
#define JSON_LENGTH 1024
#define WIFI_COUNTER_MAX 1000

#define SSID "VIDEOTRON6379"
#define PASS "XY7XY7VCW3UVV"

typedef struct { 
  float speed;
  float other;
  float min;
  float max;
} wind_t;

void readWind();
void readTouchButtons();
void updateScreen();
void checkWifiConnection();

#endif /* __MAIN_H */