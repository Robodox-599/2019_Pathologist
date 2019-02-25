/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/AllThreeAxisDistance.h"
#include "Robot.h"

AllThreeAxisDistance::AllThreeAxisDistance(double x, double y) {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  Requires(&globalRobot.armJointSystem);
  Requires(&globalRobot.slideSystem);
  Requires(&globalRobot.wristSystem);

  phi = atan2(y-a, x);
  r = x/cos(phi);
  alpha = asin(d/r);
  
  delta = r*cos(alpha)-b;
  theta = phi-alpha;
}

// Called just before this Command runs the first time
void AllThreeAxisDistance::Initialize() 
{
  globalRobot.armJointSystem.MotionMagicDegrees(theta);
  globalRobot.slideSystem.MotionMagicDistance(delta);
  globalRobot.wristSystem.MotionMagicDegrees(theta);
}

// Called repeatedly when this Command is scheduled to run
void AllThreeAxisDistance::Execute() {}

// Make this return true when this Command no longer needs to run execute()
bool AllThreeAxisDistance::IsFinished() { return false; }

// Called once after isFinished returns true
void AllThreeAxisDistance::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AllThreeAxisDistance::Interrupted() {}
