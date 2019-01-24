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

class WristSystem : public frc::Subsystem {
 private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities
	TalonSRX wristMotor = {11};
	double avgEncVal;
	double encVals[10];
	PIDVar wrist;
	bool wristSet;
	double wristTarget;

 public:
  WristSystem();
  void InitDefaultCommand() override;
  double GetEncVal();
	void UpdateEncVal();
	void GetAvgEncVal();
	void HoldWristPosition();
	void WristPID();
	bool WristFlag();
	void ResetWristFlag();
	void SetWristTarget(double angle);
	bool WristTargetSet(double angle);
};
