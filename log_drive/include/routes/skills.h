
#pragma once
#include "main.h"
#include "motors.h"
#include "robo_class.h"
#include "functions.h"

//REMOVE ALL MLOADS!
void skills()
{
	 defineRobot Robot = defineRobot("4478S"); 
	
	//First three are drivePID, next three are turnPID
	Robot.setPID(0.85, 0, 0.15, 2.2, 0, 0.93); 

	matchLoader.set_value(false); //Puts matchloader down
    
	//Low Goal Coward: Start = 90 Degrees
	Robot.drivePID(34, 1, 1500); 
	pros::delay(200);
		Robot.turnPID(93, 1, 1100); //+92 Degrees
		 
		wing.set_value(false); 
		pros::delay(300); 

		intakeLow.move_velocity(600); //Turn on intake(s)
		intakeUp.move_velocity(-20);

		intakeLow.move_velocity(600); //Turn on intake(s)
		Robot.drivePID(23.5, 0.08, 1500); //Drive to loader
		pros::delay(1500);
		Robot.drivePID(6.5, 0.1, 400);
		 
		intakeLow.move_velocity(600); //Turn on intake(s)
		intakeLow.move_velocity(600); //Turn on intake(s)
		pros::delay(1500); 

		//Drive Back and then realign
		intakeUp.move_velocity(-10); 
		intakeLow.move_velocity(600); 

		Robot.drivePID(-5, 1.5, 300); 
		Robot.turnPID(88, 1, 300); //-4 Degrees
		Robot.drivePID(-32, 1.5, 1000);
		matchLoader.set_value(true); //Puts matchloader up

		Robot.drivePID(7, 1.5, 500);
		wing.set_value(false); 

		intakeLift.set_value(false); //Put intake lift down again
		

		Robot.turnPID(17, 1.5, 800); //-90 Degrees
		Robot.drivePID(12, 1, 550);
		Robot.turnPID(-84, 1.2, 700);  //-99 Degrees

		Robot.drivePID(86.5, 0.85, 3000); //Drive to other match loader
		Robot.turnPID(-180, 1, 900); //Turn 
		Robot.drivePID(12, 1, 800);

		Robot.turnPID(-90, 1, 800); //Turns to other goal and scores
		Robot.turnToGoal(2000); 
		Robot.drivePID(-15, 0.8, 1000); 

		intakeLift.set_value(true); 

		intakeUp.move_velocity(600); 
		intakeLow.move_velocity(600);

		pros::delay(1000); 
		intakeLow.move_velocity(600); 

		pros::delay(1000); //Pause as we score (usually)
		Robot.turnPID(-91, 1, 800); 

		//intakeLift.set_value(false); //Puts down hood
		matchLoader.set_value(false); //Puts matchloader down again

		pros::delay(200); 
		intakeLow.move_velocity(600); 
		intakeUp.move_velocity(-20); 
		Robot.drivePID(28, 0.6, 1000); 
		Robot.turnPID(-92.5, 1, 200); //Readjustment turn
		Robot.drivePID(20.5, 0.08, 1700);  //Drives forward for matchLoader
		intakeLow.move_velocity(600);
		pros::delay(600);
		Robot.drivePID(3, 0.1, 300); 

		pros::delay(1500); 

		//Drive Back and then realign (2nd matchloader)
		intakeLow.move_velocity(300); 
		intakeUp.move_velocity(-20);
		
		Robot.drivePID(-15, 1.5, 700); //Drives back and realigns
		Robot.turnPID(-96.5, 1, 800);

		
		Robot.turnToGoal(2000); //Religns with Goal Again
		Robot.drivePID(-32, 0.8, 1200); //Backs up into goal
		Robot.drivePID(-10, 0.5, 500); //Backs up into goal		

		intakeUp.move_velocity(600);
		intakeLow.move_velocity(600); //Scores again
		

		intakeLift.set_value(true); //Puts hood up
		pros::delay(2000); 
		matchLoader.set_value(true); //Puts matchloader up again


		intakeLow.move_velocity(0); 
		intakeUp.move_velocity(-20); 
		Robot.drivePID(6, 1, 500);
		intakeLift.set_value(true); //Puts hood up

		Robot.turnPID(-170, 1, 1000); 

		//DELAYYYYYYY
		pros::delay(20000); 
//Test code


		Robot.drivePID(105, 0.8, 4000); //Drive to 3rd loader

		Robot.turnPID(-90, 1, 1000); //Faces goal
		Robot.turnToGoal(2000); 

		Robot.drivePID(-30, 1, 1500); //Slams into goal to realign
		matchLoader.set_value(false); //Puts matchloader down again

		pros::delay(200);
		intakeLow.move_velocity(600); 
		intakeUp.move_velocity(-20); 
		Robot.turnPID(-92, 1, 300); //Faces goal
		Robot.drivePID(45.5, 0.3, 1500);  //Drives forward for matchLoader - MAKE ALL MATCHLOADER STUFF SLOWER!

		Robot.drivePID(-3, 1, 500);
		pros::delay(400);
		Robot.drivePID(5.5, 1, 400);

		pros::delay(1500); 

		intakeLow.move_velocity(0); 
		intakeUp.move_velocity(-20);
		Robot.drivePID(-11, 1.1, 700); //Drives back and realigns

		matchLoader.set_value(true); //Puts matchloader up again
		Robot.turnPID(-90, 1, 1000);

		Robot.turnToGoal(2000); //Religns with Goal Again
		Robot.drivePID(-32, 1, 800); //Backs up into goal
		intakeLift.set_value(true); //Lifts up hood 

		intakeLow.move_relative(-50, 100); 
		//intakeLow.move_velocity(600); //Scores again
		//intakeUp.move_velocity(600);

		//pros::delay(2500);
		Robot.drivePID(10, 1, 800); //Moves away from the matchloader
		Robot.turnPID(-180, 1, 1000); 
		Robot.drivePID(18, 1, 1000); 
		Robot.turnPID(-265, 1, 1000); //Driving down the laaane

		Robot.drivePID(95, 1, 3000);
		Robot.turnPID(-360, 1, 1000); 
		Robot.drivePID(10, 1, 800); 

		Robot.turnPID(-270, 1, 1300); //Faces goal
		Robot.turnToGoal(2000); 

		Robot.drivePID(-30, 1, 1500); //Slams into goal to realign
		intakeLow.move_velocity(600); 
		intakeUp.move_velocity(600); //Score
		intakeLift.set_value(true); //Lifts up hood 

		pros::delay(1500); 
		Robot.drivePID(20, 1, 1000); 

		Robot.turnPID(-359, 1, 1000); 
		Robot.drivePID(30, 1.2, 800); 
		Robot.turnPID(-270, 1.2, 800); 
		Robot.drivePID(30, 1.2, 1000); //Drive into goal
		Robot.drivePID(-5, 1, 500); 
		



}