/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Subsystem.h>
#include "../RobotMap.h"
#include "ctre/Phoenix.h"
#include "frc/WPILib.h"

class ClimbSystem : public frc::Subsystem
{
private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities

  frc::DoubleSolenoid LeftPiston;
  frc::DoubleSolenoid RightPiston;
  frc::DoubleSolenoid RearPiston;
  TalonSRX ScooterMotor = {5};

public:
  ClimbSystem();
  void InitDefaultCommand() override;
  void LeftPistonExpand();
  void RightPistonExpand();
  void RearPsistonExpand();
  void LeftPistonRetract();
  void RightPistonRetract();
  void RearPistonRetract();
  void WheelSpin(int x);
};
