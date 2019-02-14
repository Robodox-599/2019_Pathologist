/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/AllPistonsDown.h"
#include "Robot.h"

AllPistonsDown::AllPistonsDown() {
  // Use Requires() here to declare subsystem dependencies
     Requires(&globalRobot.climbSystem);

}

// Called just before this Command runs the first time
void AllPistonsDown::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void AllPistonsDown::Execute() {
  globalRobot.climbSystem.LeftPistonExpand();
  globalRobot.climbSystem.RightPistonExpand();
  globalRobot.climbSystem.RearPistonExpand();
}

// Make this return true when this Command no longer needs to run execute()
bool AllPistonsDown::IsFinished() { return false; }

// Called once after isFinished returns true
void AllPistonsDown::End() {
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AllPistonsDown::Interrupted() {}
