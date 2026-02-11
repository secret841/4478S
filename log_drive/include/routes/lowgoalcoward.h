#pragma once
#include "main.h"
#include "motors.h"
#include "robo_class.h"
#include "functions.h"

void lowGoalCoward()
{
    defineRobot Robot = defineRobot("4478S"); 
	
	//First three are drivePID, next three are turnPID
	Robot.setPID(0.85, 0, 0.15, 2.2, 0, 0.93); 
    
	//Low Goal Coward: Start = 90 Degrees
	Robot.drivePID(34.5, 1, 1500); 
		Robot.turnPID(92, 1, 1000); //+92 Degrees
		wing.set_value(false); //Wing up

		intakeLift.set_value(false); 
		matchLoader.set_value(false); //Puts matchloader down
		mLoad.set_value(true); 
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
			matchLoader.set_value(true); //Matchloader back up
			mLoad.set_value(false); 
		intakeUp.move_velocity(600); 
		pros::delay(1600); 
		intakeUp.move_velocity(-100);

	

		Robot.drivePID(6, 1.5, 500);
		Robot.turnPID(17, 1.5, 800); //-90 Degrees
		Robot.drivePID(10.5, 1, 550);
		Robot.turnPID(-88, 1.2, 850);  //-99 Degrees

		wing.set_value(false); //Wing Up
		Robot.drivePID(15, 2.5, 700);
		Robot.turnPID(-93, 1.2, 200);  //-90 Degrees Readjust
		wing.set_value(true); //Wing Down
		Robot.drivePID(15, 0.5, 850); //RAAAAM
}