#ifndef Del_h
#define Del_h

#define DEFAULT_BLINKING_INTERVAL 200
#define DEFAULT_BRIGHTNESS 100.0
#include "Arduino.h"

typedef std::function<void(float)> SignalUpdater;
/******************************************************************************
* Definitions
******************************************************************************/
class Del
{
public:
    Del();

    void setSignalUpdater(SignalUpdater func);
    void refresh();

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


private:
    unsigned long _blinkInterval;
    bool _value;
    bool _blinking;
    float _brightness;
    SignalUpdater _updater;
};
#endif
