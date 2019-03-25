/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Subsystem.h>
#include "ctre/phoenix.h"
#include <frc/WPILib.h>

class DriveSystem : public frc::Subsystem
{
private:
  TalonSRX frontLeftMotor;
  TalonSRX rearLeftMotor;
  TalonSRX frontRightMotor;
  TalonSRX rearRightMotor;
  TalonSRX climbMotor;
  frc::DoubleSolenoid shifter;

  PigeonIMU pGyon;

  double ypr[3];

  bool turn;
  double currentHeading;
  double gyroTarget;
  double targetHeading;
  double velocity;
  bool driveFlag;
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities

public:
  DriveSystem();
  void InitDefaultCommand() override;
  void JoystickVelocityDrive(double x, double y);
  void ClimbDrive(double axis);

  void GetYaw();
  void GyroTurn(double angle);
  void ResetGyroFlag();
  bool GetGyroFlag();
  void SetGyroTarget(double target);
  double ReturnGyroTarget();
  void GetGyroValues();
  void ResetGyro();
  void SetDriveFlagTrue();
  void SetDriveFlagFalse();
  bool ReturnDriveFlag();

  void JoystickPercentDrive(double x, double y);

  void ShifterOn();
  void ShifterOff();
};
