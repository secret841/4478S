#pragma once
#include "main.h"

//Defining motors and controller
pros::Controller master(pros::E_CONTROLLER_MASTER);

pros::MotorGroup left_motor ({-14, -16, -20}, pros::MotorGearset::blue);
pros::MotorGroup right_motor({15, 2, 9}, pros::MotorGearset::blue); 

pros::Imu Inertial(3);

pros::ADIDigitalOut intakeLift('D');
pros::ADIDigitalOut intakeLift2('F'); 
pros::ADIDigitalOut wing('H'); 


pros::ADIDigitalOut mLoad('C');
pros::ADIDigitalOut matchLoader('A'); 

pros::ADIDigitalIn bumper('B'); 
pros::Distance distanceSensor(17); 

pros::Motor intakeLow(10, pros::MotorGearset::blue); 
pros::Motor intakeUp(-12, pros::MotorGearset::blue);
pros::Motor intakeRight(-2, pros::MotorGearset::blue); 
