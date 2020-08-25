#ifndef DEL_h
#define DEL_h

#define DEFAULT_BLINKING_INTERVAL 250

#include "Arduino.h"

/******************************************************************************
* Definitions
******************************************************************************/
class DEL
{
public:
    DEL();

    void set(bool value);
    bool get();

    void setBlinking(bool state);
    bool getBlinking();

    void setBlinkingInterval(unsigned long interval);
    unsigned long getBlinkingInterval();

    void refresh();

protected:
    virtual void changeState(bool value){};

private:
    unsigned long _blinkInterval;
    bool _value;
    bool _blinking;
};
#endif
