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
#include "Gamepad.h"

//####################################################//
// Sensor Setup
//####################################################//


//####################################################//
//Setup
//####################################################//

void setup()
{
  //test
  Serial.begin(38400);

  GamepadEnable();

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

  //Update currentWalkCommand based on gamepad button states
  if ( my_gamepad.update_button_states() )
  {
    if ( my_gamepad.button_press_up() ) currentWalkCommand.fwdBack = 1;
    else if ( my_gamepad.button_press_down() ) currentWalkCommand.fwdBack = -1;
    else currentWalkCommand.fwdBack = 0;

    if ( my_gamepad.button_press_left() ) currentWalkCommand.leftRight = - 10;
    else if ( my_gamepad.button_press_right() ) currentWalkCommand.leftRight = 10;
    else currentWalkCommand.leftRight = 0;
  }
  else
  {
    currentWalkCommand.fwdBack = 0;
    currentWalkCommand.leftRight = 0;
  }

  //Issue gait commands based on currentWalkCommand values
  if ( currentWalkCommand.fwdBack > 0 && currentWalkCommand.leftRight != 0 ) //Moving forward and turning
  {
    DriveForward(currentWalkCommand.leftRight, 0, currentWalkCommand.moveSpeed);
  }
  else if( currentWalkCommand.leftRight < 0 ) //Turning left only
  {
    TurnLeft(0, currentWalkCommand.moveSpeed);
  }
  else if( currentWalkCommand.leftRight > 0 ) //Turning right only
  {
    TurnRight(0, currentWalkCommand.moveSpeed);
  }
  else if ( currentWalkCommand.fwdBack > 0 ) //Moving forward only
  {
    DriveForward(0, 0, currentWalkCommand.moveSpeed);
  }
  else if ( currentWalkCommand.fwdBack < 0 ) //Moving backwards only
  {
    WalkBackward(0, currentWalkCommand.moveSpeed);
  }
  delay(50);

//  DriveForward(5, 10, 100);  // DriveForward(TurnLeft/Right, Cycles, speed) Turn Left/Right is -10 through +10. 0 is straight. Speed is 1-100.
//  delay(5000);

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

