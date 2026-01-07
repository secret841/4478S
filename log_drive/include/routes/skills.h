
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
		intakeUp.move_velocity(500); 

		pros::delay(1000);
		intakeUp.move_velocity(-50);  
		intakeLow.move_velocity(600); 

		Robot.drivePID(13, 1, 1000); 
		Robot.turnPID(125, 1, 1300);

		Robot.drivePID(30, 1, 2500);
		Robot.drivePID(12, 0.6, 1500); 

		//Offset about 33 degrees

		//Going to long goal on other side
		Robot.turnPID(165, 1, 1500); 
		Robot.drivePID(35, 1, 1800); 

		//Score on Long Goal
		Robot.turnPID(210, 1, 1800);
		Robot.drivePID(-50, 1, 1000); 

		intakeLow.move_velocity(600); 
		intakeUp.move_velocity(600); 

		pros::delay(7500);

		//Back up and Turn to Park
		Robot.drivePID(5, 0.2, 1000); 
		Robot.drivePID(15, 1, 1000); 
		Robot.turnPID(93, 1, 1300);
		Robot.drivePID(-45, 1, 2800);  

		Robot.turnPID(132, 1, 1200); 
		Robot.drivePID(-700, 2.5, 5500);
}