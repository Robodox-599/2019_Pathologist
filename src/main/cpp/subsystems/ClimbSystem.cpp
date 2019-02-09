/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/ClimbSystem.h"

ClimbSystem::ClimbSystem() : Subsystem("ExampleSubsystem"), LeftPiston(1,2), RightPiston(3,4), RearPiston(5,6)  // Dummy Values
{
}

void ClimbSystem::InitDefaultCommand()
{
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

void ClimbSystem::LeftPistonExpand()
{
  LeftPiston.Set(frc::DoubleSolenoid::kForward);
}

void ClimbSystem::RightPistonExpand()
{
  RightPiston.Set(frc::DoubleSolenoid::kForward);
}

void ClimbSystem::RearPistonExpand()
{
  RearPiston.Set(frc::DoubleSolenoid::kForward);
}

void ClimbSystem::LeftPistonRetract()
{
  RearPiston.Set(frc::DoubleSolenoid::kReverse);
}

void ClimbSystem::RightPistonRetract()
{
  RightPiston.Set(frc::DoubleSolenoid::kReverse);
}

void ClimbSystem::RearPistonRetract()
{
  RearPiston.Set(frc::DoubleSolenoid::kReverse);
}

void ClimbSystem::WheelSpin(int x)
{
  ScooterMotor.Set(ControlMode::PercentOutput, x);
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
