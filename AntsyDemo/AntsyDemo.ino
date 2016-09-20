/***********************************************************************************
 *     ______            RobotGeek TriHex Demo              ______
 *
 *
 *  External Resources
 *
 ***********************************************************************************/


//Includes
#include <ServoEx.h>
#include "Walking.h"


//####################################################//
// Sensor Setup
//####################################################//


//####################################################//
//Setup
//####################################################//

void setup()
{
  //test
  Serial.begin(9600);

  initializeServos();
  //Set servos to center values
  SetServoCenter(2000);
  delay(1000);
}


//####################################################//
//Main Loop
//####################################################//

void loop()
{

  DriveForward(0, 10, 100);  // DriveForward(TurnLeft/Right, Cycles, speed) Turn Left/Right is -10 through +10. 0 is straight. Speed is 1-100.
  delay(5000);

//  DriveForward(10, 10, 80);  // DriveForward(TurnLeft/Right, Cycles, speed) Turn Left/Right is -10 through +10. 0 is straight. Speed is 1-100.
//  delay(5000);

//  DriveForward(-10, 10, 60);  // DriveForward(TurnLeft/Right, Cycles, speed) Turn Left/Right is -10 through +10. 0 is straight. Speed is 1-100.
//  delay(5000);

//  WalkForward(10, 80);  // WalkForward(Cycles, Speed)
//  delay(1000);
//
//  TurnRight(8, 80);
//  delay(1000);
//
//  TurnLeft(8, 80);
//  delay(1000);
//
//  WalkBackward(10, 80);
//  delay(1000);

}

