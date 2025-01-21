#include "DelPin.h"

#ifdef PATCH_OLD_ESP32
DelPin::DelPin(int pinNumber,int channel) : Del()
#else
DelPin::DelPin(int pinNumber) : Del()
#endif
{
  _pinNumber = pinNumber;

  #ifdef PATCH_OLD_ESP32
  static int objectCount = FIRST_CHANNEL;
  if (objectCount < PWM_MAX_CHANNEL)
  {
    if (channel >= 0)
    {
      _channel = channel;
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
#if defined(PATCH_OLD_ESP32) 
  ledcSetup(DelPin::getChannel(), PWM_FREQUENCY, PWM_RESOLUTION);
  ledcAttachPin(DelPin::getPinNumber(), DelPin::getChannel());
#elif defined(ESP_PLATFORM)
  ledcAttach(DelPin::getPinNumber(), PWM_FREQUENCY, PWM_RESOLUTION);
#else
  pinMode(DelPin::getPinNumber(), OUTPUT);
#endif
  DelPin::doUpdate(DelPin::getBrightness());
}

int DelPin::getPinNumber()
{
  return _pinNumber;
}

void DelPin::doUpdate(float percentage)
{
#if defined(PATCH_OLD_ESP32)
  ledcWrite(DelPin::getChannel(), percentage > 0 ? (int)(percentage * PWM_MAXIMUM_FACTOR) : 0.0);
#elif defined(ESP_PLATFORM)
  ledcWrite(DelPin::getPinNumber(), percentage > 0 ? (int)(percentage * PWM_MAXIMUM_FACTOR) : 0.0);
#else
  analogWrite(DelPin::getPinNumber(), percentage > 0 ? (percentage * 2.55) : 0.0);
#endif
}

#ifdef PATCH_OLD_ESP32
int DelPin::getChannel(){
  return DelPin::_channel;
}
#endif