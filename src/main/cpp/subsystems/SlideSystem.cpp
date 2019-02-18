/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/SlideSystem.h"
#include "commands/SlideJoystick.h"
//662, 339, 500
SlideSystem::SlideSystem() : Subsystem("SlideSystem"), TelescopeMotor(3)
{
  TelescopeMotor.ConfigSelectedFeedbackSensor(Analog, 0, 0);
  TelescopeMotor.SetSensorPhase(false);
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
  printf("slide init\n");
}

void SlideSystem::InitDefaultCommand()
{
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
  SetDefaultCommand(new SlideJoystick());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void SlideSystem::MotionMagicControl(double ticks)
{
  TelescopeMotor.Set(ControlMode::MotionMagic, ticks);
}

void SlideSystem::MotionMagicJoystickControl(double axis)
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

  target += (axis * 2.2);

  TelescopeMotor.Set(ControlMode::MotionMagic, target + 500);
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