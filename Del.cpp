#include "Del.h"

Del::Del(int address) : DelBase()
{
  _address = address;
  pinMode(_address, OUTPUT);

#ifdef ESP_PLATFORM
  static int objectCount = 0;
  if (objectCount < PWM_MAX_CHANNEL)
  {
    _channel = objectCount;
    objectCount++;
    ledcSetup(_channel, PWM_FREQUENCY, PWM_RESOLUTION);
    ledcAttachPin(_address, _channel);
    ledcWrite(_channel, (int)(getBrightness() * PWM_MAXIMUM_FACTOR)); //duty Cycle de 0
  }
  else
  {
    _channel = -1;
  }

#endif
}

int Del::getAddress()
{
  return _address;
}

#ifdef ESP_PLATFORM
int Del::getChannel()
{
  return _channel;
}
#endif

void Del::changeState(bool state, float brightness)
{

#ifdef ESP_PLATFORM

  if (_channel >= 0)
  {
    ledcWrite(_channel, state ? (int)(getBrightness() * PWM_MAXIMUM_FACTOR) : 0.0);
  }
  

#else
  analogWrite(_address, state ? (brightness * 2.55) : 0.0);

#endif
}
