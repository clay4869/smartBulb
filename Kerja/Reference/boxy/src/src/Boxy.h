#ifndef _BOXY_H
#define _BOXY_H

#include "plDatatypes.h"
#include "TCALL.h"
#include "KRS98.h"
#include <Keypad.h>

typedef enum
{
  LOCKER_PASSWORD_SETTING = 0,
  APN_SETTING = 64,
  GPRS_USER_SETTING = 128,
  GPRS_PASS_SETTING = 192,
  SIN_PIN_SETTING = 256,
  MQTT_BROKER_SETTING = 320,
  MQTT_USERNAME_SETTING = 384,
  MQTT_PASSWORD_SETTING = 448
} BSETTING;

class Boxy
{
protected:
  uint8_t hexaKeys[4][4] = {
      {'1', '2', '3', 'A'},
      {'4', '5', '6', 'B'},
      {'7', '8', '9', 'C'},
      {'*', '0', '#', 'D'}}; // keys in keypad

  uint8_t rowPins[4] = {22, 21, 19, 18};
  uint8_t colPins[4] = {13, 35, 15, 2};
  byte mac[6];

public:
  String readSetting(BSETTING type);
  bool writeSetting(BSETTING type, uint8_t *data);
  char getKey(void);
  void changeSetting(String message);
  // Boxy(void);
  //string test;
  uint8_t locker_password[4];
  uint8_t configuration_mode = 0;
  uint8_t broker[20];
  TCALL ttgo = TCALL();
  KRS98 locker = KRS98();
  Keypad keypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, sizeof(rowPins), sizeof(colPins));
};
#endif
