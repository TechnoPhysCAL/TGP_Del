#ifndef DELPin_h
#define DELPin_h

#include "DEL.h"
#include "Arduino.h"

#ifdef ESP_PLATFORM

#define PWM_MAX_CHANNEL 16
#define PWM_FREQUENCY 5000 //Fréquence du PWM
#define PWM_RESOLUTION 8   //Résolution 8 bits; duty cycle de 0 à 255
#define PWM_MAXIMUM_FACTOR 2.55

#endif

/******************************************************************************
* Definitions
******************************************************************************/
class DELPin : public DEL
{
public:
    DELPin(int address);

protected:
    void changeState(bool,float);
  

private:
    int _address;
#ifdef ESP_PLATFORM
    int _channel;
#endif
};
#endif
