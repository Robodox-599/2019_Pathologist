/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/WristResetMinMax.h"
#include "Robot.h"

WristResetMinMax::WristResetMinMax(float power)
{
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  Requires(&globalRobot.wristSystem);
  motorPower = power;
}

// Called just before this Command runs the first time
void WristResetMinMax::Initialize() { globalRobot.wristSystem.ResetMinMax(motorPower); }

// Called repeatedly when this Command is scheduled to run
void WristResetMinMax::Execute() {}

// Make this return true when this Command no longer needs to run execute()
bool WristResetMinMax::IsFinished()
{
  return globalRobot.wristSystem.ReturnResetFlag();
}

// Called once after isFinished returns true
void WristResetMinMax::End()
{
  globalRobot.wristSystem.SetResetFlagFalse();
  frc::Wait(1);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void WristResetMinMax::Interrupted() {}
