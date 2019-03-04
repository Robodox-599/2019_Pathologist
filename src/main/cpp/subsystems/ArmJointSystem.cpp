/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/ArmJointSystem.h"
#include "commands/ArmJointJoystick.h"
#include "commands/ArmJointControl.h"
//465, 80, 272
//Practice 305, 821     190, 686
//0 angle 371,   90 angle 686
ArmJointSystem::ArmJointSystem(float min, float max, float marginPercent) : Subsystem("ArmJointSystem"), ArmJointMotor(7)
{
  angle0 = 371;

  float limitOffSet = (max - min) * (marginPercent / 200);
  float fwdLimit = max - limitOffSet;
  float revLimit = min + limitOffSet;

  commandLimitOffset = (max - min) * (marginPercent / 100);
  fwdCommandLimit = max - commandLimitOffset;
  revLimit = min + commandLimitOffset;

  ArmJointMotor.ConfigSelectedFeedbackSensor(Analog, 0, 0);
  ArmJointMotor.SetSensorPhase(true);
  ArmJointMotor.SetInverted(true);
  // ArmJointMotor.ConfigForwardSoftLimitThreshold(453);
  // ArmJointMotor.ConfigReverseSoftLimitThreshold(92);
  ArmJointMotor.ConfigForwardSoftLimitThreshold(fwdLimit);
  ArmJointMotor.ConfigReverseSoftLimitThreshold(revLimit);
  ArmJointMotor.ConfigForwardSoftLimitEnable(true);
  ArmJointMotor.ConfigReverseSoftLimitEnable(true);
  float kf = 0;
  float kp = 15;
  float ki = 0;
  float kd = 0;
  float velocity = 272 / 8;
  float acceleration = 272 / 8;

  ArmJointMotor.Config_kF(0, kf, 0);
  ArmJointMotor.Config_kP(0, kp, 0);
  ArmJointMotor.Config_kI(0, ki, 0);
  ArmJointMotor.Config_kD(0, kd, 0);

  ArmJointMotor.ConfigMotionAcceleration(acceleration);
  ArmJointMotor.ConfigMotionCruiseVelocity(velocity);

  target = ArmJointMotor.GetSelectedSensorPosition();
}

void ArmJointSystem::InitDefaultCommand()
{
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
  //SetDefaultCommand(new ArmJointJoystick());
  //SetDefaultCommand(new ArmJointControl(target));
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void ArmJointSystem::MotionMagicControl(double ticks)
{
  ArmJointMotor.Set(ControlMode::MotionMagic, ticks);
}

void ArmJointSystem::MotionMagicDegrees(double degrees)
{
  double ticks = degrees * 3.4889 + angle0;
  ArmJointMotor.Set(ControlMode::MotionMagic, ticks);
}

void ArmJointSystem::MotionMagicJoystickControl(double axis)
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
  // ArmJointMotor.Set(ControlMode::PercentOutput, axis*.3);
  target += (axis * 2.5);
  if (target > 929)
  {
    target = 928;
  }
  if (target < 473)
  {
    target = 474;
  }
  ArmJointMotor.Set(ControlMode::MotionMagic, target);
}

void ArmJointSystem::JoystickControl(double axis)
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
  ArmJointMotor.Set(ControlMode::PercentOutput, axis);
  frc::SmartDashboard::PutNumber("Arm Joint Potentiometer readout", ArmJointMotor.GetSelectedSensorPosition());
}

void ArmJointSystem::ChangeTarget(double newTarget)
{
  target = newTarget * 3.4889 + angle0;
}

double ArmJointSystem::ReturnAngle()
{
  return ((ArmJointMotor.GetSelectedSensorPosition(0) - angle0) / 3.4889);
}