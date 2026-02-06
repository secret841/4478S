#pragma once
#include "main.h"
#include "motors.h"
#include "robo_class.h"
#include "functions.h"

void cowardSkills()
{
	 defineRobot Robot = defineRobot("4478S"); 
	
	//First three are drivePID, next three are turnPID
	Robot.setPID(0.85, 0, 0.15, 2.2, 0, 0.93); 
    Robot.drivePID(34.5, 1, 1500); 
	pros::delay(200);
		Robot.turnPID(92, 1, 1000); //+92 Degrees
		matchLoader.set_value(false); //Puts matchloader down
		mLoad.set_value(true); 
		wing.set_value(false); 
		pros::delay(300); 

		intakeLow.move_velocity(600); //Turn on intake(s)
		intakeUp.move_velocity(-100);

		pros::delay(200); 
		Robot.drivePID(13, 0.85, 1000); //Drive to loader

		Robot.drivePID(-2, 1, 200); //Drive Back a bit
		//Wiggle
		Robot.drivePID(5, 0.4, 400); 
		Robot.drivePID(5, 0.4, 400);
		Robot.drivePID(5, 0.4, 400);

		pros::delay(1300); 

		//Drive Back and then realign
		intakeUp.move_velocity(-100);
		intakeUp.move_velocity(-100); 
		intakeLow.move_velocity(0); 

		Robot.drivePID(-5, 1.5, 300); 
		Robot.turnPID(88, 1, 300); //-4 Degrees
        Robot.turnToGoal(1000); 
		Robot.drivePID(-32, 1.5, 1100);
		matchLoader.set_value(true); //Puts matchloader up
		mLoad.set_value(false); 

        intakeLow.move_velocity(600); 
        intakeUp.move_velocity(600); 

		intakeLift.set_value(true); //Puts hood up
        pros::delay(2000); 

		Robot.turnPID(90, 1, 500); 


		Robot.drivePID(25, 1, 1200);
		Robot.drivePID(-6, 1, 1000); 
        Robot.turnPID(145, 1, 2000); 

        Robot.drivePID(36, 1, 2000); 
		

		Robot.turnPID(155, 1, 2000);
		matchLoader.set_value(false); //Puts matchloader down
		mLoad.set_value(true); 

		pros::delay(500); 
		Robot.drivePID(45, 1, 2000); 
		Robot.drivePID(-15, 1, 2000); 
		wing.set_value(false); 

		intakeLift.set_value(false); //Put intake lift down again
		matchLoader.set_value(true); //Puts matchloader up
		mLoad.set_value(false); 
}