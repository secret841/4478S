
#pragma once
#include "main.h"
#include "motors.h"
#include "robo_class.h"
#include "functions.h"

void skills()
{

    defineRobot Robot = defineRobot("4478S"); 
	
	//First three are drivePID, next three are turnPID
	Robot.setPID(1.1, 0, 0.56, 2.9, 0, 0.9); 
    //Mid Goal Coward - Start = 270 Degrees

		Robot.drivePID(34.5, 1, 1500); 
		Robot.turnPID(-92, 1, 1000); //-92 Degrees
		matchLoader.set_value(false); //Puts matchloader down
		pros::delay(500); 

		intakeLow.move_velocity(600); //Turn on intake(s)
		intakeUp.move_velocity(-100);

		Robot.drivePID(9.5, 0.9, 1000); //Drive to loader
		 
		Robot.drivePID(-2, 1, 200); //Drive Back a bit
		//Wiggle
		Robot.drivePID(4.5, 0.4, 400); 
		Robot.drivePID(4.5, 0.4, 400);
		Robot.drivePID(4.5, 0.4, 400);

		pros::delay(2500); 

		//Drive Back and then realign
		Robot.drivePID(-5, 1.5, 500); 
		matchLoader.set_value(true);
		Robot.turnPID(-100, 1, 200); //-15 Degrees
		Robot.drivePID(-32, 1.3, 1500);

		intakeLift.set_value(true);
		intakeUp.move_velocity(600); 
		pros::delay(4000); 
		intakeUp.move_velocity(-100);

		intakeLift.set_value(false);

		Robot.drivePID(16.5, 1.3, 1000);
		Robot.turnPID(25, 1.1, 1100); //+90 Degrees
		Robot.drivePID(-14, 1, 1000);

		Robot.turnPID(0, 1, 1000); 
		Robot.drivePID(-50, 1, 2000);

	

}