/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/AutoHome.h"
#include "commands/SlideReconfig.h"
#include "commands/SlideResetMinMax.h"
#include "commands/WristReconfig.h"
#include "commands/WristResetMinMax.h"
#include "commands/WristControl.h"
#include "commands/ArmJointControl.h"
#include "commands/SlidePercent.h"
#include "commands/WristPercent.h"

AutoHome::AutoHome() {
  // Add Commands here:
  // e.g. AddSequential(new Command1());
  //      AddSequential(new Command2());
  // these will run in order.

  // To run multiple commands at the same time,
  // use AddParallel()
  // e.g. AddParallel(new Command1());
  //      AddSequential(new Command2());
  // Command1 and Command2 will run in parallel.

  // A command group will require all of the subsystems that each member
  // would require.
  // e.g. if Command1 requires chassis, and Command2 requires arm,
  // a CommandGroup containing them would require both the chassis and the
  // arm.
  AddSequential(new ArmJointControl(386));
  AddSequential(new WristControl(-2000));
  AddSequential(new SlideResetMinMax(-0.20));
  AddSequential(new SlideResetMinMax(0.20));
  AddSequential(new SlideReconfig());
  AddSequential(new SlidePercent(75));
  AddSequential(new WristResetMinMax(-0.25));
  AddSequential(new WristResetMinMax(0.35));
  AddSequential(new WristReconfig());
  AddSequential(new WristPercent(50));
}
