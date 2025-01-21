#ifndef DelPin_h
#define DelPin_h

#include "Del.h"
#include "Arduino.h"


#ifdef ESP_PLATFORM 
#define PWM_FREQUENCY 5000 // Fréquence du PWM
#define PWM_RESOLUTION 8   // Résolution 8 bits; duty cycle de 0 à 255
#define PWM_MAXIMUM_FACTOR 2.55

    #if ESP_ARDUINO_VERSION_MAJOR <3
    #define PATCH_OLD_ESP32
    #define FIRST_CHANNEL 0
    #define PWM_MAX_CHANNEL 16
    
    #endif
#endif

/******************************************************************************
 * Definitions
 ******************************************************************************/
class DelPin : public Del
{
public:
#ifdef PATCH_OLD_ESP32
    DelPin(int pinNumber,int channel=-1);
    int getChannel();
#else
    DelPin(int pinNumber);
#endif
    void begin();
    int getPinNumber();

private:
    void doUpdate(float) override;
    int _pinNumber;
    #ifdef PATCH_OLD_ESP32
    int _channel;
    #endif

};
#endif
