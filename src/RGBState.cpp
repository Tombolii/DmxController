#include "../include/RGBState.h"

RGBState::RGBState(int red, int green, int blue)
{
    // if (red < 0 || red > 255 || green < 0 || green > 255 || blue < 0 || blue > 255)
    // {
    //     this->red = 0;
    //     this->green = 0;
    //     this->blue = 0;
    // }

    this->red = red;
    this->green = green;
    this->blue = blue;
}
