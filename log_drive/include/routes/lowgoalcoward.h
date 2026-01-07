#pragma once
#include "main.h"
#include "motors.h"
#include "robo_class.h"
#include "functions.h"

void lowGoalCoward()
{
    defineRobot Robot = defineRobot("4478S"); 
	
	//First three are drivePID, next three are turnPID
	Robot.setPID(1.1, 0, 0.56, 2.9, 0, 0.9); 
    Robot.drivePID(40, 0.3, 3500);
		Robot.turnPID(90, 0.9, 2000);  
		Robot.drivePID(-35, 0.6, 1600);

		intakeLow.move_velocity(600); 
		intakeUp.move_velocity(600);
}