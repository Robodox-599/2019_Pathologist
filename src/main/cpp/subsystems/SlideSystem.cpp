/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/SlideSystem.h"
#include "commands/SlideJoystick.h"
#include "commands/SlideControl.h"
//507, 192, 349
//Practice 194, 500   (183, 489)    661, 354
SlideSystem::SlideSystem(float min, float max, float marginPercent) : Subsystem("SlideSystem"), TelescopeMotor(3)
{
  startingPoint = min;

  limitOffSet = (max - min) * (marginPercent / 200);
  fwdLimit = max - limitOffSet;
  revLimit = min + limitOffSet;

  totalTicks = max - min;

  commandLimitOffset = (max - min) * (marginPercent / 100);
  fwdCommandLimit = max - commandLimitOffset;
  revLimit = min + commandLimitOffset;

  percent = marginPercent;

  reset = false;

  TelescopeMotor.ConfigSelectedFeedbackSensor(Analog, 0, 0);
  TelescopeMotor.SetSensorPhase(true);
  TelescopeMotor.SetInverted(true);
  // TelescopeMotor.ConfigForwardSoftLimitThreshold(480);
  // TelescopeMotor.ConfigReverseSoftLimitThreshold(212);
  TelescopeMotor.ConfigForwardSoftLimitThreshold(fwdLimit);
  TelescopeMotor.ConfigReverseSoftLimitThreshold(revLimit);
  TelescopeMotor.ConfigForwardSoftLimitEnable(true);
  TelescopeMotor.ConfigReverseSoftLimitEnable(true);
  float kf = 1;
  float kp = 15;
  float ki = 0;
  float kd = 0;
  float velocity = 166 / 4;
  float acceleration = 166 / 4;

  TelescopeMotor.Config_kF(0, kf, 0);
  TelescopeMotor.Config_kP(0, kp, 0);
  TelescopeMotor.Config_kI(0, ki, 0);
  TelescopeMotor.Config_kD(0, kd, 0);

  TelescopeMotor.ConfigMotionCruiseVelocity(velocity);
  TelescopeMotor.ConfigMotionAcceleration(acceleration);

  target = TelescopeMotor.GetSelectedSensorPosition();
}

void SlideSystem::InitDefaultCommand()
{
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
  //SetDefaultCommand(new SlideJoystick());
  //SetDefaultCommand(new SlideControl(target));
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void SlideSystem::MotionMagicControl(double ticks)
{
  TelescopeMotor.Set(ControlMode::MotionMagic, ticks);
}

void SlideSystem::MotionMagicPercent(double percent)
{
  TelescopeMotor.Set(ControlMode::MotionMagic, potMin + (potMax-potMin)*(percent/100));
}

void SlideSystem::MotionMagicDistance(double distance)
{
  double ticks = distance * (totalTicks / 16.25) + startingPoint; //conversion from distance(inches) to ticks   16 inches total throw
  if(ticks > fwdCommandLimit)
  {
    TelescopeMotor.Set(ControlMode::MotionMagic, fwdCommandLimit);
  }
  else if(ticks < revCommandLimit)
  {
    TelescopeMotor.Set(ControlMode::MotionMagic, revCommandLimit);
  }
  else
  {
    TelescopeMotor.Set(ControlMode::MotionMagic, ticks); 
  }
}

void SlideSystem::MotionMagicJoystickControl(double axis)
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
  // TelescopeMotor.Set(ControlMode::PercentOutput, axis*.3);
  target += (axis * 2.2);
  if (target > 490)
  {
    target = 489;
  }
  if (target < 204)
  {
    target = 205;
  }
  TelescopeMotor.Set(ControlMode::MotionMagic, target);
}

void SlideSystem::JoystickControl(double axis)
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
  TelescopeMotor.Set(ControlMode::PercentOutput, axis);
  frc::SmartDashboard::PutNumber("Telescope Potentiometer readout", TelescopeMotor.GetSelectedSensorPosition());
  frc::SmartDashboard::PutNumber("Slide Motor Power", TelescopeMotor.GetMotorOutputPercent());
}

void SlideSystem::ChangeTarget(double newTarget)
{
  target = newTarget * (totalTicks / 16.25) + startingPoint;
  ;
}

double SlideSystem::ReturnDistance()
{
  return (TelescopeMotor.GetSelectedSensorPosition(0) - startingPoint) / (totalTicks / 16.25);
}

void SlideSystem::ResetMinMax(float power)
{
  TelescopeMotor.Set(ControlMode::PercentOutput, power);
  double prevCurrent = TelescopeMotor.GetOutputCurrent();
  TelescopeMotor.ConfigForwardSoftLimitEnable(false);
  TelescopeMotor.ConfigReverseSoftLimitEnable(false);
  while (fabs(fabs(TelescopeMotor.GetOutputCurrent()) - fabs(prevCurrent)) < 2)
  {
    ;
  }
  TelescopeMotor.Set(ControlMode::PercentOutput, 0);
  if (power < 0)
  {
    potMin = TelescopeMotor.GetSelectedSensorPosition();
  }
  if (power > 0)
  {
    potMax = TelescopeMotor.GetSelectedSensorPosition();
  }
  reset = true;
}

void SlideSystem::ResetSlideConfig()
{
  startingPoint = potMin;

  limitOffSet = (potMax - potMin) * (percent / 200);
  fwdLimit = potMax - limitOffSet;
  revLimit = potMin + limitOffSet;

  commandLimitOffset = (potMax - potMin) * (percent / 100);
  fwdCommandLimit = potMax - commandLimitOffset;
  revCommandLimit = potMin + commandLimitOffset;

  totalTicks = potMax - potMin;

  TelescopeMotor.ConfigForwardSoftLimitThreshold(fwdLimit);
  TelescopeMotor.ConfigReverseSoftLimitThreshold(revLimit);
  TelescopeMotor.ConfigForwardSoftLimitEnable(true);
  TelescopeMotor.ConfigReverseSoftLimitEnable(true);
  printf("Slide Max %F \n", potMax);
  printf("Slide Min %F \n", potMin);
  reset = true;
}

void SlideSystem::SetResetFlagFalse()
{
  reset = false;
}

bool SlideSystem::ReturnResetFlag()
{
  return reset;
}