#include "DEL.h"

DEL::DEL()
{
  _value = false;
  
  _blinking = false;
  _blinkInterval = DEFAULT_BLINKING_INTERVAL;
  
}

void DEL::set(bool value)
{
  _value = value;
}
bool DEL::get()
{
  return _value;
}
void DEL::setBlinking(bool state)
{
  _blinking = state;
}
bool DEL::getBlinking()
{
  return _blinking;
}

void DEL::setBlinkingInterval(unsigned long interval)
{
  _blinkInterval = interval == 0 ? 1 : interval;
}
unsigned long DEL::getBlinkingInterval()
{
  return _blinkInterval;
}

void DEL::refresh()
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
