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
		Robot.turnPID(93, 1, 1000); //+92 Degrees
		matchLoader.set_value(false); //Puts matchloader down
		
		wing.set_value(false); 
		pros::delay(600);

		intakeLow.move_velocity(600); //Turn on intake(s)
		intakeUp.move_velocity(-10);

		intakeLow.move_velocity(600); //Turn on intake(s)
		Robot.drivePID(23.5, 0.08, 1500); //Drive to loader
		pros::delay(1500);
		Robot.drivePID(6.5, 0.12, 400);
		 
		intakeLow.move_velocity(600); //Turn on intake(s)
		intakeLow.move_velocity(600); //Turn on intake(s)
		pros::delay(1500);

		//Drive Back and then realign
		intakeUp.move_velocity(-20);
		intakeUp.move_velocity(-100); 
		intakeLow.move_velocity(0); 

		Robot.drivePID(-5, 0.8, 700); 
		Robot.turnPID(88, 1, 300); //-4 Degrees
        Robot.turnToGoal(1000); 
		Robot.drivePID(-32, 1.5, 1100);
		matchLoader.set_value(true); //Puts matchloader up
	 

        intakeLow.move_velocity(600); 
        intakeUp.move_velocity(600);
		
		Robot.drivePID(-10, 1, 500);

		intakeLift.set_value(true); //Puts hood up
        pros::delay(2500); 

		 intakeUp.move_velocity(0);
		Robot.drivePID(15, 0.5, 1000); 
		intakeLift.set_value(false); 
		Robot.drivePID(-15, 1, 1000); 

		 intakeLow.move_velocity(600); 
        intakeUp.move_velocity(600);
		
		Robot.drivePID(-10, 1, 500);
		intakeLift.set_value(true); 
		pros::delay(1500); 
		Robot.turnPID(90, 1, 500); 


		Robot.drivePID(25, 1, 1200);
		Robot.drivePID(-6, 1, 1000); 
        Robot.turnPID(145, 1, 2000); 

        Robot.drivePID(39.5, 0.8, 2000); 
		

		Robot.turnPID(170, 1, 2000);
		Robot.drivePID(1, 1, 300);
		matchLoader.set_value(false); //Puts matchloader down
		
 
		Robot.turnPID(160, 1, 1000);

		Robot.drivePID(35, 0.9, 2000); 
		
		wing.set_value(false); 


		intakeLow.move_velocity(600); 
		Robot.drivePID(5, 0.1, 2000);
		//Robot.drivePID(-10.5, 1.4, 1000); 
		intakeLift.set_value(false); //Put intake lift down again
		matchLoader.set_value(true); //Puts matchloader up
	
}