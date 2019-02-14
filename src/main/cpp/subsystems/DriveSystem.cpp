/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/DriveSystem.h"

<<<<<<< HEAD
DriveSystem::DriveSystem() : Subsystem("DriveSystem") {}
=======
DriveSystem::DriveSystem() : Subsystem("DriveSystem"), frontLeftMotor(6), rearLeftMotor(5), frontRightMotor(2), rearRightMotor(1), pGyon(2)
{
  frontLeftMotor.SetInverted(true);
  rearLeftMotor.SetInverted(true);
  frontRightMotor.SetInverted(false);
  rearRightMotor.SetInverted(false);
>>>>>>> Drive

  rearLeftMotor.SetSensorPhase(true);
  rearRightMotor.SetSensorPhase(false);

  rearLeftMotor.ConfigSelectedFeedbackSensor(QuadEncoder, 0, 0);
  rearRightMotor.ConfigSelectedFeedbackSensor(QuadEncoder, 0, 0);

  rearLeftMotor.SetSelectedSensorPosition(0, 0, 0);
  rearRightMotor.SetSelectedSensorPosition(0, 0, 0);

  rearLeftMotor.ConfigClosedloopRamp(0, 0);
  rearRightMotor.ConfigClosedloopRamp(0, 0);

  frontLeftMotor.ConfigClosedloopRamp(0, 0);
  frontRightMotor.ConfigClosedloopRamp(0, 0);

  float seconds = 0.15;

  rearLeftMotor.ConfigClosedloopRamp(seconds, 0);
  rearRightMotor.ConfigClosedloopRamp(seconds, 0);
  frontLeftMotor.ConfigClosedloopRamp(seconds, 0);
  frontRightMotor.ConfigClosedloopRamp(seconds, 0);

  float kp = 0.8;
  float ki = 0;

  rearLeftMotor.Config_kF(0, 0.45, 0);
  rearLeftMotor.Config_kP(0, kp, 0);
  rearLeftMotor.Config_kI(0, ki, 0);
  rearLeftMotor.Config_kD(0, 0, 0);

  rearRightMotor.Config_kF(0, 0.45, 0);
  rearRightMotor.Config_kP(0, kp, 0);
  rearRightMotor.Config_kI(0, ki, 0);
  rearRightMotor.Config_kD(0, 0, 0);

  frontLeftMotor.Config_kF(0, 0.45, 0);
  frontLeftMotor.Config_kP(0, kp, 0);
  frontLeftMotor.Config_kI(0, ki, 0);
  frontLeftMotor.Config_kD(0, 0, 0);

  frontRightMotor.Config_kF(0, 0.45, 0);
  frontRightMotor.Config_kP(0, kp, 0);
  frontRightMotor.Config_kI(0, ki, 0);
  frontRightMotor.Config_kD(0, 0, 0);

  pGyon.SetYaw(0, 0);
  currentHeading = 0;
  gyroTarget = 0;
  turn = false;
  targetHeading = 0;

  velocity = 0;
}

void DriveSystem::InitDefaultCommand()
{
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void DriveSystem::JoystickVelocityDrive(double x, double y)
{
  double l;
  double r;
  double leftOutput;
  double rightOutput;
  double increment = 600;

  if (y > 0.2)
  {
    y = (y - 0.2) * (1 / .8) * 3000 /**max velocity*/;
  }
  else if (y < -0.2)
  {
    y = (y + 0.2) * 1 / .8 * 3000 /**max velocity*/;
  }
  else
  {
    y = 0;
  }

  if (x > 0.2)
  {
    x = (x - 0.2) * 1 / .8 * 1500 /**max velocity/2*/;
  }
  else if (x < -0.2)
  {
    x = (x + 0.2) * 1 / .8 * 1500 /**max velocity/2*/;
  }
  else
  {
    x = 0;
  }

  l = -y + x;
  r = -y - x;

  if (l > rearLeftMotor.GetSelectedSensorVelocity(0) + increment)
  {
    leftOutput = rearLeftMotor.GetSelectedSensorVelocity(0) + increment;
  }
  else if (l < rearLeftMotor.GetSelectedSensorVelocity(0) - increment)
  {
    leftOutput = rearLeftMotor.GetSelectedSensorVelocity(0) - increment;
  }
  else
  {
    leftOutput = l;
  }

  if (r > rearRightMotor.GetSelectedSensorVelocity(0) + increment)
  {
    rightOutput = rearRightMotor.GetSelectedSensorVelocity(0) + increment;
  }
  else if (r < rearRightMotor.GetSelectedSensorVelocity(0) - increment)
  {
    rightOutput = rearRightMotor.GetSelectedSensorVelocity(0) - increment;
  }
  else
  {
    rightOutput = r;
  }

  frontLeftMotor.Set(ControlMode::Follower, 1);
  rearLeftMotor.Set(ControlMode::Velocity, leftOutput);
  frontRightMotor.Set(ControlMode::Follower, 3);
  rearRightMotor.Set(ControlMode::Velocity, rightOutput);
}

void DriveSystem::GetYaw()
{
  currentHeading = ypr[0];
}

void DriveSystem::SetGyroTarget(double target)
{
  GetYaw();
  targetHeading = target;
  gyroTarget = currentHeading + target;
}

double DriveSystem::ReturnGyroTarget()
{
  return gyroTarget;
}

void DriveSystem::ResetGyroFlag()
{
  turn = false;
}

bool DriveSystem::GetGyroFlag()
{
  return turn;
}

void DriveSystem::GyroTurn(double angle)
{
  double accAngle = 45;
  double velocity = 1000;
  double error;
  double velocityFactor;
  error = angle - currentHeading;
  if (error > targetHeading / 2 && angle > 0)
  {
    velocityFactor = (targetHeading - error + 10) / accAngle;
  }
  else if (error > 0)
  {
    velocityFactor = (error + 3) / accAngle;
  }
  if (error < targetHeading / 2 && angle < 0)
  {
    velocityFactor = (targetHeading - error - 10) / accAngle;
  }
  else if (error < 0)
  {
    velocityFactor = (error - 3) / accAngle;
  }

  if (velocityFactor > 1)
  {
    velocityFactor = 1;
  }
  if (velocityFactor < -1)
  {
    velocityFactor = -1;
  }
  //	if(error > -1 && error < 1){velocityFactor = 0; turn = true;}
  if (error == 0)
  {
    velocityFactor = 0;
    turn = true;
  }

  frontLeftMotor.Set(ControlMode::Follower, 1);
  rearLeftMotor.Set(ControlMode::Velocity, -velocity * velocityFactor);
  frontRightMotor.Set(ControlMode::Follower, 3);
  rearRightMotor.Set(ControlMode::Velocity, velocity * velocityFactor);
}

void DriveSystem::GetGyroValues()
{
  pGyon.GetYawPitchRoll(ypr);
}

void DriveSystem::ResetGyro()
{
  pGyon.SetYaw(0, 0);
}