#pragma once
#include "main.h"
#include "motors.h"
#include "robo_class.h"
#include "functions.h"

void lowgoal()
{
    defineRobot Robot = defineRobot("4478S"); 
	
	//First three are drivePID, next three are turnPID
	Robot.setPID(1.1, 0, 0.56, 2.9, 0, 0.9); 

        wing.set_value(false); 
		intakeLow.move_velocity(600);
		intakeUp.move_velocity(-100);

		Robot.drivePID(15, 1, 1500);
		intakeLow.move_velocity(600);
		intakeUp.move_velocity(-50);

		Robot.drivePID(7, 0.75, 800); 
		Robot.drivePID(6, 1.2,800); 
		Robot.turnPID(-70, 1, 900); 

		Robot.drivePID(15, 1, 1000); 

		Robot.turnPID(-75, 0.9, 250);
		//intakeLow.move_velocity(-600);

		//pros::delay(200); 
		intakeLow.move_velocity(600); 
		Robot.drivePID(-5, 1, 500); 

		//Score on Low Goal, move to Long
		Robot.drivePID(-45, 1, 2400); 
		Robot.turnPID(162, 0.85, 1300);

		Robot.drivePID(-35, 0.9, 1500);

		//Pause to score on long, lifts up hood
		intakeLift.set_value(true); 
		intakeLow.move_velocity(600); 
		intakeUp.move_velocity(600);
		pros::delay(1400); 

		Robot.drivePID(5, 0.8, 1000);
		intakeUp.move_velocity(-200);

		//Turn for Wing
			
		Robot.turnPID(240, 1.2, 400); 
		Robot.drivePID(15.5, 1.3, 400); 
		Robot.turnPID(156, 1.8, 600); 

		//Put Down Wing
		Robot.drivePID(-13, 2, 500); 
		wing.set_value(true); 
		Robot.turnPID(145, 2, 400); 
		Robot.drivePID(-15, 1.2, 800);


		//Swing Around
		//right_motor.move_absolute(300, 400);
	
		
		//Score on High Goal
	
		
		/*
		intakeLow.move_velocity(600); 

		Robot.drivePID(7.5, 0.5, 2000);

		Robot.turnPID(-55, 1, 1500);

		Robot.drivePID(20, 1, 1000); 
		intakeLow.move_velocity(-600);
		
		pros::delay(1000);

		Robot.drivePID(-5, 1, 1000); 
		Robot.drivePID(5, 2, 1000);*/
}