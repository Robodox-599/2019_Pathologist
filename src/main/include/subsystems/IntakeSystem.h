/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Subsystem.h>
#include <frc/WPILib.h>
#include <frc/CTRE/Phoenix.h>

class IntakeSystem : public frc::Subsystem {
 private:
 frc::DoubleSolenoid HatchPiston;
 frc::DoubleSolenoid HatchPiston2;
 TalonSRX IntakeMotor;
 frc::DigitalINput Stop; 

 public:
  IntakeSystem();
  void InitDefaultCommand() override;
  void Intake(bool intake);
  void Outtake (bool outtake);
  void HatchPistons(bool forward);
  bool LimitSwitch();
};
