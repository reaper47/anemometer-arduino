#include "main.h"

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS,  TFT_DC, TFT_RST);

AsyncWebServer server(80);
char json[JSON_LENGTH] = { '\0' };
bool serverUp = true;
int checkConnectionCounter = WIFI_COUNTER_MAX;

wind_t windData = {0};


void setup(void) {
    pinMode(LED_PIN, OUTPUT);
    pinMode(PIN_TOUCH_1, INPUT);
    pinMode(PIN_TOUCH_2, INPUT);

    WiFi.mode(WIFI_STA);
    WiFi.begin(SSID, PASS);
    checkWifiConnection();
    
    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
        memset(json, 0, JSON_LENGTH);
	      snprintf(json, JSON_LENGTH, "{\"wind\":{\"ms\":\"%.2f\",\"kmph\":\"%.2f\",\"mph\":\"%.2f\"}}", 
                 windData.speed/3.6, windData.speed, windData.speed*0.621371);
        request->send(200, "text/plain", json);
    });
    server.onNotFound([](AsyncWebServerRequest *request) { request->send(404, "text/plain", "Not found"); });
    server.begin();

    tft.initR(INITR_BLACKTAB);
    delay(500);
    tft.setTextColor (ST7735_WHITE);
    tft.fillScreen (ST7735_BLACK);
    tft.drawRect (5, 5, 119, 60,ST7735_YELLOW);
    tft.drawRect (5, 70, 119, 84,ST7735_YELLOW);
}


void loop() 
{
    checkWifiConnection();
    readTouchButtons();
    readWind();
    updateScreen();
}


void checkWifiConnection()
{
    if (checkConnectionCounter < WIFI_COUNTER_MAX) {
        checkConnectionCounter++;
        return;
    }

    if (WiFi.waitForConnectResult() != WL_CONNECTED) {
        digitalWrite(LED_PIN, HIGH);
        serverUp = false;
    } else {
        digitalWrite(LED_PIN, LOW);
        serverUp = true;
    }

    checkConnectionCounter = 0;
}


void readTouchButtons()
{
    if (digitalRead(PIN_TOUCH_1)) {
        windData.other  = rand() % 256 + 1;
    }  else if (digitalRead(PIN_TOUCH_2)) {
        windData.min = rand() % 256 + 1;
    }
}


void readWind()
{
  float outvoltage = analogRead(PIN_WIND)*(5.0 / 1023.0);
  windData.speed = 6*outvoltage*3.6;
  if (windData.speed > windData.max) {
      windData.max = windData.speed;  
  }

  if (windData.speed < WIND_THRESHOLD) {
      windData.speed = 0.;
  }
}


void updateScreen()
{
    tft.setCursor(15, 15);
    tft.setTextSize(2);
    tft.setTextColor(ST7735_WHITE, ST7735_BLACK);
    tft.println(windData.speed);
    tft.setCursor(90, 15);
    tft.setTextSize(1);
    tft.println("km/h");

    tft.setTextSize(2);
    tft.setCursor (30, 30);
    tft.println("======");
    tft.setTextSize (1);
    if (serverUp) {
      tft.setCursor (25, 48); 
      tft.println(WiFi.localIP());
    } else {
      tft.setCursor (45, 48);
      tft.println("No WiFi");
    }
    
    tft.setTextSize(1);
    tft.setCursor (15, 80);
    tft.print ("Max: ");
    tft.println(windData.max);

    tft.setCursor(15, 95);
    tft.print("Min: ");
    tft.println(windData.min);

    tft.setCursor(15, 110);
    tft.print("Current: ");
    tft.println(windData.other);

    delay(50);
}
