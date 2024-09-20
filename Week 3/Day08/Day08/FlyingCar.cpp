#include "FlyingCar.h"

std::string FlyingCar::vehicleInformation()
{
    //when overriding, you can
    // 1) FULLY override the base version. you DO NOT call the base method.
    // 2) EXTEND the base version. you DO call the base method.
    //
    // DO NOT duplicate what the base method does
    std::string base = Car::vehicleInformation();//call the base
    std::string derived = "\tMax Altitude: " + std::to_string(maxAltitude_)
        + "\tMax Airspeed: " + std::to_string(maxAirspeed_);
    return base + derived;
}
