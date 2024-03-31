#ifndef DelPin_h
#define DelPin_h

#include "Del.h"
#include "Arduino.h"

#ifdef ESP_PLATFORM

#define FIRST_CHANNEL 0

#define PWM_MAX_CHANNEL 16
#define PWM_FREQUENCY 5000 // Fréquence du PWM
#define PWM_RESOLUTION 8   // Résolution 8 bits; duty cycle de 0 à 255
#define PWM_MAXIMUM_FACTOR 2.55

#endif

/******************************************************************************
 * Definitions
 ******************************************************************************/
class DelPin : public Del
{
public:
#ifdef ESP_PLATFORM
    DelPin(int address, int pwm_channel = -1);
#else
    DelPin(int address);
#endif
    void begin();
    int getAddress();

#ifdef ESP_PLATFORM
    int getChannel();
#endif

private:
    void changeState(float);
    int _address;
#ifdef ESP_PLATFORM
    int _channel;
#endif
};
#endif
