/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/FrontPistonsUp.h"
#include "Robot.h"

FrontPistonsUp::FrontPistonsUp() {
  // Use Requires() here to declare subsystem dependencies
     Requires(&globalRobot.climbSystem);
}

// Called just before this Command runs the first time
void FrontPistonsUp::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void FrontPistonsUp::Execute() {
  globalRobot.climbSystem.LeftPistonRetract();
  globalRobot.climbSystem.RightPistonRetract();
}

// Make this return true when this Command no longer needs to run execute()
bool FrontPistonsUp::IsFinished() { return false; }

// Called once after isFinished returns true
void FrontPistonsUp::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void FrontPistonsUp::Interrupted() {}
