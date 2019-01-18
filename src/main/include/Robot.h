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
#include "subsystems/LiftSystem.h"
#include "subsystems/WristSystem.h"


class Robot : public frc::TimedRobot {
 public:
  static OI oi;
  static DriveSystem driveSystem;
  static ClimbSystem climbSystem;
  static IntakeSystem intakeSystem;
  static LiftSystem liftSystem;
  static WristSystem wristSystem;

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
