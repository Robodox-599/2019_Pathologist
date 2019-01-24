/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/ClimbSystem.h"

ClimbSystem::ClimbSystem() : Subsystem("ExampleSubsystem")
{

  LeftPiston = new frc::DoubleSolenoid(1, 2);  //dummy value
  RightPiston = new frc::DoubleSolenoid(3, 4); //dummy value
  RearPiston = new frc::DoubleSolenoid(5, 6);  //dummy value
}

void ClimbSystem::InitDefaultCommand()
{
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

void ClimbSystem::LeftPistonExpand()
{
  LeftPiston->Set(frc::DoubleSolenoid::kForward);
}

void ClimbSystem::RightPistonExpand()
{
  RightPiston->Set(frc::DoubleSolenoid::kForward);
}

void ClimbSystem::RearPistonExpand()
{
  RearPiston->Set(frc::DoubleSolenoid::kForward);
}

void ClimbSystem::LeftPistonRetract()
{
  RearPiston->Set(frc::DoubleSolenoid::kReverse);
}

void ClimbSystem::RightPistonRetract()
{
  RightPiston->Set(frc::DoubleSolenoid::kReverse);
}

void ClimbSystem::RearPistonRetract()
{
  RearPiston->Set(frc::DoubleSolenoid::kReverse);
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
