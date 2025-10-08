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
void drivePID(double inches, int velocit, int waitTime)
{
    //Initialize a million different variables
    double kP = 0, kI = 0, kD = 0; 
    double degrees = inchesToDegrees(inches);
    double error = 10;
    double currentPos = (left_motor.get_position() + right_motor.get_position()) / 2;  
    double endPos = currentPos + degrees;
    double derivative = 0;  
    double prevError = 0; 

    double slew = 500;
    int currWait = 0; 

    //Keep loop runnning while error is greater than certain tolerance or under certain time
    while (fabs(error > 1) && currWait <= waitTime) 
    {
        currentPos = (left_motor.get_position() + right_motor.get_position()) / 2; 
        error = endPos - currentPos; 

        //Calculate power and then move robot
        double power = (error * kP) + (derivative * kD);

        if (power > slew)
        {
            power < 0 ? power = -slew: power = slew; 
        }
        left_motor.move_voltage(power); 
        right_motor.move_voltage(power); 

        //Get change in error
        derivative = error - prevError; 
        prevError = error;

        //Delay to keep CPU healthy, increment slew rate
        slew += 100; 
        currWait += 20;
        pros::delay(20);  

    }
    //Stops the motors
    left_motor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    right_motor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD); 
    left_motor.move_velocity(0);
    right_motor.move_velocity(0); 
}