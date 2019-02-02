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

void IntakeSystem::Intake(bool intake)
{
  if(Stop.Get() == false)
  {
     IntakeMotor.Set(ControlMode::PercentOutput, .8); 
  }       
}

void IntakeSystem::Outtake(bool outtake)
{
     IntakeMotor.Set(ControlMode::PercentOutput, -0.8)
}    

void IntakeSystem::HatchPistons(bool forward)
{
       HatchPiston.Set(Forward);
       HatchPiston2.Set(Forward);
       Wait (500); //dummy value
       HatchPiston.Set(off);
       HatchPiston.Set(off);
}

bool IntakeSystem::LimitSwitch()
{
  return Stop.Get();
}


