#include "Del.h"

Del::Del(int address)
{
  _address = address;
  pinMode(_address, OUTPUT);
}
void Del::set(bool value)
{
  digitalWrite(_address, value?HIGH:LOW);
}
