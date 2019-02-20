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
 frc::DoubleSolenoid HatchPiston;
 TalonSRX IntakeMotor;
 frc::DigitalInput limit; 

 public:
  IntakeSystem();
  void InitDefaultCommand() override;
  void IntakeRoller(float speed);
  void HatchPistonsForward();
  void HatchPistonsReverse();
  bool LimitSwitch();
};
