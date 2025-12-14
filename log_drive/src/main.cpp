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
int auton = 3; 
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
		pros::lcd::set_text(2, "One Block Long Goal (Mid Goal Side)"); 
	}
	else if (auton == 5)
	{
		pros::lcd::set_text(2, "One Block Long Goal (Low Goal Side)"); 
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
		//YOU HAVE 8878F's CONTROLLER
		pros::lcd::set_text(1, "Low Goal"); 

		intakeLow.move_velocity(600);
		intakeUp.move_velocity(-100);

		Robot.drivePID(15, 1, 1500);
		intakeLow.move_velocity(600);
		intakeUp.move_velocity(-50);

		Robot.drivePID(7, 0.75, 800); 
		Robot.drivePID(10, 1.2,1000); 
		Robot.turnPID(-70, 1, 1000); 

		Robot.drivePID(15, 1, 1000); 

		Robot.turnPID(-75, 0.9, 250);
		intakeLow.move_velocity(-600);

		pros::delay(1800); 

		Robot.drivePID(-5, 1, 500); 
		intakeLow.move_velocity(600); 

		//Score on Low Goal, move to Long
		Robot.drivePID(-52, 1, 2400); 
		Robot.turnPID(155, 0.8, 1500);

		Robot.drivePID(-35, 0.9, 1500);

		intakeLow.move_velocity(600); 
		intakeUp.move_velocity(600);
		pros::delay(2500); 

		Robot.drivePID(5, 0.2, 1000);

		pros::delay(300);

		//Swing Around
		right_motor.move_absolute(300, 400);
	
		
		//Score on High Goal
	
		
	

		/*
		intakeLow.move_velocity(600); 

		Robot.drivePID(7.5, 0.5, 2000);

		Robot.turnPID(-55, 1, 1500);

		Robot.drivePID(20, 1, 1000); 
		intakeLow.move_velocity(-600);
		
		pros::delay(1000);

		Robot.drivePID(-5, 1, 1000); 
		Robot.drivePID(5, 2, 1000);*/
	}

	//Mid Goal
	if (auton == 2)
	{
		//You have 8878F's Controller!
		pros::lcd::set_text(1, "Mid Goal"); 

		intakeLow.move_velocity(600);
		intakeUp.move_velocity(-100); 
		Robot.drivePID(19, 0.8, 2300);
		
		Robot.drivePID(9.5, 0.5, 2000);
		pros::delay(250);

		intakeLow.move_velocity(600); 

		//Robot.drivePID(9.5, 0.6, 1000);

		Robot.turnPID(-110, 0.85, 1800);

		//Drive towards mid goal
		Robot.drivePID(-21.5, 0.8, 1000); 

		//Back up a bit, then score
		Robot.drivePID(1.1, 0.9, 500); 
		pros::delay(300);
		intakeLow.move_velocity(600); 
		intakeUp.move_velocity(200); 

		pros::delay(800);
		intakeUp.move_velocity(0);  
		intakeLow.move_velocity(600); 

		//Drive back a bit, readjust angle, then drive more
		Robot.drivePID(18, 1, 900);
		Robot.turnPID(-100, 1, 800);

		Robot.drivePID(28.5, 1.2, 1800);

		//Turn to long goal and score
		Robot.turnPID(-169, 1.2, 900);
		Robot.drivePID(-18, 1, 1000);
		
		intakeLow.move_velocity(600);
		intakeUp.move_velocity(600); 

		pros::delay(2000); 
		Robot.drivePID(5, 0.2, 1000); 
	}

	if (auton == 3)
	{
		//BACKUP SKILLS 
		/*pros::lcd::set_text(1, "One Block + Park for Skills");
		Robot.drivePID(40, 0.3, 3500);
		Robot.turnPID(-90, 0.9, 2000);  
		Robot.drivePID(-35, 0.6, 1600);

		intakeLow.move_velocity(600); 
		intakeUp.move_velocity(600);

		pros::delay(10000); 

		Robot.drivePID(30, 0.5, 3000);
		Robot.turnPID(10, 0.9, 2000); 
		Robot.drivePID(-55, 1, 4000);
		Robot.turnPID(0, 1, 2000); 
		Robot.drivePID(-85, 1, 6000);*/

		//You have 8878F's Controller!
		pros::lcd::set_text(1, "Mid Goal"); 

		intakeLow.move_velocity(600);
		intakeUp.move_velocity(-100); 
		Robot.drivePID(19, 0.8, 2300);
		
		Robot.drivePID(9.5, 0.5, 2000);
		pros::delay(250);


		intakeLow.move_velocity(600); 

		//Robot.drivePID(9.5, 0.6, 1000);

		Robot.turnPID(-110, 0.85, 1800);

		//Drive towards mid goal
		Robot.drivePID(-21.5, 0.8, 1000); 

		//Back up a bit, then score
		Robot.drivePID(1.1, 0.9, 500); 
		pros::delay(300);
		intakeLow.move_velocity(600); 
		intakeUp.move_velocity(500); 

		pros::delay(1000);
		intakeUp.move_velocity(-50);  
		intakeLow.move_velocity(600); 

		Robot.drivePID(13, 1, 1000); 
		Robot.turnPID(125, 1, 1300);

		Robot.drivePID(30, 1, 2500);
		Robot.drivePID(12, 0.6, 1500); 

		//Offset about 33 degrees

		//Going to long goal on other side
		Robot.turnPID(165, 1, 1500); 
		Robot.drivePID(35, 1, 1800); 

		//Score on Long Goal
		Robot.turnPID(210, 1, 1800);
		Robot.drivePID(-50, 1, 1000); 

		intakeLow.move_velocity(600); 
		intakeUp.move_velocity(600); 

		pros::delay(7500);

		//Back up and Turn to Park
		Robot.drivePID(5, 0.2, 1000); 
		Robot.drivePID(15, 1, 1000); 
		Robot.turnPID(93, 1, 1300);
		Robot.drivePID(-45, 1, 2800);  

		Robot.turnPID(132, 1, 1200); 
		Robot.drivePID(-700, 2.5, 5500);
	}

	if (auton == 4)
	{
		pros::lcd::set_text(1, "One Block Long Goal Auto (Mid Goal Side)");

		//Drive, Turn, Drive towards Long Goal
		Robot.drivePID(40, 0.3, 3500);
		Robot.turnPID(-90, 0.9, 2000);  
		Robot.drivePID(-35, 0.6, 1600);

		//Outtake
		intakeLow.move_velocity(600); 
		intakeUp.move_velocity(600);

		pros::delay(3000); 
		Robot.drivePID(10, 0.5, 1000);
	}

	if (auton == 5)
	{
		pros::lcd::set_text(1, "One Block Long Goal Auto (Low Goal Side)");
		Robot.drivePID(40, 0.3, 3500);
		Robot.turnPID(90, 0.9, 2000);  
		Robot.drivePID(-35, 0.6, 1600);

		intakeLow.move_velocity(600); 
		intakeUp.move_velocity(600);
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
	bool reverse = false; 
	bool noMove = false; 
	bool latch = false; 

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
		}
		//Specific for mid-goal
		else if (master.get_digital(DIGITAL_L2))
		{
			intakeUp.move_velocity(150); 
		}
		else
		{
			intakeUp.move_velocity(-50);
		}


		
		
		pros::delay(20);                               // Run for 20 ms then update
	}
}