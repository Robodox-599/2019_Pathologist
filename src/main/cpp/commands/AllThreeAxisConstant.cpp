/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/AllThreeAxisConstant.h"
#include "commands/AllThreeAxisDistance.h"
#include "Robot.h"

AllThreeAxisConstant::AllThreeAxisConstant(double xinput, double yinput, double changeX, double changeY)
{
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  Requires(&globalRobot.armJointSystem);
  Requires(&globalRobot.slideSystem);
  Requires(&globalRobot.wristSystem);

  targetx = xinput;
  targety = yinput;
  deltax = changeX;
  deltay = changeY;
}

// Called just before this Command runs the first time
void AllThreeAxisConstant::Initialize()
{
  initialDelta = globalRobot.slideSystem.ReturnDistance();
  initialTheta = globalRobot.armJointSystem.ReturnAngle()*3.14/180;
  x = (b + initialDelta) * cos(initialTheta) - d * sin(initialTheta);
  y = (b + initialDelta) * sin(initialTheta) + d * sin(initialTheta) + a;
  printf("x %F \n", x);
  printf("y %F \n", y);
  printf("initial Delta %F \n", initialDelta);
}

// Called repeatedly when this Command is scheduled to run
void AllThreeAxisConstant::Execute()
{
  if((targetx - x) > deltax)
  {
    x += deltax;
  }
  else if((targetx - x) < -deltax)
  {
    x -= deltax;
  }
  else
  {
    x = targetx;
  }

  if((targety - y) > deltay)
  {
    y += deltay;
  }
  else if((targety - y) < -deltay)
  {
    y -= deltay;
  }
  else
  {
    y = targety;
  }

  phi = atan2((y-a), x);
  r = x/cos(phi);
  alpha = asin(d/r);
  
  delta = r*cos(alpha)-b;
  theta = (phi-alpha)*(180/3.14);

  // globalRobot.slideSystem.ChangeTarget(delta);
  // globalRobot.armJointSystem.ChangeTarget(theta);


}

// Make this return true when this Command no longer needs to run execute()
bool AllThreeAxisConstant::IsFinished() { return false; }

// Called once after isFinished returns true
void AllThreeAxisConstant::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AllThreeAxisConstant::Interrupted() {}
