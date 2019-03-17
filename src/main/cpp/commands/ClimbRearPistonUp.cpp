/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ClimbRearPistonUp.h"
#include "Robot.h"
 
ClimbRearPistonUp::ClimbRearPistonUp() {
  // Use Requires() here to declare subsystem dependencies
    Requires(&globalRobot.climbSystem);
}

// Called just before this Command runs the first time
void ClimbRearPistonUp::Initialize()  
{
  globalRobot.climbSystem.RearPistonRetract();
  globalRobot.climbSystem.SetClimbFlagFalse();
  globalRobot.driveSystem.SetDriveFlagTrue();
}

// Called repeatedly when this Command is scheduled to run
void ClimbRearPistonUp::Execute() {
}

// Make this return true when this Command no longer needs to run execute()
bool ClimbRearPistonUp::IsFinished() { return false; }

// Called once after isFinished returns true
void ClimbRearPistonUp::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ClimbRearPistonUp::Interrupted() {}
