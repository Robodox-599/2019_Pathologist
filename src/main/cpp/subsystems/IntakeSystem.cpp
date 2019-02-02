/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/IntakeSystem.h"

IntakeSystem::IntakeSystem() : Subsystem("ExampleSubsystem"), IntakeMotor(1), HatchPiston(1,2), HatchPiston2(3,4), DigitalInput(1) //dummy values
{
  
}

void IntakeSystem::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void IntakeSystem::Intake()
{
     IntakeMotor.Set(ControlMode::PercentOutput, .8);        
}

void IntakeSystem::Outtake()
{
     IntakeMotor.Set(ControlMode::PercentOutput, -0.8)
}    

void IntakeSystem::HatchPistonsForward()
{
     HatchPiston.Set(Forward);
     HatchPiston2.Set(Forward);
}

void IntakeSystem::HatchPistonsReverse()
{
     HatchPiston.Set(reverse);
     HatchPiston2.Set(reverse);
}

bool IntakeSystem::LimitSwitch()
{
  return Stop.Get();
}


