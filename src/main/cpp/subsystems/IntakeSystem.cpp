/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/IntakeSystem.h"
#include "commands/Ball_Intake.h"

IntakeSystem::IntakeSystem() : Subsystem("IntakeSystem"), IntakeMotor(8), hatchHook(0, 1)
{
  hatchHook.Set(frc::DoubleSolenoid::kReverse);
  hatch = false;
}

void IntakeSystem::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
  SetDefaultCommand(new Ball_Intake());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void IntakeSystem::IntakeRoller(float negativeSpeed, float positiveSpeed)
{
  positiveSpeed = positiveSpeed;
  negativeSpeed = negativeSpeed;
  IntakeMotor.Set(ControlMode::PercentOutput, negativeSpeed - positiveSpeed);        
}

bool IntakeSystem::ReturnBallFlag()
{
  return ballFlag;
}

void IntakeSystem::SetBallFlagFalse()
{
  ballFlag = false;
}

void IntakeSystem::SetBallFlagTrue()
{
  ballFlag = true;
}

void IntakeSystem::HatchHookIn()
{
  hatchHook.Set(frc::DoubleSolenoid::kReverse);
  hatch = false;
}

void IntakeSystem::HatchHookOut()
{
  hatchHook.Set(frc::DoubleSolenoid::kForward);
  hatch = true;
}

bool IntakeSystem::ReturnHatchFlag()
{
  return hatch;
}