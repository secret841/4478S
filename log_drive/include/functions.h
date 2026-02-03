#pragma once
#include "main.h"
#include "motors.h"

const float wheelRadius = 3.25; 
const float gearRatio = 36/60;
float inchesToDegrees(double inches)
{
    double degrees = (inches) / (2 * M_PI * wheelRadius * gearRatio);
    degrees *= 360;
    return degrees;
}

int velocityMove = 600; 
void intake (void * param)
{
    while (true)
    {
        intakeLow.move_velocity(velocityMove); 
    }
}