#include "display.h"

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS,  TFT_DC, TFT_RST);


void initScreen()
{
    tft.initR(INITR_BLACKTAB);
    delay(500);
    tft.setTextColor(ST7735_WHITE);
    tft.fillScreen(ST7735_BLACK);
    tft.drawRect(5, 5, 119, 60, ST7735_YELLOW);
    tft.drawRect(5, 70, 119, 84, ST7735_YELLOW);
}

void updateScreen(wind_t *wind)
{
    tft.setCursor(15, 15);
    tft.setTextSize(2);
    tft.setTextColor(ST7735_WHITE, ST7735_BLACK);
    tft.println(wind->currentSpeed);
    tft.setCursor(90, 15);
    tft.setTextSize(1);
    tft.println("km/h");

    tft.setTextSize(2);
    tft.setCursor (30, 30);
    tft.println("======");
    tft.setTextSize (1);
    tft.setCursor (20, 48);
    tft.println("Super Wind 3000");

    tft.setTextSize(1);
    tft.setCursor (15, 80);
    tft.print ("Max: ");
    tft.println(0);

    tft.setCursor(15, 95);
    tft.print("Min: ");
    tft.println(0);

    tft.setCursor(15, 110);
    tft.print("Current: ");
    tft.println(0);

    delay(50);
}
