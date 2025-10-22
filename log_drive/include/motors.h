#pragma once
#include "main.h"

//Defining motors and controller
pros::Controller master(pros::E_CONTROLLER_MASTER);

pros::MotorGroup left_motor ({-1, -2, -3}, pros::MotorGearset::blue);
pros::MotorGroup right_motor({4, 12, 13}, pros::MotorGearset::blue); 

pros::Imu Inertial(5);

pros::Motor intakeLow(11, pros::MotorGearset::blue); 
pros::Motor intakeRight(-2, pros::MotorGearset::blue); 
