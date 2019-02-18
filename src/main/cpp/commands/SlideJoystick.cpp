/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/SlideJoystick.h"
#include "Robot.h"

SlideJoystick::SlideJoystick() {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  Requires(&globalRobot.slideSystem);
}

// Called just before this Command runs the first time
void SlideJoystick::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void SlideJoystick::Execute()
  {
    globalRobot.slideSystem.MotionMagicJoystickControl(globalRobot.oi.xbox->GetRawAxis(4));
  }

// Make this return true when this Command no longer needs to run execute()
bool SlideJoystick::IsFinished() { return false; }

// Called once after isFinished returns true
void SlideJoystick::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SlideJoystick::Interrupted() {}
