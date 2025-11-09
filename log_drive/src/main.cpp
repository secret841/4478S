#pragma once
#include "main.h"
#include "motors.h"
#include "robo_class.h"
#include "functions.h"


/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
int auton = 2; 
void on_center_button() {
	auton++; 
	
	
	if (auton == 1)
	{
		pros::lcd::set_text(2, "Low Goal Auton");
	}
	else if (auton == 2)
	{
		pros::lcd::set_text(2, "Mid Goal Auton");
	}
	else if (auton == 3)
	{
		pros::lcd::set_text(2, "Skills Auton"); 
	}
	else
	{
		pros::lcd::clear_line(2);
		auton = 0; 
	}

}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	//Resets motors
	left_motor.set_zero_position(0); 
	right_motor.set_zero_position(0); 

	Inertial.reset();


	pros::lcd::initialize();
	pros::lcd::set_text(1, "Hello PROS User!");

	pros::lcd::register_btn1_cb(on_center_button);
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol  
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
	defineRobot Robot = defineRobot("4478S"); 
	
	//First three are drivePID, next three are turnPID
	Robot.setPID(1.1, 0, 0.56, 2.9, 0, 0.6); 
	 
	/*Robot.drivePID(20, 1, 2000);
	Robot.drivePID(-15, 0.8, 2000);*/
	/*Robot.turnPID(90, 1, 2000);
	Robot.turnPID(0, 1, 2000);*/

	//Low Goal
	if (auton == 1)
	{
		pros::lcd::set_text(1, "Low Goal"); 
		Robot.drivePID(16, 1, 2000);
		intakeLow.move_velocity(400);

		Robot.drivePID(10, 0.7, 2000);
		intakeLow.move_velocity(0); 

		Robot.drivePID(7.5, 0.5, 2000);

		Robot.turnPID(-55, 1, 1500);

		Robot.drivePID(20, 1, 1000); 
		intakeLow.move_velocity(-600); 

		Robot.drivePID(-5, 1, 1000); 
		Robot.drivePID(5, 2, 1000);
	}

	//Mid Goal
	if (auton == 2)
	{
		pros::lcd::set_text(1, "Mid Goal"); 
		Robot.drivePID(19.5, 1, 2200);
		intakeLow.move_velocity(500);

		Robot.drivePID(8, 0.75, 2000);
		pros::delay(450);

		intakeLow.move_velocity(100); 

		Robot.drivePID(9, 0.5, 2000);

		Robot.turnPID(-105, 0.8, 2200);

		Robot.drivePID(-22.5, 1, 1000); 
		intakeLow.move_velocity(600); 

		pros::delay(2000); 
		intakeLow.move(127); 

		Robot.drivePID(5, 1, 1000); 
		Robot.drivePID(-4, 1, 1000);
		intakeLow.move_relative(-50, 30); 
		pros::delay(50);
		intakeLow.move_velocity(-100);
		pros::delay(100); 
		intakeLow.move_velocity(600);
		intakeLow.move_velocity(600);
		intakeLow.move_velocity(600);
	}

	//Skills
	if (auton == 3)
	{
		pros::lcd::set_text(1, "Skills"); 
		Robot.drivePID(10, 1, 2000);
		Robot.turnPID(10, 1, 1000);
		Robot.drivePID(-55, 5, 2000);
	}
	 
	//Robot.drivePID(-10, 1, 2000);
	
	//pros::delay(2000);
}



/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
	double left, right; 
	bool moveIntake = false;

	intakeLow.move_velocity(0); 
	while (true) {
		//Log Drive
		left = master.get_analog(ANALOG_LEFT_Y); 
		right = master.get_analog(ANALOG_RIGHT_Y);

		double leftLog = (left * left) / 127; 
		double rightLog = (right * right) / 127; 
		

		if (fabs(leftLog) >= 0.8 || fabs(rightLog) >= 0.8)
		{
			if (left < 0)
				leftLog = -leftLog;
			if (right < 0)
				rightLog = -rightLog; 
		
			left_motor.move(leftLog); 
			right_motor.move(rightLog); 
		}
		else
		{
			left_motor.move_velocity(0); 
			right_motor.move_velocity(0); 

		}
		
		//Intake
		if (master.get_digital(DIGITAL_R1))
		{
			intakeLow.move_velocity(600);  
		}
		else if (master.get_digital(DIGITAL_R2))
		{
			intakeLow.move_velocity(-600); 
		}
		else
		{
			intakeLow.move_velocity(0);
		}

		
		
		pros::delay(20);                               // Run for 20 ms then update
	}
}