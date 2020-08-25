#include "DelPin.h"

DelPin::DelPin(int address) : Del()
{
  _address = address;
  pinMode(_address, OUTPUT);
}

void DelPin::changeState(bool state)
{
  digitalWrite(_address, state ? HIGH : LOW);
}
