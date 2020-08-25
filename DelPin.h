#ifndef DelPin_h
#define DelPin_h

#include "Del.h"

/******************************************************************************
* Definitions
******************************************************************************/
class DelPin : public Del
{
public:
    DelPin(int address);

protected:
    void changeState(bool);
private:
    int _address;
};
#endif
