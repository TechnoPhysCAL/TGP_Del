#ifndef Del_h
#define Del_h

#include "Arduino.h"

/******************************************************************************
* Definitions
******************************************************************************/
class Del
{
public:
    Del();

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
