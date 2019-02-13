/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Subsystem.h>
#include <ctre/phoenix.h>
#include <frc/WPILib.h>
#include <RobotMap.h>

class SlideSystem : public frc::Subsystem {
 private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities
  TalonSRX TelescopeMotor;
  frc::AnalogPotentiometer pot;
  double avgPotVal;
	double potVals[10];
  bool slideSet;
	double slideTarget;
  PIDVar slide;

 public:
  SlideSystem();
  void InitDefaultCommand() override;
  void PositionControl();
};
