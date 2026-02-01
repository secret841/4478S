
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
    
	//Low Goal Coward: Start = 90 Degrees
	Robot.drivePID(34.5, 1, 1500); 
	pros::delay(200);
		Robot.turnPID(92, 1, 1000); //+92 Degrees
		matchLoader.set_value(true); //Puts matchloader down
		mLoad.set_value(false); 
		wing.set_value(false); 
		pros::delay(300); 

		intakeLow.move_velocity(600); //Turn on intake(s)
		intakeUp.move_velocity(-100);

		Robot.drivePID(13, 0.85, 1000); //Drive to loader
		 
		Robot.drivePID(-2, 1, 200); //Drive Back a bit
		//Wiggle
		Robot.drivePID(5, 0.4, 400); 
		Robot.drivePID(5, 0.4, 400);
		Robot.drivePID(5, 0.4, 400);

		pros::delay(1300); 

		//Drive Back and then realign
		intakeUp.move_velocity(-100);
		intakeUp.move_velocity(-100); 
		intakeLow.move_velocity(0); 

		Robot.drivePID(-5, 1.5, 300); 
		Robot.turnPID(88, 1, 300); //-4 Degrees
		Robot.drivePID(-32, 1.5, 1100);
		matchLoader.set_value(false); //Puts matchloader up
		mLoad.set_value(true); 


		Robot.drivePID(7, 1.5, 500);
		wing.set_value(false); 

		intakeLift.set_value(false); //Put intake lift down again
		

		Robot.turnPID(17, 1.5, 800); //-90 Degrees
		Robot.drivePID(12, 1, 550);
		Robot.turnPID(-85, 1.2, 700);  //-99 Degrees

		Robot.drivePID(85, 0.9, 4000); //Drive to other match loader
		Robot.turnPID(-180, 1, 1000); //Turn 
		Robot.drivePID(12, 1, 1200);

		Robot.turnPID(-90, 1, 1000); //Turns to other goal and scores
		Robot.turnToGoal(2000); 
		Robot.drivePID(-15, 1, 1000); 

		intakeLift.set_value(true); 

		intakeLow.move_relative(-50, 200); //Outake a little bit

		intakeLow.move_velocity(600);
		intakeUp.move_velocity(600); 

		pros::delay(2200); //Pause as we score (usually)
		Robot.turnPID(-90, 1, 1000); 

		intakeLift.set_value(false); //Puts down hood
		matchLoader.set_value(true); //Puts matchloader down again
		mLoad.set_value(false); 

		intakeLow.move_velocity(600); 
		intakeUp.move_velocity(-100); 
		Robot.drivePID(32, 0.6, 1500);  //Drives forward for matchLoader

		Robot.drivePID(-2, 1, 300);

		Robot.drivePID(5, 0.4, 400); 
		Robot.drivePID(5, 0.4, 400);
		Robot.drivePID(5, 0.4, 400);

		pros::delay(1500); 

		//Drive Back and then realign (2nd matchloader)
		intakeLow.move_velocity(0); 
		intakeUp.move_velocity(-100);
		Robot.drivePID(-15, 1.5, 700); //Drives back and realigns
		Robot.turnPID(-90, 1, 1000);

		Robot.turnToGoal(2000); //Religns with Goal Again
		Robot.drivePID(-32, 1.2, 1000); //Backs up into goal
		intakeLift.set_value(true); //Lifts up hood 

		intakeLow.move_relative(-50, 100); 
		intakeLow.move_velocity(600); //Scores again
		intakeUp.move_velocity(600);

		pros::delay(2500); 
		matchLoader.set_value(false); //Puts matchloader up again
		mLoad.set_value(true); 


		intakeLow.move_velocity(0); 
		intakeUp.move_velocity(-50); 
		Robot.drivePID(6, 1, 500);
		intakeLift.set_value(false); //Puts down hood

		Robot.turnPID(-170, 1, 1500); 
		Robot.drivePID(105, 0.8, 5500); //Drive to 3rd loader

		Robot.turnPID(-90, 1, 1300); //Faces goal
		Robot.turnToGoal(2000); 

		Robot.drivePID(-30, 1, 1500); //Slams into goal to realign
		matchLoader.set_value(true); //Puts matchloader down again
		mLoad.set_value(false); 

		intakeLow.move_velocity(600); 
		intakeUp.move_velocity(-100); 
		Robot.drivePID(32, 0.6, 1500);  //Drives forward for matchLoader

		Robot.drivePID(-2, 1, 300);

		Robot.drivePID(5, 0.4, 400); 
		Robot.drivePID(5, 0.4, 400);
		Robot.drivePID(5, 0.4, 400);

		pros::delay(1500); 

		intakeLow.move_velocity(0); 
		intakeUp.move_velocity(-100);
		Robot.drivePID(-11, 1.1, 700); //Drives back and realigns
		Robot.turnPID(-90, 1, 1000);

		Robot.turnToGoal(2000); //Religns with Goal Again
		Robot.drivePID(-32, 1.2, 1000); //Backs up into goal
		intakeLift.set_value(true); //Lifts up hood 

		intakeLow.move_relative(-50, 100); 
		intakeLow.move_velocity(600); //Scores again
		intakeUp.move_velocity(600);

		pros::delay(2500);

}