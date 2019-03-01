/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Subsystem.h>
#include <frc/WPILib.h>
#include "ctre/phoenix.h"
#include "RobotMap.h"

class WristSystem : public frc::Subsystem
{
  private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	TalonSRX wristMotor;
	double target;
	bool WristFlag;

	double startingPoint;
	float fwdLimit;
  float revLimit;
  float limitOffSet;
  float potMin;
  float potMax;
  float percent;
  bool reset;

  public:
	WristSystem(float min, float max, float marginPercent);
	void InitDefaultCommand() override;
	void MotionMagicControl(double ticks);
	void MotionMagicPercent(double percent);
	void MotionMagicDegrees(double degrees);
	void MotionMagicJoystickControl(double axis);
	void JoystickControl(double axis);
	void ChangeTarget(double newTarget);
	void SetWristFlagTrue();
	void SetWristFlagFalse();
	bool GetWristFlag();

	void ResetMinMax(float power);
  void ResetWristConfig();
  void SetResetFlagFalse();
  bool ReturnResetFlag();
};
