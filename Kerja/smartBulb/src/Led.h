#ifndef _LED_H_
#define _LED_H_
#include <BluetoothSerial.h>

class Led {
    long last_millis = 0, current_millis;
    bool led_cond = true;
    int _led_indicator;
  public:
    void begin(int led_indicator) {
      _led_indicator = led_indicator;
      pinMode(_led_indicator, OUTPUT);
    }
    void ConnectionOut(int interval) {
        current_millis = millis();
        if ((current_millis - last_millis) >= interval) {
          last_millis = millis();
          digitalWrite(_led_indicator, true);
          Serial.println("CONNECTION TIMEOUT");
        }
    }
    void blinking(int interval) {
      current_millis = millis();
      if ((current_millis - last_millis) >= interval) {
        last_millis = millis();
        digitalWrite(_led_indicator, led_cond);
        led_cond = !led_cond;
      }
    }
};
#endif
