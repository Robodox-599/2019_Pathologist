/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/IntakeSystem.h"

IntakeSystem::IntakeSystem() : Subsystem("IntakeSystem"), IntakeMotor(8), HatchPiston(0,1), limit(1) //dummy values
{
  HatchPiston.Set(frc::DoubleSolenoid::kForward);
}

void IntakeSystem::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void IntakeSystem::IntakeRoller(float speed)
{
     IntakeMotor.Set(ControlMode::PercentOutput, speed);        
}

void IntakeSystem::HatchPistonsForward()
{
     HatchPiston.Set(frc::DoubleSolenoid::kReverse);
}

void IntakeSystem::HatchPistonsReverse()
{
     HatchPiston.Set(frc::DoubleSolenoid::kForward);
}

bool IntakeSystem::LimitSwitch()
{
  return limit.Get();
}


