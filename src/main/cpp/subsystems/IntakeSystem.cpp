/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/IntakeSystem.h"

IntakeSystem::IntakeSystem() : Subsystem("ExampleSubsystem") {
  HatchPiston = new frc::DoubleSolenoid(1, 2); //dummy values
  HatchPiston2 = new frc::DoubleSolenoid(3, 4);
  Stop = new frc::DigitalInput(1); //dummy values
  bool OldButton = 0;
  bool OldButton2 = 0;
}

void IntakeSystem::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void IntakeSystem::Intake(bool intake)
{
    bool CurrentButton = OI.GetRawButton(1);

    if (CurrentButton = OldButton)
    {
       if (intake && Stop.Get() == false)
          {
           IntakeMotor.Set(ControlMode::PercentOutput, .8);
           wait (500); //dummy value
           IntakeMotor.Set(ControlMode::PercentOutput, 0);
          }
       else
          {
            IntakeMotor.Set(ControlMode::PercentOutput, 0);
          }
    }
    OldButton = CurrentButton;
}

void IntakeSystem::Outtake(bool outtake)
{
   bool CurrentButton2 = OI.GetRawButton(2);
   
   if(CurrentButton 2 = OldButton2)
   {
     if (outtake && Stop.Get() == false)
     {
       IntakeMotor.Set(ControlMode::PercentOutput, -0.8)
       wait (500); //dummy value
       IntakeMotor.Set(ControlMode::PercentOutput, 0);
     }
     else
     {
       IntakeMotor.Set(ControlMode::PercentOutput, 0)
     }
   }
   OldButton2 = CurrentButton2; 
}

void IntakeSystem::HatchPistons(bool forward)
{
    if (forward)
     {
       HatchPiston.Set(Forward);
       HatchPiston2.Set(Forward);
       Wait (500); //dummy value
       HatchPiston.Set(off);
       HatchPiston.Set(off);
       toggle = 0;
     }
     else
     {
       HatchPiston.Set(off);
       HatchPiston2.Set(off);
     }
}

bool Stop()
{
  return Stop.Get();
}

