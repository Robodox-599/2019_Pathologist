/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/HatchHook.h"
#include "Robot.h"

HatchHook::HatchHook() {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  Requires(&globalRobot.intakeSystem);
}

// Called just before this Command runs the first time
void HatchHook::Initialize() 
{
  if(globalRobot.intakeSystem.ReturnHatchFlag() == true)
  {
    globalRobot.intakeSystem.HatchHookIn();
  }
  else
  {
    globalRobot.intakeSystem.HatchHookOut();
  }
  
}

// Called repeatedly when this Command is scheduled to run
void HatchHook::Execute() {}

// Make this return true when this Command no longer needs to run execute()
bool HatchHook::IsFinished() { return true; }

// Called once after isFinished returns true
void HatchHook::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void HatchHook::Interrupted() {}
