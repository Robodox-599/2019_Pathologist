/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Command.h>

class AllThreeAxisConstant : public frc::Command
{
public:
  AllThreeAxisConstant(double xinput, double yinput, double changeX, double changeY);
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;

private:
  double a = 34.5;
  //double b = 19.5;
  double b = 19;
  double d = 4.25;
  double x;
  double y;
  double initialDelta;
  double initialTheta;
  double deltay;
  double deltax;
  double targetx;
  double targety;
  double phi;
  double r;
  double alpha;
  double delta;
  double theta;
};
