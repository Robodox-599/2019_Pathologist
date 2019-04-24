/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/WristAdjustment.h"
#include "Robot.h"

WristAdjustment::WristAdjustment(double degrees) {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  Requires(&globalRobot.wristSystem);

  adjustment = degrees;
}

// Called just before this Command runs the first time
void WristAdjustment::Initialize() 
{
  globalRobot.wristSystem.MotionMagicDegrees(globalRobot.wristSystem.GetCurrentDegrees()+adjustment);
}

// Called repeatedly when this Command is scheduled to run
void WristAdjustment::Execute() {}

// Make this return true when this Command no longer needs to run execute()
bool WristAdjustment::IsFinished() { return false; }

// Called once after isFinished returns true
void WristAdjustment::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void WristAdjustment::Interrupted() {}
