#pragma once
#include "main.h"
#include "motors.h"
#include "robo_class.h"
#include "functions.h"

void midgoalcoward()
{
    defineRobot Robot = defineRobot("4478S"); 
	
	//First three are drivePID, next three are turnPID
	Robot.setPID(1.1, 0, 0.56, 2.9, 0, 0.9); 
    //Mid Goal Coward - Start = 270 Degrees
		 

		Robot.drivePID(34.5, 1, 1500); 
		Robot.turnPID(-92, 1, 1000); //-92 Degrees
		matchLoader.set_value(false); //Puts matchloader down
		pros::delay(100); 

		Robot.drivePID(9.5, 1.3, 1000); //Drive to loader
		intakeLow.move_velocity(600); //Turn on intake(s)
		intakeUp.move_velocity(-100); 

		//Wiggle
		for (int i = 0; i < 20; i++)
		{
			if (i % 2 == 0)
			{
				left_motor.move_velocity(200); 
				right_motor.move_velocity(200); 
			}
			else
			{
				left_motor.move_velocity(-200); 
				right_motor.move_velocity(-200); 
			}
			pros::delay(30);
		}
		pros::delay(900); 

		//Drive Back and then realign
		Robot.drivePID(-5, 1.5, 500); 
		Robot.turnPID(-103, 1, 200); //-13 Degrees
		Robot.drivePID(-32, 1.5, 1500);

		intakeLift.set_value(true);
		intakeUp.move_velocity(600); 
		pros::delay(1000); 
		intakeUp.move_velocity(-100);

		Robot.drivePID(6, 1.5, 500);
		Robot.turnPID(-190, 1.5, 800); //-90 Degrees
		Robot.drivePID(9, 1.5, 500);
		Robot.turnPID(-282, 1.5, 700);  //-92 Degrees

		wing.set_value(false); //Wing Up
		Robot.drivePID(20, 2.5, 500);
		wing.set_value(true); //Wing Down
		matchLoader.set_value(true);
		Robot.drivePID(15, 2.5, 500);
		
		/*Robot.turnPID(-90, 0.9, 2000);  
		Robot.drivePID(-35, 0.6, 1600);

		//Outtake
		intakeLow.move_velocity(600); 
		intakeUp.move_velocity(600);

		pros::delay(3000); 
		Robot.drivePID(10, 0.5, 1000);*/
}