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
	double fwdLimit;
  double revLimit;
  double limitOffSet;
  double potMin;
  double potMax;
  double percent;
  bool reset;
	double commandLimitOffset;
	double fwdCommandLimit;
	double revCommandLimit;
	double degreeToTicks = 204800.0/12240.0; //50.0/34.0 gear ratio   *    4096.0/360.0 ticks per 360

  public:
	WristSystem(double min, double max, double marginPercent);
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
