
#pragma once
#include "main.h"
#include "motors.h"
#include "robo_class.h"
#include "functions.h"

void skills()
{
	 defineRobot Robot = defineRobot("4478S"); 
	
	//First three are drivePID, next three are turnPID
	Robot.setPID(0.85, 0, 0.15, 2.2, 0, 0.93); 

	matchLoader.set_value(false); //Puts matchloader down
		mLoad.set_value(true);
    
	//Low Goal Coward: Start = 90 Degrees
	Robot.drivePID(34.5, 1, 1500); 
	pros::delay(200);
		Robot.turnPID(92, 1, 1000); //+92 Degrees
		 
		wing.set_value(false); 
		pros::delay(300); 

		intakeLow.move_velocity(600); //Turn on intake(s)
		intakeUp.move_velocity(-20);

		intakeLow.move_velocity(600); //Turn on intake(s)
		Robot.drivePID(16, 0.3, 1500); //Drive to loader
		 
		intakeLow.move_velocity(600); //Turn on intake(s)
		Robot.drivePID(-5, 1, 400); //Drive Back a bit

		intakeLow.move_velocity(600); //Turn on intake(s)
		pros::delay(200);
		//Wiggle
		Robot.drivePID(4, 1, 400); 
		//pros::delay(500); 
		//Robot.drivePID(4, 1, 300);
		//Robot.drivePID(3, 1, 300);  


		pros::delay(1800); 

		//Drive Back and then realign
		intakeUp.move_velocity(-50); 
		intakeLow.move_velocity(300); 

		Robot.drivePID(-5, 1.5, 300); 
		Robot.turnPID(88, 1, 300); //-4 Degrees
		Robot.drivePID(-32, 1.5, 1000);
		matchLoader.set_value(true); //Puts matchloader up
		mLoad.set_value(false); 


		Robot.drivePID(7, 1.5, 500);
		wing.set_value(false); 

		intakeLift.set_value(false); //Put intake lift down again
		

		Robot.turnPID(17, 1.5, 800); //-90 Degrees
		Robot.drivePID(12, 1, 550);
		Robot.turnPID(-85, 1.2, 700);  //-99 Degrees

		Robot.drivePID(86.5, 0.9, 3500); //Drive to other match loader
		Robot.turnPID(-180, 1, 900); //Turn 
		Robot.drivePID(12, 1, 800);

		Robot.turnPID(-90, 1, 800); //Turns to other goal and scores
		Robot.turnToGoal(2000); 
		Robot.drivePID(-15, 1, 1000); 

		intakeLift.set_value(true); 

		intakeLow.move_velocity(600);
		intakeUp.move_velocity(600); 

		pros::delay(2200); //Pause as we score (usually)
		Robot.turnPID(-90, 1, 1000); 

		intakeLift.set_value(false); //Puts down hood
		matchLoader.set_value(false); //Puts matchloader down again
		mLoad.set_value(true); 

		pros::delay(200); 

		intakeLow.move_velocity(600); 
		intakeUp.move_velocity(-20); 
		Robot.drivePID(45, 0.3, 1700);  //Drives forward for matchLoader

		Robot.drivePID(-5, 1, 400);
		pros::delay(400);

		Robot.drivePID(4, 1, 400); 
		

		pros::delay(1500); 

		//Drive Back and then realign (2nd matchloader)
		intakeLow.move_velocity(0); 
		intakeUp.move_velocity(-20);
		Robot.drivePID(-15, 1.5, 700); //Drives back and realigns
		Robot.turnPID(-90, 1, 1000);

		Robot.turnToGoal(2000); //Religns with Goal Again
		Robot.drivePID(-32, 1.2, 1000); //Backs up into goal
		intakeLift.set_value(true); //Lifts up hood 

		intakeLow.move_relative(-50, 100); 
		intakeLow.move_velocity(600); //Scores again
		intakeUp.move_velocity(600);

		pros::delay(2000); 
		matchLoader.set_value(true); //Puts matchloader up again
		mLoad.set_value(false); 


		intakeLow.move_velocity(0); 
		intakeUp.move_velocity(-20); 
		Robot.drivePID(6, 1, 500);
		intakeLift.set_value(false); //Puts down hood

		Robot.turnPID(-170, 1, 1000); 
		Robot.drivePID(105, 0.8, 4000); //Drive to 3rd loader

		Robot.turnPID(-90, 1, 1000); //Faces goal
		Robot.turnToGoal(2000); 

		Robot.drivePID(-30, 1, 1500); //Slams into goal to realign
		matchLoader.set_value(false); //Puts matchloader down again
		mLoad.set_value(true); 

		pros::delay(200);
		intakeLow.move_velocity(600); 
		intakeUp.move_velocity(-20); 
		Robot.drivePID(45, 0.3, 1500);  //Drives forward for matchLoader

		Robot.drivePID(-5, 1, 500);
		pros::delay(400);
		Robot.drivePID(3, 0.4, 400); 

		pros::delay(1500); 

		intakeLow.move_velocity(0); 
		intakeUp.move_velocity(-20);
		Robot.drivePID(-11, 1.1, 700); //Drives back and realigns

		matchLoader.set_value(true); //Puts matchloader up again
		mLoad.set_value(false); 
		Robot.turnPID(-90, 1, 1000);

		Robot.turnToGoal(2000); //Religns with Goal Again
		Robot.drivePID(-32, 1.2, 800); //Backs up into goal
		intakeLift.set_value(true); //Lifts up hood 

		intakeLow.move_relative(-50, 100); 
		//intakeLow.move_velocity(600); //Scores again
		//intakeUp.move_velocity(600);

		//pros::delay(2500);
		Robot.drivePID(10, 1, 800); //Moves away from the matchloader
		Robot.turnPID(-180, 1, 1000); 
		Robot.drivePID(16, 1, 1000); 
		Robot.turnPID(-265, 1, 1000); //Driving down the laaane

		Robot.drivePID(95, 1, 3000);
		Robot.turnPID(-360, 1, 1000); 
		Robot.drivePID(10, 1, 1000); 

		Robot.turnPID(-270, 1, 1300); //Faces goal
		Robot.turnToGoal(2000); 

		Robot.drivePID(-30, 1, 1500); //Slams into goal to realign
		intakeLow.move_velocity(600); 
		intakeUp.move_velocity(600); //Score
		intakeLift.set_value(true); //Lifts up hood 

		pros::delay(1500); 
		Robot.drivePID(20, 1, 1000); 
		Robot.drivePID(-5, 1, 500); 
		



}