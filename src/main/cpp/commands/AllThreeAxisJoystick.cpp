/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/AllThreeAxisJoystick.h"
#include "commands/AllThreeAxisDistance.h"
#include "Robot.h"

AllThreeAxisJoystick::AllThreeAxisJoystick(double xinput, double yinput, double changeX, double changeY)
{
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  initialDelta = globalRobot.slideSystem.ReturnDistance();
  initialTheta = globalRobot.armJointSystem.ReturnAngle();
  x = (b + initialDelta) * cos(initialTheta) - d * sin(initialTheta);
  y = (b + initialDelta) * sin(initialTheta) + d * sin(initialTheta) + a;
  targetx = xinput;
  targety = yinput;
  deltax = changeX;
  deltay = changeY;
}

// Called just before this Command runs the first time
void AllThreeAxisJoystick::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void AllThreeAxisJoystick::Execute()
{
  if((targetx - x) > deltax)
  {
    newx = x + deltax;
  }
  else if((targetx - x) < -deltax)
  {
    newx = x - deltax;
  }
  else
  {
    newx = targetx;
  }

  if((targety - y) > deltay)
  {
    newy = y + deltay;
  }
  else if((targety - y) < -deltay)
  {
    newy = y - deltay;
  }
  else
  {
    newy = targety;
  }
  AllThreeAxisDistance(newx, newy);
}

// Make this return true when this Command no longer needs to run execute()
bool AllThreeAxisJoystick::IsFinished() { return false; }

// Called once after isFinished returns true
void AllThreeAxisJoystick::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AllThreeAxisJoystick::Interrupted() {}
