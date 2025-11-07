#pragma once
#include "main.h"

//Defining motors and controller
pros::Controller master(pros::E_CONTROLLER_MASTER);

pros::MotorGroup left_motor ({-10, -19, -20}, pros::MotorGearset::blue);
pros::MotorGroup right_motor({1, 13, 12}, pros::MotorGearset::blue); 

pros::Imu Inertial(4);

pros::Motor intakeLow(5, pros::MotorGearset::blue); 
pros::Motor intakeRight(-2, pros::MotorGearset::blue); 
