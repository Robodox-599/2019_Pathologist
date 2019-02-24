/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/WristSystem.h"
#include "commands/WristJoystick.h"
//925, 1003, 964
//Practice 427, 507
WristSystem::WristSystem(float min, float max, float marginPercent) : Subsystem("WristSystem"), wristMotor(9)
{
  float limitOffSet = (max-min)*(marginPercent/100);
  float fwdLimit = max - limitOffSet;
  float revLimit = min + limitOffSet;
  
  wristMotor.ConfigSelectedFeedbackSensor(Analog, 0, 0);
  wristMotor.SetSensorPhase(true);
  wristMotor.SetInverted(true);
//  wristMotor.ConfigForwardSoftLimitThreshold(1005);
//  wristMotor.ConfigReverseSoftLimitThreshold(931);
  wristMotor.ConfigForwardSoftLimitThreshold(fwdLimit);
  wristMotor.ConfigReverseSoftLimitThreshold(revLimit);
  wristMotor.ConfigForwardSoftLimitEnable(true);
  wristMotor.ConfigReverseSoftLimitEnable(true);
  float kf = 0;
  float kp = 22.5;
  float ki = 0;
  float kd = 0;
  float velocity = 964 / 32;
  float acceleration = 964 / 32;

  wristMotor.Config_kF(0, kf, 0);
  wristMotor.Config_kP(0, kp, 0);
  wristMotor.Config_kI(0, ki, 0);
  wristMotor.Config_kD(0, kd, 0);

  wristMotor.ConfigMotionAcceleration(acceleration);
  wristMotor.ConfigMotionCruiseVelocity(velocity);
  target = wristMotor.GetSelectedSensorPosition();
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
  //wristMotor.Set(ControlMode::PercentOutput, axis*.3);
  target += (axis * 1.5);
  if(target > 499){target = 498;}
  if(target < 436){target = 437;}
  wristMotor.Set(ControlMode::MotionMagic, target);
  // printf("%d\n",wristMotor.GetSelectedSensorPosition());
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