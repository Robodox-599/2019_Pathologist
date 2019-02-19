/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/DriveDefault.h"
#include "Robot.h"

DriveDefault::DriveDefault() {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  Requires(&globalRobot.driveSystem);
}

// Called just before this Command runs the first time
void DriveDefault::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void DriveDefault::Execute() 
{
  if(globalRobot.climbSystem.GetClimbFlag() == false)
  {
    globalRobot.driveSystem.JoystickVelocityDrive(globalRobot.oi.xbox->GetRawAxis(0), globalRobot.oi.xbox->GetRawAxis(1));
  }
  else
  {
    globalRobot.driveSystem.ClimbDrive(globalRobot.oi.xbox->GetRawAxis(4));
  }
  
}

// Make this return true when this Command no longer needs to run execute()
bool DriveDefault::IsFinished() { return false; }

// Called once after isFinished returns true
void DriveDefault::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveDefault::Interrupted() {}
