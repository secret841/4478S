#pragma once
#include "main.h"
#include "motors.h"
#include "robo_class.h"
#include "functions.h"
#include "routes/lowgoal.h"
#include "routes/midgoal.h"
#include "routes/skills.h"
#include "routes/midgoalcoward.h"
#include "routes/lowgoalcoward.h"


/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
int auton = 4; 
void on_center_button() {
	auton++; 
	
	
	if (auton == 1)
	{
		pros::lcd::set_text(2, "Main Low Goal Auton");
	}
	else if (auton == 2)
	{
		pros::lcd::set_text(2, "Main Mid Goal Auton");
	}
	else if (auton == 3)
	{
		pros::lcd::set_text(2, "Skills Auton (One Block + Park)"); 
	}
	else if (auton == 4)
	{
		pros::lcd::set_text(2, "Mid Goal Coward"); 
	}
	else if (auton == 5)
	{
		pros::lcd::set_text(2, "Low Goal Coward"); 
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

	//Puts wing down
	wing.set_value(false); 
	matchLoader.set_value(false);

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
	//defineRobot Robot = defineRobot("4478S"); 
	
	//First three are drivePID, next three are turnPID
	//Robot.setPID(1.1, 0, 0.56, 2.9, 0, 0.9); 

	//TRUE MAKES WING GO DOWN! wing.set_value(true); 

	//Low Goal
	if (auton == 1)
	{
		pros::lcd::set_text(1, "Low Goal"); 
		lowgoal(); 	
	}

	//Mid Goal
	if (auton == 2)
	{
		pros::lcd::set_text(1, "Mid Goal"); 

		midgoal(); 
	}

	if (auton == 3)
	{
		pros::lcd::set_text(1, "Skills Auton"); 

		skills();
	}

	if (auton == 4)
	{
		pros::lcd::set_text(1, "Mid Goal Coward");
		pros::lcd::print(2, "%.2f", Inertial.get_heading());
		midgoalcoward(); 
	}

	if (auton == 5)
	{
		pros::lcd::set_text(1, "Low Goal Coward");
		lowGoalCoward(); 
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
	bool matchLoad = false; 
	bool moveIntake = false;
	bool reverse = false; 
	bool noMove = false; 
	bool latch = false; 
	bool wingy = true;
	bool lift = true; 

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

		//Old Code in case the driver Changes Her Mind 
		/*
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
		*/
		
		//Intake Toggle
		if (master.get_digital_new_press(DIGITAL_R1))
		{
			moveIntake = !moveIntake; 
			reverse = false; 
		}
		if (master.get_digital_new_press(DIGITAL_R2))
		{
			reverse = !reverse; 
			moveIntake = false; 
		}
		
		//Spin reverse, forward, and not at all respectively
		if (reverse)
		{
			intakeLow.move_velocity(-600); 
		}
		else if (moveIntake)
		{
			intakeLow.move_velocity(600); 
		}
		else
		{
			intakeLow.move_velocity(0); 
		}

		//Code for the upper intake
		if (master.get_digital(DIGITAL_L1))
		{
			intakeUp.move_velocity(600);
			lift = true;  
		}
		//Specific for mid-goal
		else if (master.get_digital(DIGITAL_L2))
		{
			intakeUp.move_velocity(150); 
		}
		else
		{
			intakeUp.move_velocity(-50);
			lift = false; 
		}

		
		//Control Wing 
		if (master.get_digital_new_press(DIGITAL_A))
		{
			wingy = !wingy; 
		}
		if (wingy)
		{
			wing.set_value(true);
		}
		else
		{
			wing.set_value(false);
		}

		if (master.get_digital_new_press(DIGITAL_B))
		{
			lift = !lift; 
		}
		if (lift)
		{
			intakeLift.set_value(true);
		}
		else
		{
			intakeLift.set_value(false);
		}


		if (master.get_digital_new_press(DIGITAL_UP))
		{
			matchLoad = !matchLoad; 
		}
		if (matchLoad)
		{
			matchLoader.set_value(true);
		}
		else
		{
			matchLoader.set_value(false);
		}


		
		
		pros::delay(20);                               // Run for 20 ms then update
	}
}