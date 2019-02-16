/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/AllPistonsDown.h"
#include "Robot.h"

AllPistonsDown::AllPistonsDown()
{
  // Use Requires() here to declare subsystem dependencies
  Requires(&globalRobot.climbSystem);
}

// Called just before this Command runs the first time
void AllPistonsDown::Initialize()
{
  globalRobot.climbSystem.LeftPistonExpand();
  globalRobot.climbSystem.RightPistonExpand();
  globalRobot.climbSystem.RearPistonExpand();
  globalRobot.climbSystem.SetClimbFlagTrue();
}

// Called repeatedly when this Command is scheduled to run
void AllPistonsDown::Execute()
{
}

// Make this return true when this Command no longer needs to run execute()
bool AllPistonsDown::IsFinished() { return globalRobot.climbSystem.GetClimbFlag(); }

// Called once after isFinished returns true
void AllPistonsDown::End()
{
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AllPistonsDown::Interrupted() {}
