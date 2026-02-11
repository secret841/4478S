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
	 
	Robot.setPID(0.85, 0, 0.15, 2.2, 0, 0.93); 
	
    intakeLow.move_velocity(600);
		intakeUp.move_velocity(-80);
		wing.set_value(false); //Wing up 
		

		Robot.drivePID(32.5, 0.7, 1800); //Drive forward pick up blocks 
		
		matchLoader.set_value(false); //Puts matchloader down
		mLoad.set_value(true); 
		Robot.turnPID(-106.5, 1, 1000); // -108 Degrees turn to mid goal
		intakeLow.move_velocity(600);
		Robot.drivePID(-17, 0.9, 800); //Drive to mid goal

		intakeLift.set_value(true); //Lifts up hood
		intakeLow.move_velocity(600);
		intakeUp.move_velocity(500); 
		pros::delay(400); 
		intakeLift.set_value(false); //Puts hood down
		intakeUp.move_velocity(-50);

		intakeLow.move_velocity(0); 
		Robot.drivePID(54, 0.94, 2800); //Turn and drive to loader
		pros::delay(50);
		Robot.turnPID(-159, 1.3, 1000); //-138 Degrees: PLS CHANGE IF IT DOESNT WORK YOU MADE IT MORE NEGATIVE
 
		intakeLow.move_velocity(600);
		Robot.drivePID(-6, 1, 150); //Back Up a bit
		
		pros::delay(100);
		Robot.drivePID(22.5, 0.5, 700); //Drive into matchloader

		Robot.drivePID(-2, 1, 300); //Drive Back a bit
		//Wiggle
 		Robot.drivePID(7.5, 0.5, 300); 
		Robot.drivePID(7.5, 0.5, 300);

		pros::delay(150); 
		Robot.drivePID(-20, 1.2, 400); //Drive Back
		Robot.turnPID(-155, 1, 300); 

		Robot.turnToGoal(2000);
		Robot.drivePID(-30, 1.2, 750); 
		matchLoader.set_value(true); //Put matchloader back up
		mLoad.set_value(false); 

		intakeLift.set_value(true); //Lifts hood

		intakeLow.move_velocity(600);
		intakeUp.move_velocity(600); 

		Robot.drivePID(-10, 1, 250);
		
		intakeLow.move_velocity(600);
		intakeUp.move_velocity(600); 
		pros::delay(1250); 
		
		intakeLift.set_value(false);

		Robot.drivePID(7.5, 2, 250);
		Robot.turnPID(-248, 1.6, 600);
		Robot.drivePID(-10.5, 1.1, 500); //Drive back and go back up

		Robot.turnPID(-153, 1.5, 500); 
		wing.set_value(true); //Wing Down
		Robot.drivePID(-25.5, 1.2, 1050);
		
		




		//OLD CODE
		/*Robot.drivePID(5, 1, 200);
		
		Robot.turnPID(-81, 1.5, 750);
		Robot.drivePID(10.5, 2, 600)

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