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
int auton = 0; 
void on_center_button() {
	auton++; 

	switch (auton)
	{
		case 1: 
			pros::lcd::set_text(2, "Auton #1");
		case 2:
			pros::lcd::set_text(2, "Auton #2"); 
		case 3:
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
	//Robot.setPID(1.5, 0, 0.5, 0.5, 0.3, 0.2); 
	//Robot.drivePID(20, 0.5, 2000);
	//First three are drivePID, next three are turnPID
	
	//pros::delay(2000);

	intakeLow.move_velocity(-600);
  left_motor.move_relative(2450, 110);
  right_motor.move_relative(2450, 110);

  

  pros::delay(2800);

  left_motor.move_relative(-250, 100);
  right_motor.move_relative(-250, 100);

  pros::delay(1700); 

   left_motor.move_relative(-350, 50);
  right_motor.move_relative(350, 50);

  pros::delay(2000); 
  intakeLow.move_velocity(0);

    left_motor.move_relative(2100, 100);
  right_motor.move_relative(2100, 100);

  pros::delay(2000); 
  

    left_motor.move_relative(-250, 100);
  right_motor.move_relative(-250, 100);

  pros::delay(1000);
   intakeLow.move_velocity(600);

   pros::delay(500); 

    left_motor.move_relative(-15, 80);
  right_motor.move_relative(15, 80);

   pros::delay(1000); 

      
    left_motor.move_relative(-500, 100);
  right_motor.move_relative(-500, 100);
  intakeLow.move_velocity(600);
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
			//Brake Motors
			left_motor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD); 
			right_motor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD); 

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
			//Brake Motors
			intakeLow.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD); 
			intakeLow.move_velocity(0); 
		}
		

	
		pros::delay(20);                               // Run for 20 ms then update
	}
}