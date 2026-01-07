#pragma once
#include "main.h"
#include "motors.h"
#include "robo_class.h"
#include "functions.h"

void midgoal()
{
    defineRobot Robot = defineRobot("4478S"); 
	
	//First three are drivePID, next three are turnPID
	Robot.setPID(1.1, 0, 0.56, 2.9, 0, 0.9); 
    intakeLow.move_velocity(600);
		intakeUp.move_velocity(-100); 
		Robot.drivePID(19, 0.8, 2300);
		
		Robot.drivePID(9.5, 0.5, 2000);
		pros::delay(250);

		intakeLow.move_velocity(600); 

		//Robot.drivePID(9.5, 0.6, 1000);

		Robot.turnPID(-110, 0.85, 1800);

		//Drive towards mid goal
		Robot.drivePID(-21.5, 0.8, 1000); 

		//Back up a bit, then score
		Robot.drivePID(1.1, 0.9, 500); 
		pros::delay(300);
		intakeLow.move_velocity(600); 
		intakeUp.move_velocity(200); 

		pros::delay(800);
		intakeUp.move_velocity(0);  
		intakeLow.move_velocity(600); 

		//Drive back a bit, readjust angle, then drive more
		Robot.drivePID(18, 1, 900);
		Robot.turnPID(-100, 1, 800);

		Robot.drivePID(28.5, 1.2, 1800);

		//Turn to long goal and score
		Robot.turnPID(-169, 1.2, 900);
		Robot.drivePID(-18, 1, 1000);
		
		intakeLift.set_value(true); 
		intakeLow.move_velocity(600);
		intakeUp.move_velocity(600); 

		pros::delay(2000); 
		Robot.drivePID(7, 0.4, 1000); 
}