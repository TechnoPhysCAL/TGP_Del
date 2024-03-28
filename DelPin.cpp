#include "DelPin.h"

DelPin::DelPin(int address) : Del()
{
  _address = address;
}

void DelPin::begin()
{
#ifdef ESP_PLATFORM
  static int objectCount = FIRST_CHANNEL;
  if (objectCount < PWM_MAX_CHANNEL)
  {
    _channel = objectCount;
    objectCount++;
    objectCount++;
    ledcSetup(getChannel(), PWM_FREQUENCY, PWM_RESOLUTION);
    ledcAttachPin(_address, getChannel());
    ledcWrite(getChannel(), (int)(getBrightness() * PWM_MAXIMUM_FACTOR)); // duty Cycle de 0
  }
  else
  {
    _channel = -1;
  }
#else
  pinMode(_address, OUTPUT);
#endif
}

int DelPin::getAddress()
{
  return _address;
}

#ifdef ESP_PLATFORM
int DelPin::getChannel()
{
  return _channel;
}
#endif

void DelPin::refresh()
{
  auto updater = [&](bool state, float brightness)
  { changeState(state, brightness); };
  Del::refresh(updater);
}

void DelPin::changeState(bool state, float brightness)
{
#ifdef ESP_PLATFORM

  if (getChannel() >= 0)
  {
    ledcWrite(getChannel(), state ? (int)(getBrightness() * PWM_MAXIMUM_FACTOR) : 0.0);
  }

#else
  analogWrite(_address, state ? (brightness * 2.55) : 0.0);

#endif
}
