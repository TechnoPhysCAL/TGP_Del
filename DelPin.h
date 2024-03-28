#ifndef DelPin_h
#define DelPin_h

#include "Del.h"
#include "Arduino.h"

#ifdef ESP_PLATFORM

#define FIRST_CHANNEL 0

#define PWM_MAX_CHANNEL 16
#define PWM_FREQUENCY 5000 //Fréquence du PWM
#define PWM_RESOLUTION 8   //Résolution 8 bits; duty cycle de 0 à 255
#define PWM_MAXIMUM_FACTOR 2.55

#endif

/******************************************************************************
* Definitions
******************************************************************************/
class DelPin : public Del
{
public:
    DelPin(int address);
    void begin();
    int getAddress();
    void refresh();

#ifdef ESP_PLATFORM
    int getChannel();
#endif

private:
void changeState(bool, float);
    int _address;
#ifdef ESP_PLATFORM
    int _channel;
#endif
};
#endif
