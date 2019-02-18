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
#include "commands/ClimbPistonsDown.h"
#include "commands/ClimbFrontPistonsUp.h"
#include "commands/ClimbRearPistonUp.h"
#include "commands/SlideControl.h"
#include "commands/ArmJointControl.h"
#include "commands/WristControl.h"

OI::OI()
{
  xbox = new frc::Joystick(0);
  atk3 = new frc::Joystick(1);
  // Process operator interface input here.
  frc::JoystickButton *Buttonx1_A = new frc::JoystickButton(xbox, 1);
  frc::JoystickButton *Buttonx2_B = new frc::JoystickButton(xbox, 2);
  frc::JoystickButton *Buttonx3_X = new frc::JoystickButton(xbox, 3);
  frc::JoystickButton *Buttonx4_Y = new frc::JoystickButton(xbox, 4);
  frc::JoystickButton *Buttonx5_LB = new frc::JoystickButton(xbox, 5);
  frc::JoystickButton *Buttonx6_RB = new frc::JoystickButton(xbox, 6);
  frc::JoystickButton *Buttonx7_Start = new frc::JoystickButton(xbox, 7);
  frc::JoystickButton *Buttonx8_Select = new frc::JoystickButton(xbox, 8);
  frc::JoystickButton *Button4 = new frc::JoystickButton(atk3, 4);
  frc::JoystickButton *Button2 = new frc::JoystickButton(atk3, 2);
  frc::JoystickButton *Button3 = new frc::JoystickButton(atk3, 3);
  Buttonx1_A->WhenPressed(new SlideControl(498));
  Buttonx2_B->WhenPressed(new SlideControl(550));
  Buttonx3_X->WhenPressed(new SlideControl(400));
  Buttonx4_Y->WhenPressed(new ArmJointControl(272));
  Buttonx5_LB->WhenPressed(new ArmJointControl(410));
  Buttonx6_RB->WhenPressed(new ArmJointControl(160));
  Buttonx7_Start->WhenPressed(new ClimbFrontPistonsUp());
  Buttonx8_Select->WhenPressed(new ClimbRearPistonUp());
  Button2->WhenPressed(new WristControl(1629));
  Button3->WhenPressed(new WristControl(-700));
  Button4->WhenPressed(new WristControl(2400));
}
