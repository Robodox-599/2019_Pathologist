/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ManipulatorPlacement.h"
#include "Robot.h"
#include "commands/AllThreeAxisDistance.h"

ManipulatorPlacement::ManipulatorPlacement(int position) {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  if(position = 2)
  {
    High = true;
    Mid = false;
    Low = false;
  }
  if(position = 1)
  {
    High = false;
    Mid = true;
    Low = false;
  }
  if(position = 0)
  {
    High = false;
    Mid = false;
    Low = true;
  }
}

// Called just before this Command runs the first time
void ManipulatorPlacement::Initialize() 
{
  if(High)
  {
    x = 16;
    if(globalRobot.wristSystem.GetWristFlag() == true)
    {
      y = 80;
    }
    else
    {
      y = 85;
    }
  }
  if(Mid)
  {
    x = 24.02;
    if(globalRobot.wristSystem.GetWristFlag() == true)
    {
      y = 40;
    }
    else
    {
      y = 47; 
    }
  }
  if (Low)
  {
    x = 32;
    if(globalRobot.wristSystem.GetWristFlag() == true)
    {
      y = 18;
    }
    else
    {
      y = 24;
    }
  }
  AllThreeAxisDistance(x, y);
}

// Called repeatedly when this Command is scheduled to run
void ManipulatorPlacement::Execute() {}

// Make this return true when this Command no longer needs to run execute()
bool ManipulatorPlacement::IsFinished() { return true; }

// Called once after isFinished returns true
void ManipulatorPlacement::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ManipulatorPlacement::Interrupted() {}
