#ifndef DmxAdapter_h
#define DmxAdapter_h

#include <Arduino.h>

class DmxAdapter
{
public:
    void write(int channel, int value);
};

#endif