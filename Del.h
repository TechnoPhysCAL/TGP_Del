#ifndef Del_h
#define Del_h

#define DEFAULT_BLINKING_INTERVAL 250
#define DEFAULT_BRIGHTNESS 100.0
#include "Arduino.h"

/******************************************************************************
* Definitions
******************************************************************************/
class Del
{
public:
    Del();

    void on();
    void off();
    
    void set(bool);
    bool get();

    void setBlinking(bool);
    bool getBlinking();

    void setBrightness(float);
    float getBrightness();

    void setBlinkingInterval(unsigned long);
    unsigned long getBlinkingInterval();

    void refresh(std::function<void(bool,float)> updater);

private:
    unsigned long _blinkInterval;
    bool _value;
    bool _blinking;
    float _brightness;
};
#endif
