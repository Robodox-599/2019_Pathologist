/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ClimbPistonsUp.h"
#include "Robot.h"

ClimbPistonsUp::ClimbPistonsUp() {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  Requires(&globalRobot.climbSystem);
}

// Called just before this Command runs the first time
void ClimbPistonsUp::Initialize() 
{
  globalRobot.climbSystem.RearPistonRetract();
  globalRobot.climbSystem.LeftPistonRetract();
  globalRobot.climbSystem.RightPistonRetract();
  globalRobot.climbSystem.SetClimbFlagFalse();
}

// Called repeatedly when this Command is scheduled to run
void ClimbPistonsUp::Execute() {}

// Make this return true when this Command no longer needs to run execute()
bool ClimbPistonsUp::IsFinished() { return true; }

// Called once after isFinished returns true
void ClimbPistonsUp::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ClimbPistonsUp::Interrupted() {}
