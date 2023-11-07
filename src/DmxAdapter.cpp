#include "../include/DmxAdapter.h"

void DmxAdapter::write(int channel, int value)
{
    byte buf[2] = {channel, value};    
    Serial1.write(buf, 2);
    Serial.print("Channel: ");
    Serial.print(channel);
    Serial.print(" Value: ");
    Serial.println(value);

}
