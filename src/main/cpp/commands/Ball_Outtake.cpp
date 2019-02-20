/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Ball_Outtake.h" 
#include "Robot.h"
Ball_Outtake::Ball_Outtake(float speed) {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  Requires(&globalRobot.intakeSystem);
  outtakeSpeed = speed;
}

// Called just before this Command runs the first time
void Ball_Outtake::Initialize() {globalRobot.intakeSystem.IntakeRoller(outtakeSpeed);}

// Called repeatedly when this Command is scheduled to run
void Ball_Outtake::Execute() 
{

}

// Make this return true when this Command no longer needs to run execute()
bool Ball_Outtake::IsFinished() { return false; }

// Called once after isFinished returns true
void Ball_Outtake::End() 
{
  globalRobot.intakeSystem.IntakeRoller(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Ball_Outtake::Interrupted() 
{
  End();
}
