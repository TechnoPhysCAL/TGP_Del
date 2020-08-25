#ifndef Del_h
#define Del_h

#include "Arduino.h"

/******************************************************************************
* Definitions
******************************************************************************/
class Del
{
public:
    Del(int address);
    void set(bool value);
private:
 int _address;
};
#endif
