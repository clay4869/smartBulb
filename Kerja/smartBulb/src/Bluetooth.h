#ifndef _BLUETOOTH_H_
#define _BLUETOOTH_H_

#include<BluetoothSerial.h>
#include"Eeprom.h"
#include"Wifi.h"

class Bluetooth {
    BluetoothSerial SerialBT;
    enum State {
      gantissid,
      restartwifi
    };
    byte command_post;
    String str;
    char data;
  public:
    void begin() {
      SerialBT.begin ("SmartBulb_BT");
    }
    void inputData() {
      while (SerialBT.available()) {
        delay(2);
        data = SerialBT.read();
        str += data;
      }
      if (str.length() > 0) {
        command_post          = str.indexOf("//");
        String command        = str.substring(0, command_post);
        String command_data   = str.substring(command_post + 2, str.length());
        command.toLowerCase();
        int state = command.toInt();
        Serial.print("Command = ");
        Serial.println(command);
        
        if (command == "gantissid") {
          _gantissid(command_data);
        }
        if (command == "reconnect") {
          _restartwifi(); (command_data);
        }
        else {
          Serial.println("Perintah Salah!!!");
        }
        str = "";
      }
    }

  private:
    Eeprom eeprom;
    Wifi wifi;
    void _gantissid(String data) {
      String ssid               = data.substring(0, str.length());
      eeprom.changeWifi(ssid, pswd);
      wifi.reconnect();
    }
    void _gantipswd(String data){
      String pswd              = data.substring(0, str.length());
    }
    void _restartwifi() {
      wifi.reconnect();
    }
    
};
#endif //_BLUETOOTH_H
