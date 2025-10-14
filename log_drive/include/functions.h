#pragma once
#include "main.h"
#include "motors.h"

const float wheelRadius = 2.75; 
float inchesToDegrees(double inches)
{
    double degrees = (inches) / (2 * M_PI * wheelRadius);
    degrees *= 360; 
    return degrees;
}
