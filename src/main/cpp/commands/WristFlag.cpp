/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/WristFlag.h"
#include "Robot.h"

WristFlag::WristFlag() {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void WristFlag::Initialize() 
{
  if(globalRobot.wristSystem.GetWristFlag())
  {
    globalRobot.wristSystem.SetWristFlagFalse();
  }
  else
  {
    globalRobot.wristSystem.SetWristFlagTrue();
  }
  
}

// Called repeatedly when this Command is scheduled to run
void WristFlag::Execute() {}

// Make this return true when this Command no longer needs to run execute()
bool WristFlag::IsFinished() 
{
  if(globalRobot.wristSystem.GetWristFlag())
  {
    return globalRobot.wristSystem.GetWristFlag();
  }
  else
  {
    return !globalRobot.wristSystem.GetWristFlag();
  }
  
}

// Called once after isFinished returns true
void WristFlag::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void WristFlag::Interrupted() {}
