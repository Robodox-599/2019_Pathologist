/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/WristReconfig.h"
#include "Robot.h"

WristReconfig::WristReconfig() {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  Requires(&globalRobot.wristSystem);
}

// Called just before this Command runs the first time
void WristReconfig::Initialize() 
{
  globalRobot.wristSystem.SetResetFlagFalse();
  globalRobot.wristSystem.ResetWristConfig();
}

// Called repeatedly when this Command is scheduled to run
void WristReconfig::Execute() {}

// Make this return true when this Command no longer needs to run execute()
bool WristReconfig::IsFinished() { return globalRobot.wristSystem.ReturnResetFlag(); }

// Called once after isFinished returns true
void WristReconfig::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void WristReconfig::Interrupted() {}
