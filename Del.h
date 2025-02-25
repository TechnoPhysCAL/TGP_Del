#ifndef Del_h
#define Del_h

#define DEFAULT_BLINKING_INTERVAL 200
#define DEFAULT_BRIGHTNESS 100.0
#include "Arduino.h"

//#ifndef __AVR__
//typedef std::function<void(float)> SignalUpdater;
//#else
typedef void (*SignalUpdater)(float);
//#endif
/******************************************************************************
* Definitions
******************************************************************************/
class Del
{
public:
    Del();
    Del(SignalUpdater updater);

    void setSignalUpdater(SignalUpdater updater);
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

protected:
    virtual void doUpdate(float value);

private:
    unsigned long _blinkInterval;
    bool _value;
    bool _blinking;
    float _brightness;
    SignalUpdater _updater;
};
#endif

