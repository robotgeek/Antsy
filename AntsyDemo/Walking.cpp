/******************************************************************************
Walking.cpp
 *****************************************************************************/

#include <Servo.h> 
#include <Arduino.h>
#include "Walking.h"

#define DEBUG

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
int rightSweepRangeOffset;
int rightFrontSweep = RIGHT_CENTER + rightSweepRange;  //1700
int rightBackSweep = RIGHT_CENTER - rightSweepRange;  //1300


//####################################################//
//Left Servo Values & Ranges
//####################################################//

int leftSweepRange = 200;  //Range of this value should be 100-200. Controls the distance of horizontal sweep motion.
int leftSweepRangeOffset;
int leftFrontSweep = LEFT_CENTER - leftSweepRange;  //1300
int leftBackSweep = LEFT_CENTER + leftSweepRange;  //1700


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

void RightUpForward(int leftOffset, int rightOffset)
{
  centerServo.writeMicroseconds(centerRightDown); 
  delay(delayValue);  
  rightServo.writeMicroseconds(rightFrontSweep - rightOffset);  //1700 normally
  leftServo.writeMicroseconds(leftBackSweep - leftOffset);    //1700 normally
  delay(delayValue2); 
  
  #ifdef DEBUG
  int tempRight = (rightFrontSweep - rightOffset);
  int tempLeft = (leftBackSweep - leftOffset);
  Serial.println("RightUpForward");
  Serial.print("Right: ");
  Serial.println(tempRight); 
  Serial.println(" ");
  Serial.print("Left: ");
  Serial.println(tempLeft);  
  Serial.println(" ");
  #endif
}

void LeftUpForward(int leftOffset, int rightOffset)
{
  centerServo.writeMicroseconds(centerLeftDown); 
  delay(delayValue); 
  rightServo.writeMicroseconds(rightBackSweep + rightOffset);  //1300 normally
  leftServo.writeMicroseconds(leftFrontSweep + leftOffset);  //1300 normally 
  delay(delayValue2); 
  
  #ifdef DEBUG
  int tempRight = (rightBackSweep + rightOffset);
  int tempLeft = (leftFrontSweep + leftOffset);
  Serial.println("LeftUpForward");
  Serial.print("Right: ");
  Serial.println(tempRight); 
  Serial.println(" ");
  Serial.print("Left: ");
  Serial.println(tempLeft);  
  Serial.println(" ");
  #endif

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
    RightUpForward(0, 0);
    //RightCenterForward();
    LeftUpForward(0, 0);
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

void DriveForward(int turn, int cycle)
{
  turn = constrain(turn, -10, +10);
  int i = 0;
  while(i <= cycle)
  {
    if (turn >= 1)  //Drive Right
    {
    RightUpForward(0, (turn * 15));
    //RightCenterForward();
    LeftUpForward(0, (turn * 15));
    //LeftCenterForward();
    }
    
    
    if (turn <= -1)  //Drive Left
    {
    RightUpForward((turn * -15), 0);
    //RightCenterForward();
    LeftUpForward((turn * -15), 0);
    //LeftCenterForward();
    }
    

    if (turn == 0)  //Drive Straight
    {
    RightUpForward(0, 0);
    //RightCenterForward();
    LeftUpForward(0, 0);
    //LeftCenterForward();
    }
    
    i++;
  }
}
