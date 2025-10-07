#pragma once
#include "main.h"
#include "motors.h"

const float wheelRadius = 2.75; 
float inchesToDegrees(double inches)
{
    double degrees = (inches) / (M_PI / 180);
    degrees /= wheelRadius; 
    return degrees;
}
void drivePID(double inches, int velocit)
{
    //Initialize a million different variables
    double kP, kI, kD; 
    double degrees = inchesToDegrees(inches);
    double error = 10;
    double currentPos = (left_motor.get_position() + right_motor.get_position()) / 2;  
    double endPos = currentPos + degrees;
    double derivative = 0;  
    double prevError = 0; 

    //Keep loop runnning while error is greater than certain tolerance
    while (fabs(error > 1)) 
    {
        currentPos = (left_motor.get_position() + right_motor.get_position()) / 2; 
        error = endPos - currentPos; 

        //Calculate power and then move robot
        double power = (error * kP) + (derivative * kD);
        left_motor.move_voltage(power); 
        right_motor.move_voltage(power); 

        //Get change in error
        derivative = error - prevError; 
        prevError = error;

        //Delay to keep CPU healthy
        pros::delay(20);  

    }
}