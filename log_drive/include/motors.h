#pragma once
#include "main.h"

//Defining motors and controller
pros::Controller master(pros::E_CONTROLLER_MASTER);

pros::MotorGroup left_motor ({1, 2, 3});
pros::MotorGroup right_motor({-4, -5, -6}); 

pros::Motor intakeLeft(1, pros::MotorGearset::blue); 
pros::Motor intakeRight(-2, pros::MotorGearset::blue); 
