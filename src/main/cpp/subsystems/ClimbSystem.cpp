/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/ClimbSystem.h"
#include "WPILib.h"


ClimbSystem::ClimbSystem() : Subsystem("ClimbSystem") {

  LeftPiston = new frc::DoubleSolenoid(2); //dummy value
  RightPiston = new frc::DoubleSolenoid(3); //dummy value
  RearPiston = new frc::DoubleSolenoid(4); //dummy value
  ScooterMotor = new frc::Talon(5); //dummy value
  
}


void ClimbSystem::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());

  
}

void ClimbSystem::LeftPistonExpand()
{
  LeftPiston.Set(Forward);
}

void ClimbSystem::RightPistonExpand()
{
  RightPiston.Set(Forward);
}

void ClimbSystem::RearPistonExpand()
{
  RearPiston.Set(Forward);
}

void ClimbSystem::LeftPistonRetract()
{
  RearPiston.Set(Reverse);
}

void ClimbSystem::RightPistonRetract()
{
  RightPiston.Set(Reverse);
}

void ClimbSystem::RearPistonRetract()
{
  RearPiston.Set(Reverse);
}

void ClimbSystem::StopAllMotors()
{

}
// Put methods for controlling this subsystem
// here. Call these from Commands.
