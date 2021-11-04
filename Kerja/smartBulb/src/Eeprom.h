#ifndef _EEPROM_H_
#define _EEPROM_H_

#include<EEPROM.h>

#define MAX_LENGTH 20

unsigned int addr = 0;

struct {
  char mySSID[MAX_LENGTH] = "";
  char myPSWD[MAX_LENGTH] = "";
} settings;
struct {
  char mySSID[MAX_LENGTH] = "wifi tes";
  char myPSWD[MAX_LENGTH] = "wifites";
} defaultWifi;


class Eeprom {
  public:
    void checkWifi() {
      EEPROM.begin(sizeof(settings));
      Serial.println("Reading old data from EEPROM:");
      EEPROM.get(addr, settings);
      Serial.println("mySSID: " + String(settings.mySSID) + "\n\myPSWD: " + String(settings.myPSWD));
    }
    void changeWifi(String input_ssid, String input_pswd) {
       input_ssid.toCharArray(settings.mySSID,MAX_LENGTH);
       input_pswd.toCharArray(settings.myPSWD,MAX_LENGTH);       
      addr = 0;
      EEPROM.put(addr, settings);
      EEPROM.commit();    
      addr = 0;           //first addr
      for (int i = 0; i < MAX_LENGTH; ++i) {
        EEPROM.write(addr + i, settings.mySSID[i]);
      }  
      addr += MAX_LENGTH; //next addr
      for (int i = 0; i < MAX_LENGTH; ++i) {
        EEPROM.write(addr + i, settings.myPSWD[i]);
      }
      EEPROM.commit();
      EEPROM.get(addr, settings);
      Serial.println("\n\nNew mySSID: " + String(settings.mySSID) + "\n\New myPSWD: " + String(settings.myPSWD));
      Serial.println("-----------Update EEPROM Succes-------------");
    }
    void read() {
      EEPROM.get(addr, settings);
      Serial.println("mySSID: " + String(settings.mySSID) + "\n\myPSWD: " + String(settings.myPSWD));
    }
    void clear() {
      addr = 0;
      for (int i = 0; i < MAX_LENGTH; ++i) {
        EEPROM.write(addr + i, NULL);
      }
      addr += MAX_LENGTH;
      for (int i = 0; i < MAX_LENGTH; ++i) {
        EEPROM.write(addr + i, NULL);
      }
      EEPROM.commit();
      EEPROM.get(addr, settings);
      Serial.println("\nERASE DATA FROM EEPROM\n");
    }
};

#endif
