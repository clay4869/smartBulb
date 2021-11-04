#ifndef _WIFI_H_
#define _WIFI_H_

#include "Eeprom.h"
#include "Led.h"
#include <WiFi.h>

Led indicator;

class Wifi {
#define CONNECTION_TIMEOUT 10
  public:
    void start() {
      if (String (settings.mySSID) == NULL && String (settings.myPSWD) == NULL) {
        WiFi.mode(WIFI_STA);
        WiFi.begin(defaultWifi.mySSID, defaultWifi.myPSWD);
        Serial.println("\nConnecting to " + String(defaultWifi.mySSID));
        int timeout_counter = 0;
        while (WiFi.status() != WL_CONNECTED) {
          Serial.print(".");
          delay(200);
          timeout_counter++;
          if (timeout_counter >= CONNECTION_TIMEOUT * 5) {
            break;
          }
        }
        Serial.println("\nConnected to the Default WiFi network");
        Serial.print("Local ESP32 IP: ");
        Serial.println(WiFi.localIP());
      }
      else {
        WiFi.disconnect();
        WiFi.mode(WIFI_STA);
        WiFi.disconnect();
        WiFi.begin(settings.mySSID, settings.myPSWD);
        Serial.println("\nConnecting to " + String(settings.mySSID));
        int timeout_counter = 0;
        while (WiFi.status() != WL_CONNECTED) {
          Serial.print(".");
          delay(1000);
          timeout_counter++;
          if (timeout_counter >= CONNECTION_TIMEOUT / 2) {
           break;
          }
        }
        Serial.println("\nConnected to the EEPROM WiFi network");
        Serial.print("Local ESP32 IP: ");
        Serial.println(WiFi.localIP());
      }
    }
    void reconnect() {
      Serial.print("Reconnecting");
      WiFi.disconnect();
      start();
    }
};
#endif
