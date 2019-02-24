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

class SlideSystem : public frc::Subsystem {
  private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities
  TalonSRX TelescopeMotor;
  double target;

 public:
  SlideSystem(float min, float max, float marginPercent);
  void InitDefaultCommand() override;
  void MotionMagicControl(double ticks);
  void MotionMagicJoystickControl(double axis);
  void JoystickControl(double axis);
};
