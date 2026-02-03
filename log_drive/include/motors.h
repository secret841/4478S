#pragma once
#include "main.h"

//Defining motors and controller
pros::Controller master(pros::E_CONTROLLER_MASTER);

pros::MotorGroup left_motor ({-10, -19, -20}, pros::MotorGearset::blue);
pros::MotorGroup right_motor({1, 15, 12}, pros::MotorGearset::blue); 

pros::Imu Inertial(4);

pros::ADIDigitalOut intakeLift('B');
pros::ADIDigitalOut intakeLift2('C'); 
pros::ADIDigitalOut wing('A'); 


pros::ADIDigitalOut mLoad('F');
pros::ADIDigitalOut matchLoader('G'); 

pros::Distance distanceSensor(6); 

pros::Motor intakeLow(3, pros::MotorGearset::blue); 
pros::Motor intakeUp(-5, pros::MotorGearset::blue);
pros::Motor intakeRight(-2, pros::MotorGearset::blue); 
