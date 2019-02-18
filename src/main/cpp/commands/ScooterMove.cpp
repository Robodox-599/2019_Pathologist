/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ScooterMove.h"
#include "Robot.h"


ScooterMove::ScooterMove() {
  // Use Requires() here to declare subsystem dependencies
    Requires(&globalRobot.climbSystem);
}

// Called just before this Command runs the first time
void ScooterMove::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void ScooterMove::Execute() {
  if(globalRobot.climbSystem.GetClimbFlag() == true)
  {
    globalRobot.climbSystem.WheelSpin(globalRobot.oi.xbox->GetRawAxis(4));
  }
  frc::SmartDashboard::PutBoolean("Climb Flag", globalRobot.climbSystem.GetClimbFlag());
}

// Make this return true when this Command no longer needs to run execute()
bool ScooterMove::IsFinished() { return false; }

// Called once after isFinished returns true
void ScooterMove::End() {globalRobot.climbSystem.WheelSpin(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ScooterMove::Interrupted() {}