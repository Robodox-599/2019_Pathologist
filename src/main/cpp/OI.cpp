/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OI.h"
#include "commands/Ball_Intake.h"
#include "commands/Ball_Outtake.h"
#include "commands/Ball_Stop.h"
#include "commands/Hatch_Release.h"
#include "commands/Hatch_Reset.h"
#include "commands/AllPistonsDown.h"
#include "commands/FrontPistonsUp.h"
#include "commands/RearPistonUp.h"
#include "commands/SlideControl.h"

OI::OI()
{
  xbox = new frc::Joystick(0);
  atk3 = new frc::Joystick(1);
  // Process operator interface input here.
  frc::JoystickButton *Buttonx1 = new frc::JoystickButton(xbox, 1);
  frc::JoystickButton *Buttonx2 = new frc::JoystickButton(xbox, 2);
  frc::JoystickButton *Buttonx3 = new frc::JoystickButton(xbox, 3);
  frc::JoystickButton *Buttonx4 = new frc::JoystickButton(xbox, 4);
  frc::JoystickButton *Buttonx5 = new frc::JoystickButton(xbox, 5);
  frc::JoystickButton *Buttonx6 = new frc::JoystickButton(xbox, 6);
  frc::JoystickButton *Buttonx7 = new frc::JoystickButton(xbox, 7);
  frc::JoystickButton *Buttonx8 = new frc::JoystickButton(xbox, 8);
  Buttonx1->WhenPressed(new SlideControl(498));
  Buttonx2->WhenPressed(new SlideControl(550));
  Buttonx3->WhenPressed(new SlideControl(400));
  Buttonx4->WhenPressed(new Hatch_Release());
  Buttonx5->WhenPressed(new Hatch_Reset());
  Buttonx6->WhenPressed(new AllPistonsDown());
  Buttonx7->WhenPressed(new FrontPistonsUp());
  Buttonx8->WhenPressed(new RearPistonUp());
}
