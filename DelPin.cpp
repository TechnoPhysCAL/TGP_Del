#include "DELPin.h"

DELPin::DELPin(int address) : DEL()
{
  _address = address;
  pinMode(_address, OUTPUT);

#ifdef ESP_PLATFORM
  static int objectCount =0;
  if (objectCount < PWM_MAX_CHANNEL)
  {
    _channel = objectCount;
    objectCount++;
    ledcSetup(_address, PWM_FREQUENCY, PWM_RESOLUTION);
    ledcAttachPin(_address, _channel);
    ledcWrite(_channel, (int)(getBrightness() * PWM_MAXIMUM_FACTOR)); //duty Cycle de 0
  }
  else
  {
    _channel = -1;
  }

#endif
}

#ifdef ESP_PLATFORM
void DELPin::changeState(bool state, float brightness)
{
  digitalWrite(_address, state ? HIGH : LOW);
  if (_channel >= 0)
  {
    ledcWrite(_channel, (int)(brightness * PWM_MAXIMUM_FACTOR));
  }
}
#else
void DELPin::changeState(bool state, float brightness)
{
  analogWrite(_address, state ? (brightness * 2.55) : 0.0);
}

#endif