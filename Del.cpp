#include "Del.h"

Del::Del()
{
  _value = false;

  _blinking = false;
  _blinkInterval = DEFAULT_BLINKING_INTERVAL;
  _brightness = DEFAULT_BRIGHTNESS;
}

void Del::on()
{
  Del::set(true);
}
void Del::off()
{
  Del::set(false);
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

void Del::setBrightness(float value)
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

float Del::getBrightness()
{
  return _brightness;
}

void Del::setBlinkingInterval(unsigned long interval)
{
  _blinkInterval = interval == 0 ? 1 : interval;
}
unsigned long Del::getBlinkingInterval()
{
  return _blinkInterval;
}

void Del::refresh(std::function<void(bool,float)> updater)
{
  if (_value)
  {
    if (_blinking)
    {
      updater(((millis() % (_blinkInterval * 2)) > _blinkInterval), _brightness);
    }
    else
    {
      updater(true, _brightness);
    }
  }
  else
  {
    updater(false, _brightness);
  }
}
