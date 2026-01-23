#pragma once
#include "main.h"
#include "motors.h"
#include "robo_class.h"
#include "functions.h"

void lowGoalCoward()
{
    defineRobot Robot = defineRobot("4478S"); 
	
	//First three are drivePID, next three are turnPID
	Robot.setPID(1.1, 0, 0.56, 2.9, 0, 0.9); 
    
	//Low Goal Coward: Start = 90 Degrees
	Robot.drivePID(34.5, 1, 1500); 
		Robot.turnPID(92, 1, 1000); //+92 Degrees
		matchLoader.set_value(true); //Puts matchloader down
		mLoad.set_value(false); 
		pros::delay(300); 

		intakeLow.move_velocity(600); //Turn on intake(s)
		intakeUp.move_velocity(-100);

		Robot.drivePID(11, 0.85, 1000); //Drive to loader
		 
		Robot.drivePID(-2, 1, 200); //Drive Back a bit
		//Wiggle
		Robot.drivePID(3, 0.4, 400); 
		Robot.drivePID(3, 0.4, 400);

		pros::delay(100); 

		//Drive Back and then realign
		Robot.drivePID(-5, 1.5, 300); 
		Robot.turnPID(88, 1, 300); //-4 Degrees
		Robot.drivePID(-32, 1.5, 1000);

		intakeLift.set_value(true);
			matchLoader.set_value(false);
			mLoad.set_value(true); 
		intakeUp.move_velocity(600); 
		pros::delay(1300); 
		intakeUp.move_velocity(-100);

	

		Robot.drivePID(6, 1.5, 500);
		Robot.turnPID(17, 1.5, 800); //-90 Degrees
		Robot.drivePID(12, 1, 550);
		Robot.turnPID(-85, 1.2, 700);  //-99 Degrees

		wing.set_value(false); //Wing Up
		Robot.drivePID(12, 2.5, 500);
		Robot.turnPID(-93, 1.2, 200);  //-90 Degrees Readjust
		wing.set_value(true); //Wing Down
		Robot.drivePID(8, 2.2, 650); //RAAAAM
}