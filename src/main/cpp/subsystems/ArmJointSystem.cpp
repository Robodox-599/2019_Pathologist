/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/ArmJointSystem.h"

ArmJointSystem::ArmJointSystem() : Subsystem("ArmJointSystem"), ArmJointMotor(3)
{
  ArmJointMotor.ConfigSelectedFeedbackSensor(CTRE_MagEncoder_Absolute, 0, 0);
  float kf = 0;
  float kp = 0;
  float ki = 0;
  float kd = 0;
  float velocity = 0;
  float acceleration = 0;

  ArmJointMotor.Config_kF(0, kf, 0);
  ArmJointMotor.Config_kP(0, kp, 0);
  ArmJointMotor.Config_kI(0, ki, 0);
  ArmJointMotor.Config_kD(0, kd, 0);

  ArmJointMotor.ConfigMotionAcceleration(acceleration);
  ArmJointMotor.ConfigMotionCruiseVelocity(velocity);
}

void ArmJointSystem::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void ArmJointSystem::MotionMagicControl(double ticks)
{
  ArmJointMotor.Set(ControlMode::MotionMagic, ticks);
}
