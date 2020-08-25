#include "Del.h"

Del::Del()
{
  _value = false;
  _blinkInterval = 250;
  _blinking = false;
}

void Del::set(bool value)
{
  _value = value;
}
bool Del::get()
{
  return _value;
}
void Del::setBlinking(bool state)
{
  _blinking = state;
}
bool Del::getBlinking()
{
  return _blinking;
}

void Del::setBlinkingInterval(unsigned long interval)
{
  _blinkInterval = interval == 0 ? 1 : interval;
}
unsigned long Del::getBlinkingInterval()
{
  return _blinkInterval;
}

void Del::refresh()
{
  if (_value)
  {
    if (_blinking)
    {
      changeState(((millis() % (_blinkInterval * 2)) > _blinkInterval));
    }
    else
    {
      changeState(true);
    }
  }
  else
  {
    changeState(false);
  }
}
