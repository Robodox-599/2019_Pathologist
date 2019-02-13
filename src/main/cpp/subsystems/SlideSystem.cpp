/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/SlideSystem.h"

SlideSystem::SlideSystem() : Subsystem("SlideSystem"), TelescopeMotor(7), pot(0, 0, 0)
{
  slideTarget = pot.Get();
  avgPotVal = 0;
  potVals[0] = 0;
	potVals[1] = 0;
	potVals[2] = 0;
	potVals[3] = 0;
	potVals[4] = 0;
	potVals[5] = 0;
	potVals[6] = 0;
	potVals[7] = 0;
	potVals[8] = 0;
	potVals[9] = 0;
  slide.integrator = 0;
  slide.kf = 0;
  slide.kp = 0;
  slide.ki = 0;
  slide.kd = 0;
}

void SlideSystem::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void SlideSystem::PositionControl()
{

}