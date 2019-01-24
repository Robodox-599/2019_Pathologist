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
#include "WPILib.h"

class ClimbSystem : public frc::Subsystem {
 private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities

frc::DoubleSolenoid* LeftPiston;
frc::DoubleSolenoid* RightPiston;
frc::DoubleSolenoid* RearPiston;
frc::Talon* ScooterMotor;


 public:
  ClimbSystem();
  void InitDefaultCommand() override;
  void ClimbSystem::LeftPistonExpand();
  void ClimbSystem::RightPistonExpand();
  void ClimbSystem::RearPistonExpand();
  void ClimbSystem::LeftPistonRetract();
  void ClimbSystem::RightPistonRetract();
  void ClimbSystem::RearPistonRetract();
  

};
