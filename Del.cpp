#include "DEL.h"

DEL::DEL()
{
  _value = false;

  _blinking = false;
  _blinkInterval = DEFAULT_BLINKING_INTERVAL;
  _brightness = DEFAULT_BRIGHTNESS;
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

void DEL::setBrightness(float value)
{
  if (value < 0.0)
  {
    _brightness = 0.0;
  }
  else if (value > 100.0)
  {
    _brightness = 100.0;
  }
  else
  {
    _brightness = value;
  }
}

float DEL::getBrightness()
{
  return _brightness;
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
      changeState(((millis() % (_blinkInterval * 2)) > _blinkInterval), _brightness);
    }
    else
    {
      changeState(true, _brightness);
    }
  }
  else
  {
    changeState(false, _brightness);
  }
}
