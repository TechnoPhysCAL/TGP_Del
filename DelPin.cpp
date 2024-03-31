#include "DelPin.h"

#ifdef ESP_PLATFORM
DelPin::DelPin(int address) : Del()
#else
DelPin::DelPin(int address, int pwm_channel) : Del()
#endif
{
  _address = address;
  auto updater = [&](float percentage)
  { changeState(percentage); };
  Del::setSignalUpdater(updater);

#ifdef ESP_PLATFORM
  static int objectCount = FIRST_CHANNEL;
  if (objectCount < PWM_MAX_CHANNEL)
  {
    if (channel >= 0)
    {
      _channel = pwm_channel;
    }
    else
    {
      _channel = objectCount;
      objectCount++;
      objectCount++;
    }
  }

#endif
}

void DelPin::begin()
{
#ifdef ESP_PLATFORM

  if (DelPin::getChannel() >= 0)
  {
    ledcSetup(DelPin::getChannel(), PWM_FREQUENCY, PWM_RESOLUTION);
    ledcAttachPin(DelPin::getAdress(), DelPin::getChannel());
    DelPin::changeState(DelPin::getBrightness()); // duty Cycle de 0
  }
#else
  pinMode(DelPin::getAddress(), OUTPUT);
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

void DelPin::changeState(float percentage)
{
#ifdef ESP_PLATFORM

  if (DelPin::getChannel() >= 0)
  {
    ledcWrite(DelPin::getChannel(), percentage > 0 ? (int)(percentage * PWM_MAXIMUM_FACTOR) : 0.0);
  }

#else
  analogWrite(DelPin::getAddress(), percentage > 0 ? (percentage * 2.55) : 0.0);

#endif
}
