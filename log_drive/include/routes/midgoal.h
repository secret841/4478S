#pragma once
#include "main.h"
#include "motors.h"
#include "robo_class.h"
#include "functions.h"

void midgoal()
{
    defineRobot Robot = defineRobot("4478S"); 
	
	//First three are drivePID, next three are turnPID
	//Mid Goal Auton - Starts at around 27 Degrees
	Robot.setPID(1.1, 0, 0.56, 2.9, 0, 0.9); 
    intakeLow.move_velocity(600);
		intakeUp.move_velocity(-100);
		matchLoader.set_value(true); //Puts matchloader up

		Robot.drivePID(30.5, 0.9, 2000); //Drive forward pick up blocks
		pros::delay(150); 
		Robot.turnPID(-106.5, 1, 1200); // -108 Degrees turn to mid goal
		Robot.drivePID(-17, 0.9, 1000); //Drive to mid goal

		intakeUp.move_velocity(600); 
		pros::delay(450); 
		intakeUp.move_velocity(-100);

		Robot.drivePID(59, 1, 2700); //Turn and drive to loader
		Robot.turnPID(-159, 1, 1200); //-138 Degrees: PLS CHANGE IF IT DOESNT WORK YOU MADE IT MORE NEGATIVE

		Robot.drivePID(-6, 1, 150); //Back Up a bit
		matchLoader.set_value(false); //Puts matchloader down
		pros::delay(250);
		Robot.drivePID(18.5, 0.7, 800); 

		Robot.drivePID(-2, 1, 200); //Drive Back a bit
		//Wiggle
		Robot.drivePID(3, 0.5, 300); 
		Robot.drivePID(3, 0.5, 300);

		pros::delay(150); 
		Robot.drivePID(-5, 0.5, 200); //Drive Back

		Robot.turnPID(-156, 1, 400);//-5 Degrees

		
		Robot.drivePID(-30, 1.2, 1000); 
		matchLoader.set_value(true); //Put matchloader back up

		intakeLow.move_velocity(600);
		intakeUp.move_velocity(600); 
		intakeLift.set_value(true); 

		pros::delay(1000); 
		wing.set_value(true); //Wing up

		
		Robot.swingPID(27, 0.4, 1000); //Turn
		wing.set_value(false); //Wing Down
		
		Robot.drivePID(20, 1, 1000);
		//left_motor.move_absolute(800, 200);
		

		/*pros::delay(1550); 

		intakeLift.set_value(false);
		Robot.drivePID(5, 1, 200); 
		Robot.drivePID(-30, 1.2, 800);*/
		

		//////////////////
}

/*
Old Mid Goal
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
*/