#ifndef DELPin_h
#define DELPin_h

#include "DEL.h"

/******************************************************************************
* Definitions
******************************************************************************/
class DELPin : public DEL
{
public:
    DELPin(int address);

protected:
    void changeState(bool);
private:
    int _address;
};
#endif
