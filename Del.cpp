#include "Del.h"

Del::Del(SignalUpdater updater):Del()
{
  _updater = updater;
}

Del::Del()
{
  _value = false;

  _blinking = false;
  _blinkInterval = DEFAULT_BLINKING_INTERVAL;
  _brightness = DEFAULT_BRIGHTNESS;
  _updater = nullptr;
}

void Del::setSignalUpdater(SignalUpdater func)
{
  _updater = func;
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

void Del::refresh()
{
  if (_value)
  {
    if (_blinking)
    {
      doUpdate(((millis() % (_blinkInterval * 2)) > _blinkInterval) ? _brightness : 0.0);
    }
    else
    {
      doUpdate(_brightness);
    }
  }
  else
  {
    doUpdate(0.0);
  }
}

void Del::doUpdate(float value)
{
  if(_updater != nullptr){
    _updater(value);
  }

}