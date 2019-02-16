/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/ClimbSystem.h"
#include "commands/ScooterMove.h"

ClimbSystem::ClimbSystem() : Subsystem("ClimbSystem"), LeftPiston(4, 5), RightPiston(6, 7), RearPiston(2, 3), ScooterMotor(4)  // Dummy Values
{
  ClimbFlag = false;
  LeftPiston.Set(frc::DoubleSolenoid::kReverse);
  RightPiston.Set(frc::DoubleSolenoid::kForward);
  RearPiston.Set(frc::DoubleSolenoid::kReverse);
}

void ClimbSystem::InitDefaultCommand()
{
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
  SetDefaultCommand(new ScooterMove());
}

void ClimbSystem::LeftPistonExpand()
{
  LeftPiston.Set(frc::DoubleSolenoid::kForward);
}

void ClimbSystem::RightPistonExpand()
{
  RightPiston.Set(frc::DoubleSolenoid::kReverse);
}

void ClimbSystem::RearPistonExpand()
{
  RearPiston.Set(frc::DoubleSolenoid::kForward);
}

void ClimbSystem::LeftPistonRetract()
{
  LeftPiston.Set(frc::DoubleSolenoid::kReverse);
}

void ClimbSystem::RightPistonRetract()
{
  RightPiston.Set(frc::DoubleSolenoid::kForward);
}

void ClimbSystem::RearPistonRetract()
{
  RearPiston.Set(frc::DoubleSolenoid::kReverse);
}

void ClimbSystem::WheelSpin(double x)
{
  ScooterMotor.Set(ControlMode::PercentOutput, x);
}
// Put methods for controlling this subsystem
// here. Call these from Commands.

bool ClimbSystem::GetClimbFlag()
{
  return ClimbFlag;
}

void ClimbSystem::SetClimbFlagTrue()
{
  ClimbFlag = true;
}