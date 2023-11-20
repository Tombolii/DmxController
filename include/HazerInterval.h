#ifndef HazerInterval_h
#define HazerInterval_h

class HazerInterval
{
    public:
    HazerInterval(int duration, int offTime, int hazeTime, int fanLevel, 
    int volumeLevel);
    int duration;
    int offTime;
    int hazeTime;
    bool hazeOn;
    int hazeLastTime;
    int offLastTime;
    int startTime;
    int fanLevel;
    int volumeLevel;
    bool sent;
};

#endif