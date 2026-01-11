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
		matchLoader.set_value(true); //Puts matchloader down
		pros::delay(500); 

		intakeLow.move_velocity(600); //Turn on intake(s)
		intakeUp.move_velocity(-100);

		Robot.drivePID(9.5, 0.9, 1000); //Drive to loader
		 
		Robot.drivePID(-2, 1, 200); //Drive Back a bit
		//Wiggle
		Robot.drivePID(4.5, 0.4, 400); 
		Robot.drivePID(4.5, 0.4, 400);
		Robot.drivePID(4.5, 0.4, 400);

		pros::delay(400); 

		//Drive Back and then realign
		Robot.drivePID(-5, 1.5, 500); 
		matchLoader.set_value(false);
		Robot.turnPID(-100, 1, 200); //-15 Degrees
		Robot.drivePID(-32, 1.3, 1500);

		intakeLift.set_value(true);
		intakeUp.move_velocity(600); 
		pros::delay(1200); 
		intakeUp.move_velocity(-100);

		Robot.drivePID(7.5, 1.3, 600);
		Robot.turnPID(-15, 1.5, 800); //+90 Degrees
		Robot.drivePID(7, 1, 950);
		Robot.turnPID(-110, 1.2, 900);  //-85 Degrees

		wing.set_value(true); //Wing Up
		Robot.drivePID(-27, 2.5, 500);
		wing.set_value(false); //Wing Down
		Robot.drivePID(-15.5, 2.2, 600); //RAAAAM
}