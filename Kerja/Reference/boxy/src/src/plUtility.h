#ifndef PLUGIN__UTILITY_H
#define PLUGIN__UTILITY_H

#include "plDatatypes.h"
#include <Arduino.h>

constexpr uint32_t hash(const char *s, uint32_t off = 0)
{
  return !s[off] ? 5381 : (hash(s, off + 1) * 33) ^ s[off];
}

String explodeString(String data, String delimiter, byte index);

class Macadd
{
private:
  String addr;
  String deli;
  char *res;

public:
  Macadd(String address, String delimiter);
  void inputMacAddress(String Macaddress);
  char *getTopic();
};
#endif