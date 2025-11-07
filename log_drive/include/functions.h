#pragma once
#include "main.h"
#include "motors.h"

const float wheelRadius = 2.75; 
const float gearRatio = 0.5;
float inchesToDegrees(double inches)
{
    double degrees = (inches) / (2 * M_PI * wheelRadius * gearRatio);
    degrees *= 360;
    return degrees;
}

void intake (void * param)
{
    while (true)
    {
        intakeLow.move_velocity(-600); 
    }
}