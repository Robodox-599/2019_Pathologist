/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/LiftSystem.h"
#include <math>

LiftSystem::LiftSystem() : Subsystem("ExampleSubsystem"), LiftMotor(3), power = 0, degree = 0 {
  LiftMotor.ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Absolute);
}

void LiftSystem::InitDefaultCommand() {
 
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}
 
 void LiftSystem::Thing(double kfU, double kfD, double target)
 {
   if(target = negative_int_value)
   {
   angle = LiftMotor.GetSelectedSensorPosition();
   angle = angle * 2048/pi;
   power = kfU * math.cos(degree) * angle;
   return;
   }
   angle = LiftMotor.GetSelectedSensorPosition();
   angle = angle * 2048/pi;
   power = kfD * math.cos(degree) * angle;
 }

 //kf cost r

  


// Put methods for controlling this subsystem
// here. Call these from Commands.
