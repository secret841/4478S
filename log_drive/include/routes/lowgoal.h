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
		

		Robot.drivePID(32.5, 0.7, 1800); //Drive forward pick up blocks 

			intakeLow.move_velocity(600);
			Robot.drivePID(5, 0.2, 300);
		Robot.drivePID(-5, 0.2, 300);  
		
		
		Robot.turnPID(106.5, 1, 1000); // -108 Degrees turn to mid goal
		intakeLow.move_velocity(600);
		Robot.drivePID(-17, 0.9, 800); //Drive to mid goal

		intakeLift.set_value(true); //Lifts up hood
		intakeLow.move_velocity(600);
		
		intakeUp.move_velocity(-20);

		intakeLow.move_velocity(0); 
		Robot.drivePID(48, 0.95, 2200); //Turn and drive to loader - NEEDS TO BE CHANGED THE MOST

		matchLoader.set_value(false); //Puts matchloader down
		
		pros::delay(50);
		Robot.turnPID(159, 1.3, 1000); //-138 Degrees: PLS CHANGE IF IT DOESNT WORK YOU MADE IT MORE NEGATIVE
 
		intakeLow.move_velocity(600);
		Robot.drivePID(32.5, 0.32, 800); //Drive into matchloader

		Robot.drivePID(-2.5, 1, 300); //Drive Back a bit
		//Wiggle
 		Robot.drivePID(7.5, 0.5, 500); 
		pros::delay(500);
 
		Robot.drivePID(-30, 1, 300); //Drive Back
		Robot.turnPID(155, 1, 300); 

		Robot.turnToGoal(2000);
		Robot.drivePID(-30, 1.2, 750); 
		matchLoader.set_value(true); //Put matchloader back up
		 

		intakeLift.set_value(true); //Lifts hood

		intakeLow.move_velocity(600);
		intakeUp.move_velocity(600); 

		Robot.drivePID(-10, 1, 250);
		
		intakeLow.move_velocity(600);
		intakeUp.move_velocity(600); 
		pros::delay(1600); 

		Robot.drivePID(5, 1, 300); 
		Robot.drivePID(-10, 2, 400); 
		
		intakeLift.set_value(false);

		//Wing Part not Added Yet

      
}