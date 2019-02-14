/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/SlideSystem.h"

SlideSystem::SlideSystem() : Subsystem("SlideSystem"), TelescopeMotor(7)
{
  TelescopeMotor.ConfigSelectedFeedbackSensor(Analog, 0, 0);
  float kf = 0;
  float kp = 0;
  float ki = 0;
  float kd = 0;
  TelescopeMotor.Config_kF(0, kf, 0);
  TelescopeMotor.Config_kP(0, kp, 0);
  TelescopeMotor.Config_kI(0, ki, 0);
  TelescopeMotor.Config_kD(0, kd, 0);

  TelescopeMotor.ConfigMotionCruiseVelocity(0);
  TelescopeMotor.ConfigMotionAcceleration(0);
}

void SlideSystem::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void SlideSystem::MotionMagicControl(float ticks)
{
  TelescopeMotor.Set(ControlMode::MotionMagic, ticks);
}