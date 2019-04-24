/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Subsystem.h>
#include <frc/WPILib.h>
#include <ctre/Phoenix.h>

class IntakeSystem : public frc::Subsystem {
 private:
 TalonSRX IntakeMotor;
 bool ballFlag;
 frc::DoubleSolenoid hatchHook;
 bool hatchFlag;

 public:
  IntakeSystem();
  void InitDefaultCommand() override;
  void IntakeRoller(float positiveSpeed, float negativeSpeed);
  bool ReturnBallFlag();
  void SetBallFlagTrue();
  void SetBallFlagFalse();
  void HatchHookIn();
  void HatchHookOut();
  bool ReturnHatchFlag();
};
