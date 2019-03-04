/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Ball_Intake.h"
#include "Robot.h"
Ball_Intake::Ball_Intake(float speed) {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  Requires(&globalRobot.intakeSystem);
  motorSpeed = speed;
}

// Called just before this Command runs the first time
void Ball_Intake::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void Ball_Intake::Execute() 
{
  globalRobot.intakeSystem.IntakeRoller(motorSpeed, 0/*globalRobot.oi.xbox->GetRawAxis(3), globalRobot.oi.xbox->GetRawAxis(2)*/);
}

// Make this return true when this Command no longer needs to run execute()
bool Ball_Intake::IsFinished() { return false; }

// Called once after isFinished returns true
void Ball_Intake::End() 
{
    globalRobot.intakeSystem.IntakeRoller(0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Ball_Intake::Interrupted() {
  End();
}
