/******************************************************************************
Walking.cpp
 *****************************************************************************/

#include <Servo.h> 
#include <Arduino.h>
#include "Walking.h"

//####################################################//
//Servo Objects
//####################################################//

Servo centerServo, rightServo, leftServo;  // create servo objects to control the center, right, and left servos.

//####################################################//
//Center Servo Values & Ranges
//####################################################//

int centerShiftRange = 400;  //Range of this value should be 300-400. Controls the amount of vertical lift provided by the center servo.
int centerRightDown = CENTER_CENTER - centerShiftRange;
int centerLeftDown = CENTER_CENTER + centerShiftRange;


//####################################################//
//Right Servo Values & Ranges
//####################################################//

int rightSweepRange = 200;  //Range of this value should be 100-200. Controls the distance of horizontal sweep motion.
int rightFrontSweep = RIGHT_CENTER + rightSweepRange;
int rightBackSweep = RIGHT_CENTER - rightSweepRange;


//####################################################//
//Left Servo Values & Ranges
//####################################################//

int leftSweepRange = 200;  //Range of this value should be 100-200. Controls the distance of horizontal sweep motion.
int leftFrontSweep = LEFT_CENTER - leftSweepRange;
int leftBackSweep = LEFT_CENTER + leftSweepRange;


// Placeholder for interpolation implementation.
int centerServoValue = 1500;   //current positional value being sent to the center servo. 
int rightServoValue = 1500;  //current positional value being sent to the right servo. 
int leftServoValue = 1500;  //current positional value being sent to the left servo. 

// Delay values for walking sequences.
int delayValue = 180;
int delayValue2 = 250;


//####################################################//
//FORWARD WALKING POSES
//####################################################//

void RightUpForward()
{
  centerServo.writeMicroseconds(centerRightDown); 
  delay(delayValue);  
  rightServo.writeMicroseconds(rightFrontSweep);
  leftServo.writeMicroseconds(leftBackSweep);
  delay(delayValue2); 
}

void LeftUpForward()
{
  centerServo.writeMicroseconds(centerLeftDown); 
  delay(delayValue); 
  rightServo.writeMicroseconds(rightBackSweep);
  leftServo.writeMicroseconds(leftFrontSweep);
  delay(delayValue2); 
}

void RightCenterForward()
{
  centerServo.writeMicroseconds(CENTER_CENTER); 
  rightServo.writeMicroseconds(rightFrontSweep);
  leftServo.writeMicroseconds(leftBackSweep);
  delay(delayValue2); 
}

void LeftCenterForward()
{
  centerServo.writeMicroseconds(CENTER_CENTER); 
  rightServo.writeMicroseconds(rightBackSweep);
  leftServo.writeMicroseconds(leftFrontSweep);
  delay(delayValue2); 
}

void Center()
{
  centerServo.writeMicroseconds(CENTER_CENTER); 
  rightServo.writeMicroseconds(RIGHT_CENTER);
  leftServo.writeMicroseconds(LEFT_CENTER);
  delay(delayValue2); 
}

//####################################################//
//BACKWARD WALKING POSES
//####################################################//

void RightUpBackward()
{
  centerServo.writeMicroseconds(centerRightDown); 
  rightServo.writeMicroseconds(rightBackSweep);
  leftServo.writeMicroseconds(leftFrontSweep);
  delay(delayValue); 
}

void LeftUpBackward()
{
  centerServo.writeMicroseconds(centerLeftDown); 
  rightServo.writeMicroseconds(rightFrontSweep);
  leftServo.writeMicroseconds(leftBackSweep);
  delay(delayValue); 
}

void RightCenterBackward()
{
  centerServo.writeMicroseconds(CENTER_CENTER); 
  rightServo.writeMicroseconds(rightBackSweep);
  leftServo.writeMicroseconds(leftFrontSweep);
  delay(delayValue); 
}

void LeftCenterBackward()
{
  centerServo.writeMicroseconds(CENTER_CENTER); 
  rightServo.writeMicroseconds(rightFrontSweep);
  leftServo.writeMicroseconds(leftBackSweep);
  delay(delayValue); 
}



//####################################################//
// RIGHT TURN WALKING POSES
//####################################################//

void RightUpTurnRight()
{
  centerServo.writeMicroseconds(centerRightDown); 
  rightServo.writeMicroseconds(rightBackSweep);
  leftServo.writeMicroseconds(leftBackSweep);
  delay(delayValue); 
}

void LeftUpTurnRight()
{
  centerServo.writeMicroseconds(centerLeftDown); 
  rightServo.writeMicroseconds(rightFrontSweep);
  leftServo.writeMicroseconds(leftFrontSweep);
  delay(delayValue); 
}

void RightCenterTurnRight()
{
  centerServo.writeMicroseconds(CENTER_CENTER); 
  rightServo.writeMicroseconds(rightBackSweep);
  leftServo.writeMicroseconds(leftBackSweep);
  delay(delayValue); 
}

void LeftCenterTurnRight()
{
  centerServo.writeMicroseconds(CENTER_CENTER); 
  rightServo.writeMicroseconds(rightFrontSweep);
  leftServo.writeMicroseconds(leftFrontSweep);
  delay(delayValue); 
}


//####################################################//
//LEFT TURN WALKING POSES
//####################################################//

void RightUpTurnLeft()
{
  centerServo.writeMicroseconds(centerRightDown); 
  rightServo.writeMicroseconds(rightFrontSweep);
  leftServo.writeMicroseconds(leftFrontSweep);
  delay(delayValue); 
}

void LeftUpTurnLeft()
{
  centerServo.writeMicroseconds(centerLeftDown); 
  rightServo.writeMicroseconds(rightBackSweep);
  leftServo.writeMicroseconds(leftBackSweep);
  delay(delayValue); 
}

void RightCenterTurnLeft()
{
  centerServo.writeMicroseconds(CENTER_CENTER); 
  rightServo.writeMicroseconds(rightFrontSweep);
  leftServo.writeMicroseconds(leftFrontSweep);
  delay(delayValue); 
}

void LeftCenterTurnLeft()
{
  centerServo.writeMicroseconds(CENTER_CENTER); 
  rightServo.writeMicroseconds(rightBackSweep);
  leftServo.writeMicroseconds(leftBackSweep);
  delay(delayValue); 
}


//####################################################//
//WALK CYCLE FUNCTIONS
//####################################################//

void TurnRight(int cycle)
{
  int i = 0;
  while(i <= cycle)
  {
    LeftUpTurnRight();
    LeftCenterTurnRight();
    RightUpTurnRight();  
    RightCenterTurnRight();  
    i++;
  }
}

void TurnLeft(int cycle)
{
  int i = 0;
  while(i <= cycle)
  {
    LeftUpTurnLeft();
    LeftCenterTurnLeft();
    RightUpTurnLeft();  
    RightCenterTurnLeft();
    i++;
  }
}

void WalkForward(int cycle)
{
  int i = 0;
  while(i <= cycle)
  {
    RightUpForward();
    //RightCenterForward();
    LeftUpForward();
    //LeftCenterForward();
    i++;
  }
}

void WalkBackward(int cycle)
{
  int i = 0;
  while(i <= cycle)
  {
    RightUpBackward();
    RightCenterBackward();
    LeftUpBackward();
    LeftCenterBackward();
    i++;
  }
}
