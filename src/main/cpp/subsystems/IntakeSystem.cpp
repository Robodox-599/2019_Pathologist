/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/IntakeSystem.h"

IntakeSystem::IntakeSystem() : Subsystem("ExampleSubsystem"), IntakeMotor(1), HatchPiston(1,2), HatchPiston2(3,4), limit(1) //dummy values
{
  
}

void IntakeSystem::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void IntakeSystem::Intake(float speed)
{
     IntakeMotor.Set(ControlMode::PercentOutput, speed);        
}

void IntakeSystem::Outtake(float speed)
{
     IntakeMotor.Set(ControlMode::PercentOutput, speed);
}    

void IntakeSystem::HatchPistonsForward()
{
     HatchPiston.Set(frc::DoubleSolenoid::kForward);
     HatchPiston2.Set(frc::DoubleSolenoid::kForward);
}

void IntakeSystem::HatchPistonsReverse()
{
     HatchPiston.Set(frc::DoubleSolenoid::kReverse);
     HatchPiston2.Set(frc::DoubleSolenoid::kReverse);
}

bool IntakeSystem::LimitSwitch()
{
  return limit.Get();
}


