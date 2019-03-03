/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/AllThreeAxisTrimX.h"
#include "Robot.h"

AllThreeAxisTrimX::AllThreeAxisTrimX(double trim)
{
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  Requires(&globalRobot.armJointSystem);
  Requires(&globalRobot.slideSystem);
  Requires(&globalRobot.wristSystem);
  trimVal = trim;
}

// Called just before this Command runs the first time
void AllThreeAxisTrimX::Initialize()
{
  initialDelta = globalRobot.slideSystem.ReturnDistance();
  initialTheta = globalRobot.armJointSystem.ReturnAngle() * 3.14 / 180.0;
  x = (b + initialDelta) * cos(initialTheta) - d * sin(initialTheta);
  y = (b + initialDelta) * sin(initialTheta) + d * sin(initialTheta) + a;

  phi = atan2((y - a), x);
  r = x / cos(phi);
  alpha = asin(d / r);

  delta = r * cos(alpha) - b;
  theta = (phi - alpha) * (180 / 3.14);

  if (!globalRobot.wristSystem.GetWristFlag())
  {
    globalRobot.armJointSystem.MotionMagicDegrees(theta);
    globalRobot.slideSystem.MotionMagicDistance(delta);
    globalRobot.wristSystem.MotionMagicDegrees(-theta+15);
  }
  else
  {
    globalRobot.armJointSystem.MotionMagicDegrees(theta);
    globalRobot.slideSystem.MotionMagicDistance(delta);
    globalRobot.wristSystem.MotionMagicDegrees(-theta + 105);
  }
}

// Called repeatedly when this Command is scheduled to run
void AllThreeAxisTrimX::Execute() {}

// Make this return true when this Command no longer needs to run execute()
bool AllThreeAxisTrimX::IsFinished() { return true; }

// Called once after isFinished returns true
void AllThreeAxisTrimX::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AllThreeAxisTrimX::Interrupted() {}
