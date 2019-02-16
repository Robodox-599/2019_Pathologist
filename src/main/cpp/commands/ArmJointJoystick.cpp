/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ArmJointJoystick.h"
#include "Robot.h"

ArmJointJoystick::ArmJointJoystick() {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  Requires(&globalRobot.armJointSystem);
}

// Called just before this Command runs the first time
void ArmJointJoystick::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void ArmJointJoystick::Execute() {globalRobot.armJointSystem.JoystickControl(globalRobot.oi.xbox->GetRawAxis(1));}

// Make this return true when this Command no longer needs to run execute()
bool ArmJointJoystick::IsFinished() { return false; }

// Called once after isFinished returns true
void ArmJointJoystick::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ArmJointJoystick::Interrupted() {}
