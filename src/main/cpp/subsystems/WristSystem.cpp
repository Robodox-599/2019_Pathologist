/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/WristSystem.h"

WristSystem::WristSystem() : Subsystem("WristSystem"), wristMotor(11)
{
  wristMotor.ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Absolute);
  wristTarget = wristMotor.GetSelectedSensorPosition();
  avgEncVal = 0;
  encVals[0] = 0;
  encVals[1] = 0;
  encVals[2] = 0;
  encVals[3] = 0;
  encVals[4] = 0;
  encVals[5] = 0;
  encVals[6] = 0;
  encVals[7] = 0;
  encVals[8] = 0;
  encVals[9] = 0;
  wrist.integrator = 0;
  wrist.kf = -0.40;
  wrist.kp = 0.025;
  wrist.ki = 0;
  wrist.kd = 0.25;
  wristMotor.ConfigOpenloopRamp(0.25, 0);
  wristSet = false;
}

void WristSystem::InitDefaultCommand()
{
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

double WristSystem::GetEncVal()
{
  return avgEncVal;
}

void WristSystem::UpdateEncVal()
{
  encVals[0] = encVals[1];
  encVals[1] = encVals[2];
  encVals[2] = encVals[3];
  encVals[3] = encVals[4];
  encVals[4] = encVals[5];
  encVals[5] = encVals[6];
  encVals[6] = encVals[7];
  encVals[7] = encVals[8];
  encVals[8] = encVals[9];
  encVals[9] = wristMotor.GetSelectedSensorPosition();
}

void WristSystem::GetAvgEncVal()
{
  avgEncVal = (encVals[0] + encVals[1] + encVals[2] + encVals[3] + encVals[4] + encVals[5] + encVals[6] + encVals[7] + encVals[8] + encVals[9]) / 10;
}

void WristSystem::HoldWristPosition()
{
  double angle;
  angle = avgEncVal * (3.14 / 140) /*In parentheses - conversion from potentiometer value to radians*/;
  if (avgEncVal > -6)
  {
    wristMotor.Set(ControlMode::PercentOutput, -0.40 * cos(angle));
  }
  else
  {
    wristMotor.Set(ControlMode::PercentOutput, 0);
  }
  frc::SmartDashboard::PutNumber("Wrist Motor Power Output", wristMotor.GetMotorOutputPercent());
}

void WristSystem::WristPID()
{
  double nkp = 0.0125;
  double angle = avgEncVal * (3.14 / 140);
  double kpValue;
  //double setTarget = -32.5*(target-1);
  wrist.error = avgEncVal - wristTarget;
  wrist.integrator += wrist.error;
  if (wrist.error < 0)
  {
    kpValue = wrist.kp;
  }
  else
  {
    kpValue = nkp;
  }
  wrist.motorPower = (wrist.error * kpValue) + (wrist.kd * (wrist.error - wrist.prevError)) + (wrist.ki * wrist.integrator);
  if (avgEncVal < 0 && wristTarget < 0)
  {
    wristMotor.Set(ControlMode::PercentOutput, 0);
  }
  else
  {
    wristMotor.Set(ControlMode::PercentOutput, ((wrist.kf) * cos(angle)) + wrist.motorPower);
  }
  if (wrist.error > -3 && wrist.error < 3 || wristTarget < 0)
  {
    wristSet = true;
  }
  wrist.prevError = wrist.error;
}

bool WristSystem::WristFlag()
{
  return wristSet;
}

void WristSystem::ResetWristFlag()
{
  wristSet = false;
}

void WristSystem::SetWristTarget(double angle)
{
  wristTarget = angle;
}

bool WristSystem::WristTargetSet(double angle)
{
  if (wristTarget == angle)
  {
    return true;
  }
  else
  {
    return false;
  }
}