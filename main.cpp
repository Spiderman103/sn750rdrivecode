#include "main.h"

pros::Controller master(pros::E_CONTROLLER_MASTER);

pros::Motor left_mtr1(10, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor left_mtr2(9, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor left_mtr3(8, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor right_mtr1(1, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor right_mtr2(2, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor right_mtr3(3, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES);

pros::Motor intake_mtr(11, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);

pros::Motor cata_mtr(6, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);

pros::ADIDigitalOut wings('A');

void initialize() {

}

void disabled() {
    
}

void competition_initialize() {
    
}

void autonomous() {
    
}

void opcontrol() {
    while (true) {
        int forward = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
        int turn = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);

		// Drive
        int left_power = forward + turn;
        int right_power = forward - turn;

        if (left_power > 127) {
            left_power = 120;
        } else if (left_power < -127) {
            left_power = -120;
        }
        if (right_power > 127) {
            right_power = 120;
        } else if (right_power < -127) {
            right_power = -120;
        }

        left_mtr1.move_velocity(left_power);
        left_mtr2.move_velocity(left_power);
        left_mtr3.move_velocity(left_power);
        right_mtr1.move_velocity(right_power);
        right_mtr2.move_velocity(right_power);
        right_mtr3.move_velocity(right_power);

        int intake_speed = 0;
        if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
            intake_speed = 120;
        } else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
            intake_speed = -120;
        }
        intake_mtr.move_velocity(intake_speed);

        // Cata 
        int cata_speed = 0;
        if (master.get_digital(pros::E_CONTROLLER_DIGITAL_A)) {
            cata_speed = 120;
        }
        cata_mtr.move_velocity(cata_speed);

        // Wings
        if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B)) {
            wings.set_value(!wings.get_value());
        }

        pros::delay(20); 
    }
}
