/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/ArmJointSystem.h"
#include "commands/ArmJointJoystick.h"
//465, 80, 272
ArmJointSystem::ArmJointSystem() : Subsystem("ArmJointSystem"), ArmJointMotor(7)
{
  ArmJointMotor.ConfigSelectedFeedbackSensor(Analog, 0, 0);
  ArmJointMotor.SetSensorPhase(true);
  ArmJointMotor.SetInverted(true);
  float kf = 0;
  float kp = 15;
  float ki = 0;
  float kd = 0;
  float velocity = 272/8;
  float acceleration = 272/12;

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
  SetDefaultCommand(new ArmJointJoystick());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void ArmJointSystem::MotionMagicControl(double ticks)
{
  ArmJointMotor.Set(ControlMode::MotionMagic, ticks);
}

void ArmJointSystem::MotionMagicJoystickControl(double axis)
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

  target += (axis*2.5);
  
  ArmJointMotor.Set(ControlMode::MotionMagic, target + 272);
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