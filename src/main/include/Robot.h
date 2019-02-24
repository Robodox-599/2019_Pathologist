/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/TimedRobot.h>
#include <frc/commands/Command.h>
#include <frc/smartdashboard/SendableChooser.h>

#include "OI.h"
#include "subsystems/DriveSystem.h"
#include "subsystems/ClimbSystem.h"
#include "subsystems/IntakeSystem.h"
#include "subsystems/ArmJointSystem.h"
#include "subsystems/WristSystem.h"
#include "subsystems/SlideSystem.h"

class Robot : public frc::TimedRobot {
 public:
  OI oi;
  DriveSystem driveSystem;
  ClimbSystem climbSystem;
  ArmJointSystem armJointSystem;
  IntakeSystem intakeSystem;
  WristSystem wristSystem;
  SlideSystem slideSystem;
  frc::Compressor comp599;

  Robot();
  void RobotInit() override;
  void RobotPeriodic() override;
  void DisabledInit() override;
  void DisabledPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void TestPeriodic() override;

 private:
  // Have it null by default so that if testing teleop it
  // doesn't have undefined behavior and potentially crash.
  frc::Command* m_autonomousCommand = nullptr;
  frc::SendableChooser<frc::Command*> m_chooser;
};

extern Robot globalRobot;