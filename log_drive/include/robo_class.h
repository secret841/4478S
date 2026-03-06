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
        void turnToGoal(int waitTime);
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

        left_motor.move_velocity(power * velocit); 
        right_motor.move_velocity(-power * velocit); 

        derivative = error - prevError; 
        prevError = error; 

        //Keeps robot from self-destructing
        currWait += 20;
        pros::delay(20); 
        pros::lcd::set_text(1, std::to_string(error)); 
    }
    maxTime -= currWait; 
    left_motor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    right_motor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD); 
    left_motor.move_velocity(0);
    right_motor.move_velocity(0); 
}

 void defineRobot::turnToGoal(int waitTime) {

    double currDist = distanceSensor.get_distance(); //get current distance sensor read (mm)
    double getSize = distanceSensor.get_object_size(); 
    bool foundGoal = false;  
    int time = 0; 

     pros::lcd::set_text(5, "getSize " + std::to_string(getSize)); 

    double heading = Inertial.get_rotation() + 16; 
    double error = 10; 

    if (currDist >= 30 && currDist <= 750)
    {
        left_motor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
        right_motor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD); 
        left_motor.move_velocity(0);
        right_motor.move_velocity(0); 
        return; 
    }

    while (fabs(error) >= 1 && !foundGoal && time <= waitTime/2)
    {
        getSize = distanceSensor.get_object_size(); 
        currDist = distanceSensor.get_distance();
        //getSize = distanceSensor.get_object_size(); 
        if ((currDist >= 30 && currDist <= 750) && getSize >= 350)
        {
            foundGoal = true; 
        }
        error = heading - Inertial.get_rotation();

         left_motor.move_velocity(40); 
        right_motor.move_velocity(-40); 

         time += 20;  //Increments time
         pros::lcd::set_text(5, "currDist " + std::to_string(currDist)); 
        pros::delay(20); 
       
    }

    if (foundGoal)
    {
         left_motor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
        right_motor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD); 
        left_motor.move_velocity(0);
        right_motor.move_velocity(0);
        maxTime -= time;  
        return; 
    }
    else
    {
        time = 0; 
        error = 10; 
        heading = Inertial.get_rotation() - 32;
        while (fabs(error) >= 1 && !foundGoal && time <= waitTime/2)
        {
             getSize = distanceSensor.get_object_size(); 
            currDist = distanceSensor.get_distance();
            if ((currDist >= 30 && currDist <= 750) && getSize >= 350)
            {
                foundGoal = true; 
            }
            error = heading - Inertial.get_rotation();

            left_motor.move_velocity(-50); 
            right_motor.move_velocity(50);
             pros::lcd::set_text(5, "Error " + std::to_string(error)); 
        
            time += 20; 
         pros::delay(20); 
        } 
    }

    maxTime -= time; 
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

    double slew = 5;
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

       if (fabs(power) >= 550)
        {
            double factor = 21.5 + log((power - 300) * (power - 300)); 
            if (power >= 0)
            {
                left_motor.move_velocity(power - factor); 
                right_motor.move_velocity(power - factor);
            }
            else
            {
                left_motor.move_velocity(power + factor); 
                right_motor.move_velocity(power + factor);
            }

        }
        else
        {
            left_motor.move_velocity(power); 
            right_motor.move_velocity(power);
        }

          

        //Get change in error
       
        prevError = error;

        //Delay to keep CPU healthy, increment slew rate
        slew += 15; 
        currWait += 20;
        pros::lcd::set_text(5, std::to_string(error)); 
        pros::delay(20);
        // pros::lcd::set_text(1, std::to_string(error));  

    }
    maxTime -= currWait; 
    //Stops the motors
    left_motor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    right_motor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD); 
    left_motor.move_velocity(0);
    right_motor.move_velocity(0); 

    return;
}





