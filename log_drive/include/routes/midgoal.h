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
		matchLoader.set_value(false); //Puts matchloader up
		mLoad.set_value(true); 

		Robot.drivePID(31, 0.85, 2000); //Drive forward pick up blocks 
		Robot.turnPID(-106.5, 1, 1200); // -108 Degrees turn to mid goal
		Robot.drivePID(-17, 0.9, 1000); //Drive to mid goal

		intakeUp.move_velocity(600); 
		pros::delay(300); 
		intakeUp.move_velocity(-100);

		Robot.drivePID(57, 1, 2700); //Turn and drive to loader
		Robot.turnPID(-159, 1.3, 1100); //-138 Degrees: PLS CHANGE IF IT DOESNT WORK YOU MADE IT MORE NEGATIVE

		Robot.drivePID(-6, 1, 150); //Back Up a bit
		matchLoader.set_value(true); //Puts matchloader down
		mLoad.set_value(false); 
		pros::delay(100);
		Robot.drivePID(18.5, 0.7, 700); 

		Robot.drivePID(-2, 1, 200); //Drive Back a bit
		//Wiggle
		Robot.drivePID(3, 0.5, 300); 
		Robot.drivePID(3, 0.7, 300);

		pros::delay(150); 
		Robot.drivePID(-5, 0.5, 150); //Drive Back

		Robot.turnPID(-159, 1, 400);//-5 Degrees

		
		Robot.drivePID(-30, 1.2, 800); 
		matchLoader.set_value(false); //Put matchloader back up
		mLoad.set_value(true); 

		intakeLow.move_velocity(600);
		intakeUp.move_velocity(600); 
		intakeLift.set_value(true); 

		pros::delay(1300); 
		wing.set_value(true); //Wing up
		intakeLift.set_value(false);

		Robot.drivePID(3, 1, 200);
		Robot.turnPID(-248, 1.4, 700);
		Robot.drivePID(11.5, 1.2, 500);

		Robot.turnPID(-350, 1.4, 700); 
		Robot.drivePID(23.5, 1.5, 800);
		/*Robot.drivePID(5, 1, 200);
		
		Robot.turnPID(-81, 1.5, 750);
		Robot.drivePID(10.5, 2, 600);

			Robot.turnPID(-163, 2, 650);
			Robot.drivePID(-20, 2, 500);
			wing.set_value(false);
				Robot.drivePID(-20, 1.5, 500);*/

		//Robot.drivePID(-156, 1.3, 700); 
		/*Robot.drivePID(-15, 1.3, 500); 
		wing.set_value(false); //Wing Down

		Robot.drivePID(-22, 1.3, 500); */
	
		
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