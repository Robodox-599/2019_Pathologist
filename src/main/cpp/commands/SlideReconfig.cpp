/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/SlideReconfig.h"
#include "Robot.h"

SlideReconfig::SlideReconfig() {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  Requires(&globalRobot.slideSystem);
}

// Called just before this Command runs the first time
void SlideReconfig::Initialize() 
{
  globalRobot.slideSystem.SetResetFlagFalse();
  globalRobot.slideSystem.ResetSlideConfig();
}

// Called repeatedly when this Command is scheduled to run
void SlideReconfig::Execute() {}

// Make this return true when this Command no longer needs to run execute()
bool SlideReconfig::IsFinished() { return globalRobot.slideSystem.ReturnResetFlag(); }

// Called once after isFinished returns true
void SlideReconfig::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SlideReconfig::Interrupted() {}
