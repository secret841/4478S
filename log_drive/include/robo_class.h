#pragma once
#include "motors.h"
#include "functions.h"
#include "main.h"
#include <string>

class defineRobot {
    private:
        double kP, kI, kD;
        double tKP, tKI, tKD;  
        std::string robotName; 
    public:
        defineRobot(std::string name)
        {
            robotName = name; 
        }
        std::string returnName(); 
        void setPID(double p, double i, double d, double tP, double tI, double tD); 
        void drivePID(double inches, double velocit, int waitTime); 
        void turnPID(double heading, double velocit, int waitTime); 
        void swingPID(double heading, double velocit, int waitTime);
};

void defineRobot::setPID(double p, double i, double d, double tP, double tI, double tD)
{
    kP = p; 
    kI = i;
    kD = d; 
    tKP = tP;
    tKI = tI; 
    tKD = tD; 
}

std::string defineRobot::returnName()
{
    return robotName;
}

void defineRobot::turnPID(double heading, double velocit, int waitTime)
{
    int currWait = 0;
    double error = heading - Inertial.get_rotation(); 
     pros::lcd::set_text(2, "Original Error " + std::to_string(error)); 
    double derivative = 0;
    double prevError = 0;
    
    while (fabs(error) >= 0.1 && currWait <= waitTime)
    {
        error = heading - Inertial.get_rotation();
        double power = (error * tKP) + (derivative * tKD); 

        left_motor.move_velocity(power); 
        right_motor.move_velocity(-power); 

        derivative = error - prevError; 
        prevError = error; 

        //Keeps robot from self-destructing
        currWait += 20;
        pros::delay(20); 
        pros::lcd::set_text(1, std::to_string(error)); 
    }
    left_motor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    right_motor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD); 
    left_motor.move_velocity(0);
    right_motor.move_velocity(0); 
}

//Only right swing at the moment
void defineRobot::swingPID(double heading, double velocit, int waitTime)
{
    int currWait = 0;
    double error = heading - Inertial.get_rotation(); 
     pros::lcd::set_text(2, "Original Error " + std::to_string(error)); 
    double derivative = 0;
    double prevError = 0;
    
    while (fabs(error) >= 0.1 && currWait <= waitTime)
    {
        error = heading - Inertial.get_rotation();
        double power = (error * tKP) + (derivative * tKD); 

        right_motor.move_velocity(power);
        left_motor.move_velocity(-power/2);  

        derivative = error - prevError; 
        prevError = error; 

        //Keeps robot from self-destructing
        currWait += 20;
        pros::delay(20); 
        pros::lcd::set_text(1, std::to_string(error)); 
    }
    left_motor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    right_motor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD); 
    left_motor.move_velocity(0);
    right_motor.move_velocity(0); 
}

void defineRobot::drivePID(double inches, double velocit, int waitTime)
{
    //Initialize a million different variables
    double degrees = inchesToDegrees(inches);
    double error = 10;
    double currentPos = (left_motor.get_position() + right_motor.get_position()) / 2;  
    double endPos = currentPos + degrees;
    double derivative = 0;  
    double prevError = 0; 

    double slew = 15;
    int currWait = 0; 

 
    //Keep loop runnning while error is greater than certain tolerance or under certain time
    while (fabs(error) > 1 && currWait <= waitTime) 
    {
        currentPos = (left_motor.get_position() + right_motor.get_position()) / 2; 
        error = endPos - currentPos; 
 
         derivative = error - prevError; 

        //Calculate power and then move robot
        double power = (error * kP) + (derivative * kD);
        power *= velocit;

        if (fabs(power) > slew)
        {
            power < 0 ? power = -slew: power = slew; 
        }
        left_motor.move_velocity(power); 
        right_motor.move_velocity(power); 

        //Get change in error
       
        prevError = error;

        //Delay to keep CPU healthy, increment slew rate
        slew += 20; 
        currWait += 20;
        pros::delay(20);
        // pros::lcd::set_text(1, std::to_string(error));  

    }
    //Stops the motors
    left_motor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    right_motor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD); 
    left_motor.move_velocity(0);
    right_motor.move_velocity(0); 

    return;
}





