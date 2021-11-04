#include "src/Eeprom.h"
#include "src/Wifi.h"
#include "src/Bluetooth.h"
#include "srcLed.h"

#define led_builtin 2

Eeprom eeprom;
Wifi wifi;
Bluetooth bluetooth;
Led led;

void setup() {
  Serial.begin(115200);
  bluetooth.begin();
  led.begin(led_builtin);
  Serial.println("\n\Smart Bulb");
  eeprom.checkWifi();
  wifi.start();
}

void loop() {
  if (WiFi.status() != WL_CONNECTED) {
    led.ConnectionOut(3000);
  }
  if (WiFi.status() == WL_CONNECTED) {
    led.blinking(1000);
  }
  bluetooth.inputData();
}
