/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/WristSystem.h"
#include "commands/WristJoystick.h"
//2488, -771, 1629
WristSystem::WristSystem() : Subsystem("WristSystem"), wristMotor(9)
{
  wristMotor.ConfigSelectedFeedbackSensor(CTRE_MagEncoder_Absolute, 0, 0);
  wristMotor.SetSensorPhase(false);
  wristMotor.SetInverted(true);
  float kf = 0;
  float kp = 15;
  float ki = 0;
  float kd = 0;
  float velocity = 1629 / 32;
  float acceleration = 1629 / 32;

  wristMotor.Config_kF(0, kf, 0);
  wristMotor.Config_kP(0, kp, 0);
  wristMotor.Config_kI(0, ki, 0);
  wristMotor.Config_kD(0, kd, 0);

  wristMotor.ConfigMotionAcceleration(acceleration);
  wristMotor.ConfigMotionCruiseVelocity(velocity);
}

void WristSystem::InitDefaultCommand()
{
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
  SetDefaultCommand(new WristJoystick());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void WristSystem::MotionMagicControl(double ticks)
{
  wristMotor.Set(ControlMode::MotionMagic, ticks);
}

void WristSystem::MotionMagicJoystickControl(double axis)
{
  double target;
  if (axis > 0.2)
  {
    axis = (axis - 0.2) * (1 / .8);
  }
  else if (axis < -0.2)
  {
    axis = (axis + 0.2) * (1 / .8);
  }
  else
  {
    axis = 0;
  }

  target += (axis * 20);

  wristMotor.Set(ControlMode::MotionMagic, target + 1629);
}

void WristSystem::JoystickControl(double axis)
{
  if (axis > 0.2)
  {
    axis = (axis - 0.2) * (1 / .8) * .25;
  }
  else if (axis < -0.2)
  {
    axis = (axis + 0.2) * 1 / .8 * .25;
  }
  else
  {
    axis = 0;
  }
  wristMotor.Set(ControlMode::PercentOutput, axis);
  frc::SmartDashboard::PutNumber("Wrist Encoder readout", wristMotor.GetSelectedSensorPosition());
}