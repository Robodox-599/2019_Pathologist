/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/RearPistonUp.h"
#include "Robot.h"
 
RearPistonUp::RearPistonUp() {
  // Use Requires() here to declare subsystem dependencies
    Requires(&globalRobot.climbSystem);
}

// Called just before this Command runs the first time
void RearPistonUp::Initialize()  {globalRobot.climbSystem.RearPistonRetract();}

// Called repeatedly when this Command is scheduled to run
void RearPistonUp::Execute() {
}

// Make this return true when this Command no longer needs to run execute()
bool RearPistonUp::IsFinished() { return false; }

// Called once after isFinished returns true
void RearPistonUp::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RearPistonUp::Interrupted() {}
