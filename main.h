#ifndef _PROS_MAIN_H_
#define _PROS_MAIN_H_
#define PROS_USE_SIMPLE_NAMES
#define PROS_USE_LITERALS


#include "api.h"

extern pros::Controller master;

extern pros::Motor left_mtr1;
extern pros::Motor left_mtr2;
extern pros::Motor left_mtr3;
extern pros::Motor right_mtr1;
extern pros::Motor right_mtr2;
extern pros::Motor right_mtr3;

extern pros::Motor intake_mtr;

extern pros::Motor cata_mtr;

extern pros::ADIDigitalOut wings;

#ifdef __cplusplus
extern "C" {
#endif

void initialize();
void disabled();
void competition_initialize();
void autonomous();
void opcontrol();

#ifdef __cplusplus
}
#endif

#endif  
