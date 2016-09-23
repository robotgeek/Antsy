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
#include "Sounds.h"
#include "Lights.h"
#include "LightSensors.h"

bool lightSensorsEnabled = false;

void sing_test()
{
  sing( S_connection  ); delay(500);
  sing( S_disconnection ); delay(500);
  sing( S_buttonPushed  ); delay(500);
  sing( S_mode1     ); delay(500);
  sing( S_mode2     ); delay(500);
  sing( S_mode3     ); delay(500);
  //sing( S_surprise    ); delay(500);
  sing( S_OhOoh     ); delay(500);
  //sing( S_OhOoh2    ); delay(500);
  sing( S_cuddly    ); delay(500);
  //sing( S_sleeping    ); delay(500);
  sing( S_happy     ); delay(500);
  sing( S_superHappy  ); delay(500);
  sing( S_happy_short   ); delay(500);
  //sing( S_sad       ); delay(500);
  sing( S_confused    ); delay(500);
  sing( S_insect1     ); delay(500);
  sing( S_insect2     ); delay(500);
  sing( S_insect3     ); delay(500);
}
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

  SoundEnable();
  SoundPlay(LAUGH);

  LightsEnable();

  initializeServos();
  //Set servos to center values
  SetServoCenter(2000);
  delay(1000);

  sing_test(); //Just a test
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

    //Check for select press.. If true toggle light sensing mode
    if ( my_gamepad.button_press_select() )
    {
      if ( lightSensorsEnabled == true )
      {
        lightSensorsEnabled = false;
        SoundPlay(DOWN);
      }
      else
      {
        lightSensorsEnabled = true;
        SoundPlay(UP);
      }
      delay(1000);
      my_gamepad.update_button_states();
    }

    if ( my_gamepad.button_press_b() )
    {
      SoundPlay(BEEPS);
      Wiggle(3, currentWalkCommand.moveSpeed);
      my_gamepad.update_button_states();
    }
    if ( my_gamepad.button_press_a() )
    {
      SoundPlay(OHH);
      Shiver(2, currentWalkCommand.moveSpeed);
      my_gamepad.update_button_states();
    }
    if ( my_gamepad.button_press_ta() )
    {
      SoundPlay(LAUGH);
      Giggle(2, currentWalkCommand.moveSpeed);
      my_gamepad.update_button_states();
    }
    if ( my_gamepad.button_press_tb() )
    {
      SoundPlay(WHISTLE);
      Wave(4, currentWalkCommand.moveSpeed);
      my_gamepad.update_button_states();
    }
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

  //Else there are no currentWalkCommand values.. perform light seeking if enabled
  else if ( lightSensorsEnabled == true )
  {
    switch( lightSensors.SeekLight() )
    {
    case LightSensors::WALK_FWD:
      LightsSet( HIGH, HIGH );
      DriveForward(0, 0, currentWalkCommand.moveSpeed);
      break;
    case LightSensors::WALK_LEFT:
      LightsSet( HIGH, LOW );
      TurnLeft(0, currentWalkCommand.moveSpeed);
      break;
    case LightSensors::WALK_RIGHT:
      LightsSet( LOW, HIGH );
      TurnRight(0, currentWalkCommand.moveSpeed);
      break;
    case LightSensors::WALK_STOP:
      LightsSet( LOW, LOW );
      break;
    }
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

