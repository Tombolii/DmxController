#ifndef BaseController_h
#define BaseController_h

class BaseController
{
public:
    BaseController(int startAddress);

protected:
    bool validateValue(int value);
    int address;
};

#endif