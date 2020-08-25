#include "DELPin.h"

DELPin::DELPin(int address) : DEL()
{
  _address = address;
  pinMode(_address, OUTPUT);
}

void DELPin::changeState(bool state)
{
  digitalWrite(_address, state ? HIGH : LOW);
}
