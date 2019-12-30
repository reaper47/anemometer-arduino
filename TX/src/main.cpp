#include <Arduino.h>
#include <VirtualWire.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>

#define PIN_TOUCH_1 6
#define PIN_TOUCH_2 7
#define PIN_RF_TX   12
#define TFT_CS  10
#define TFT_DC  9
#define TFT_RST -1 // Or set to -1 and connect to Arduino RESET pin
#define WIND_LENGTH 4
#define PIN_WIND A0

void tx();
void readWind();
void updateScreen();
void readTouchButtons();

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS,  TFT_DC, -1);

float currentSpeed = 77.52;
uint16_t minSpeed = 0;
float windSpeed = 0.0;
float windSpeedMax = 0.0;

struct data_t { float windSpeed; };
data_t data;
 

void setup(void) {
    pinMode(PIN_TOUCH_1, INPUT);
    pinMode(PIN_TOUCH_2, INPUT);

    vw_set_tx_pin(PIN_RF_TX);
    vw_set_ptt_inverted(true);
    vw_setup(2000);

    tft.initR(INITR_BLACKTAB);
    delay(500);

    tft.setTextColor (ST7735_WHITE);
    tft.fillScreen (ST7735_BLACK);
    tft.drawRect (5, 5, 119, 60,ST7735_YELLOW);
    tft.drawRect (5, 70,119, 84,ST7735_YELLOW);
}
 
void loop() {
    tx();
    readTouchButtons();
    readWind();
    updateScreen();
}
  

void readTouchButtons()
{
    if (digitalRead(PIN_TOUCH_1)) {
        currentSpeed = rand() % 256 + 1;
    }  else if (digitalRead(PIN_TOUCH_2)) {
        minSpeed = rand() % 256 + 1;
    } 
}


void tx()
{
    data.windSpeed = lround(windSpeed*100);
    vw_send((uint8_t *)&data, sizeof(data));
    vw_wait_tx();
}


void readWind()
{
  float outvoltage = analogRead(PIN_WIND)*(5.0 / 1023.0);
  windSpeed = 6*outvoltage*3.6;
  if (windSpeed > windSpeedMax) {
    windSpeedMax = windSpeed;  
  }

  if (windSpeed < 0.5) {
    windSpeed = 0.;
  }
}


void updateScreen()
{
    tft.setCursor(15, 15);
    tft.setTextSize(2);
    tft.setTextColor(ST7735_WHITE, ST7735_BLACK);
    tft.println(windSpeed);
    tft.setCursor(90, 15);
    tft.setTextSize(1);
    tft.println("km/h");

    tft.setTextSize(2);
    tft.setCursor (30, 30);
    tft.println("======");
    tft.setTextSize (1);
    tft.setCursor (22, 48);
    tft.println("Super Wind 3030");
    
    tft.setTextSize(1);
    tft.setCursor (15, 80);
    tft.print ("Max: ");
    tft.println(windSpeedMax);

    tft.setCursor(15, 95);
    tft.print("Min: ");
    tft.println(minSpeed);

    tft.setCursor(15, 110);
    tft.print("Current: ");
    tft.println(currentSpeed);

    delay(50);
}
