/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OI.h"
#include "commands/Ball_Intake.h"
#include "commands/ClimbPistonsDown.h"
#include "commands/ClimbFrontPistonsUp.h"
#include "commands/ClimbRearPistonUp.h"
#include "commands/SlideControl.h"
#include "commands/ArmJointControl.h"
#include "commands/WristControl.h"
#include "commands/ClimbPistonsUp.h"
#include "commands/AllThreeAxis.h"
#include "commands/AllThreeAxisDistance.h"
#include "commands/AllThreeAxisConstant.h"
#include "commands/AutoHome.h"
#include "commands/WristFlag.h"
#include "commands/WristScoreMovement.h"
#include "commands/IntakeFlag.h"
#include "commands/DriveScoreFlag.h"
#include "commands/WristMotorRest.h"
#include "commands/HatchHook.h"
#include "commands/DriveShift.h"

OI::OI()
{
  xbox = new frc::Joystick(0);
  atk3 = new frc::Joystick(1);
// Process operator interface input here.
#if 1
  frc::JoystickButton *Buttonx1_A = new frc::JoystickButton(xbox, 1);
  frc::JoystickButton *Buttonx2_B = new frc::JoystickButton(xbox, 2);
  frc::JoystickButton *Buttonx3_X = new frc::JoystickButton(xbox, 3);
  frc::JoystickButton *Buttonx4_Y = new frc::JoystickButton(xbox, 4);
  frc::JoystickButton *Buttonx5_LB = new frc::JoystickButton(xbox, 5);
  frc::JoystickButton *Buttonx6_RB = new frc::JoystickButton(xbox, 6);
  frc::JoystickButton *Buttonx7_Start = new frc::JoystickButton(xbox, 7);
  frc::JoystickButton *Buttonx8_Select = new frc::JoystickButton(xbox, 8);
  frc::JoystickButton *Buttonx9_LeftJoystick = new frc::JoystickButton(xbox, 9);
  frc::JoystickButton *Buttonx10_RightJoystick = new frc::JoystickButton(xbox, 10);
  frc::JoystickButton *Button2 = new frc::JoystickButton(atk3, 2);
  frc::JoystickButton *Button3 = new frc::JoystickButton(atk3, 3);
  frc::JoystickButton *Button4 = new frc::JoystickButton(atk3, 4);
  frc::JoystickButton *Button5 = new frc::JoystickButton(atk3, 5);
  // Buttonx1_A->WhenPressed(new Ball_Intake(.3));
  // Buttonx2_B->WhenPressed(new Ball_Outtake(-.3));
  // Buttonx3_X->WhenPressed(new Ball_Stop());
  // Buttonx4_Y->WhenPressed(new Hatch_Release());
  // Buttonx5_LB->WhenPressed(new Hatch_Reset());
  // Buttonx1_A->WhenPressed(new AllThreeAxis(422, 383, 465)); //Low
  // Buttonx2_B->WhenPressed(new AllThreeAxis(650, 320, 449)); //Mid
  // Buttonx3_X->WhenPressed(new AllThreeAxis(766, 486, 451)); //High

  //Distance (x,y)
  //High Hatch (36, 75)     Ball (36.2, 83.5)
  //Mid Hatch (24.02, 47)        (28.4, 55.5)
  //Low Hatch (26.97, 19)        (21.02, 27.5)

  // Buttonx1_A->WhenPressed(new AllThreeAxisDistance(26.97, 19)); //Low Hatch

  Buttonx1_A->WhenPressed(new WristScoreMovement());
  Buttonx2_B->WhenPressed(new AllThreeAxisDistance(32, 22.5));
  Buttonx4_Y->WhenPressed(new AllThreeAxisDistance(24.02, 47)); //Mid Hatch
  Buttonx3_X->WhenPressed(new AllThreeAxisDistance(10, 75)); //High Hatch

  Button2->WhenPressed(new ClimbPistonsDown());  
  Button3->WhenPressed(new ClimbPistonsUp());
  Button4->WhenPressed(new ClimbRearPistonUp());
  Button5->WhenPressed(new ClimbFrontPistonsUp());

  // Buttonx1_A->WhenPressed(new ButtonACommand());

  //Buttonx5_LB->WhenPressed(new AutoHome());
  Buttonx5_LB->WhenPressed(new IntakeFlag());
  //Buttonx5_LB->WhenPressed(new Ball_Intake(0.2));
  Buttonx6_RB->WhenPressed(new WristFlag());

  Buttonx7_Start->WhenPressed(new AutoHome());

  Buttonx8_Select->WhenPressed(new AllThreeAxisDistance(30, 13.5));

  Buttonx9_LeftJoystick->WhenPressed(new DriveShift());
  Buttonx10_RightJoystick->WhenPressed(new WristMotorRest());

  // Button2->WhenPressed(new AllThreeAxisConstant(32, 27, .5, .5));
  // Button3->WhenPressed(new AllThreeAxisConstant(32, 30, .5, .5));
  // Button4->WhenPressed(new AllThreeAxisConstant(32, 45, .5, .5));

  // Buttonx4_Y->WhenPressed(new ArmJointControl(901));
  // Buttonx5_LB->WhenPressed(new ArmJointControl(501));
  //Buttonx6_RB->WhenPressed(new ArmJointControl(160));
  //Buttonx5_LB->WhenPressed(new ClimbPistonsUp());
  // Buttonx6_RB->WhenPressed(new ClimbPistonsDown());
  //Buttonx7_Start->WhenPressed(new AllThreeAxisDistance(-3, 0));
  // Button2->WhenPressed(new SlideControl(500));
  // Button3->WhenPressed(new WristControl(439));
//422, 433, 472  Low Hatch
//650, 653, 449  Mid Hatch
//766, 793, 451  High Hatch
#else
  struct
  {
    frc::Joystick *joystick;
    int button;
    frc::Command *control;
  } combos[] =
  {
    {xbox, 1, new Ball_Outtake(1)},       // A
    {xbox, 2, new SlideControl(329)},     // B
    {xbox, 3, new SlideControl(662)},     // X
    {xbox, 4, new ArmJointControl(272)},  // Y
    {xbox, 5, new ArmJointControl(410)},  // LB
    {xbox, 6, new ArmJointControl(160)},  // RB
    {xbox, 7, new ClimbFrontPistonsUp()}, // Start
    {xbox, 8, new ClimbRearPistonUp()},   // Select
    {atk3, 2, new WristControl(925)},
    {atk3, 3, new WristControl(964)},
    {atk3, 4, new WristControl(1003)},
  };
for (int i = 0; i < sizeof(combos) / sizeof(combos[0]); ++i)
{
  const auto &combo  = combos[i];
  (new frc::JoystickButton(combo.joystick, combo.button))->WhenPressed(combo.control);
}
#endif
}
