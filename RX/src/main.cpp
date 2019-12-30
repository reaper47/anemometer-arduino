#include <Arduino.h>
#include <VirtualWire.h>

struct data_t { float windSpeed; };
data_t data;


void setup() {
    Serial.begin(9600);
    Serial.println("RX Setup");

    vw_set_rx_pin(12);
    vw_set_ptt_inverted(true);
    vw_setup(2000);
    vw_rx_start();
}

void loop() {
    uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN;

    if (vw_get_message(buf, &buflen)) {
        if (buflen == sizeof(data_t)) {
            memcpy(&data, buf, sizeof(data));
            Serial.print("Wind Speed: ");
            Serial.println(data.windSpeed/100);
        }
    }
}