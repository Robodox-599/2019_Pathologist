/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/SlideResetMinMax.h"
#include "Robot.h"

SlideResetMinMax::SlideResetMinMax(float power)
{
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  Requires(&globalRobot.slideSystem);
  motorPower = power;
}

// Called just before this Command runs the first time
void SlideResetMinMax::Initialize()
{
  globalRobot.slideSystem.ResetMinMax(motorPower);
}

// Called repeatedly when this Command is scheduled to run
void SlideResetMinMax::Execute() {}

// Make this return true when this Command no longer needs to run execute()
bool SlideResetMinMax::IsFinished() { return globalRobot.slideSystem.ReturnResetFlag(); }

// Called once after isFinished returns true
void SlideResetMinMax::End()
{
  globalRobot.slideSystem.SetResetFlagFalse();
  frc::Wait(1);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SlideResetMinMax::Interrupted() {}
