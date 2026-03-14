#pragma once
#include "main.h"
#include "motors.h"
#include "robo_class.h"
#include "functions.h"

void lowgoal()
{
    defineRobot Robot = defineRobot("4478S"); 
	
	//First three are drivePID, next three are turnPID
	Robot.setPID(0.85, 0, 0.15, 2.2, 0, 0.93); 

	intakeLow.move_velocity(600);
		intakeUp.move_velocity(-20);
		wing.set_value(false); //Wing up 
		

		Robot.drivePID(34.8, 0.4, 1500); //Drive forward pick up blocks 
		pros::delay(150);

			intakeLow.move_velocity(600);
		
		Robot.turnPID(106.5, 1, 1000); // -108 Degrees turn to mid goal
		intakeLow.move_velocity(600);
		//Robot.drivePID(-18.5, 0.9, 800); //Drive to mid goal

		intakeLift.set_value(true); //Lifts up hood
		intakeLow.move_velocity(600);
		
		intakeUp.move_velocity(-20);

		intakeLow.move_velocity(0); 
		Robot.drivePID(33.5, 0.95, 1600); //Turn and drive to loader - NEEDS TO BE CHANGED THE MOST

		matchLoader.set_value(false); //Puts matchloader down
		
		pros::delay(50);

		//BIG DELAY ADDED HERE!
		Robot.turnPID(158, 1, 1000); //-138 Degrees: PLS CHANGE
	
 
		intakeLow.move_velocity(600);
		/*
		Robot.drivePID(33.5, 0.23, 800); //Drive into matchloader
 		Robot.drivePID(9.5, 0.14, 500); 
		*/

		//Wiggle
		Robot.bumperGo(200, 1000); 
		Robot.drivePID(-0.5, 1, 200);

		Robot.bumperGo(150, 1000); 
		Robot.drivePID(-0.5, 1, 200);
		pros::delay(500);
 
		Robot.drivePID(-30, 1, 450); //Drive Back
		Robot.turnPID(149, 1.1, 600); 
Robot.turnToGoal(2000, 525);
		
		Robot.drivePID(-30, 0.8, 900); 
		matchLoader.set_value(true); //Put matchloader back up
		 

		intakeLift.set_value(true); //Lifts hood
		Robot.drivePID(-10, 1.5, 300);

		intakeLow.move_velocity(600);
		intakeUp.move_velocity(600); 

		
		
		intakeLow.move_velocity(600);
		intakeUp.move_velocity(600); 
		pros::delay(1800); 

		Robot.drivePID(7.5, 1, 300);
		Robot.turnPID(248.5, 1.6, 550);  
		Robot.drivePID(16.5, 1.1, 700); 

		Robot.turnPID(158.5, 1.3, 800);
		wing.set_value(true); //Wing Down 
		Robot.drivePID(-29, 0.55, 1000); //Speed up for elims and such
		
		intakeLift.set_value(false);

		//Wing Part not Added Yet

      
}