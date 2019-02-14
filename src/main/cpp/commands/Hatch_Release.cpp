/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Hatch_Release.h"
#include "Robot.h"
Hatch_Release::Hatch_Release() {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
    Requires(&globalRobot.intakeSystem);
}

// Called just before this Command runs the first time
void Hatch_Release::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void Hatch_Release::Execute() 
{
  globalRobot.intakeSystem.HatchPistonsForward();
}

// Make this return true when this Command no longer needs to run execute()
bool Hatch_Release::IsFinished() { return false; }

// Called once after isFinished returns true
void Hatch_Release::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Hatch_Release::Interrupted() {}
