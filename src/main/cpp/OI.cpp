/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OI.h"

#include <frc/WPILib.h>

OI::OI()
{
  xbox = new frc::Joystick(0);
	frc::JoystickButton* Buttonx1 = new frc::JoystickButton(xbox, 1);
  atk3 = new frc::Joystick(1);
	frc::JoystickButton* Button1 = new frc::JoystickButton(atk3, 1);
}
