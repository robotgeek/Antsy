/***********************************************************************************
 *     ______            RobotGeek TriHex Demo              ______
 *
 *
 *  External Resources
 *
 ***********************************************************************************/


//Includes
#include <Servo.h>
#include "Walking.h"


//####################################################//
// Sensor Setup
//####################################################//



//####################################################//
//Setup
//####################################################//

void setup()
{
  Serial.begin(9600);
  //initialize servo objects, set min/max range values.
  centerServo.attach(CENTER, CENTER_MIN, CENTER_MAX);      // attaches/activates the center servo, sets min/max values
  rightServo.attach(RIGHT, RIGHT_MIN, RIGHT_MAX);  // attaches/activates the right servo, sets min/max values
  leftServo.attach(LEFT, LEFT_MIN, LEFT_MAX);  // attaches/activates the left servo, sets min/max values

  //use the writeMicroseconds to set the servos to their default positions
  centerServo.writeMicroseconds(centerServoValue);
  rightServo.writeMicroseconds(rightServoValue);
  leftServo.writeMicroseconds(leftServoValue);
  delay(1000);
}


//####################################################//
//Main Loop
//####################################################//

void loop()
{

  DriveForward(10, 10);  // DriveForward(TurnLeft/Right, cycles) Turn Left/Right is -10 through +10. 0 is straight.
  delay(5000);

  DriveForward(-10, 10);  // DriveForward(TurnLeft/Right, cycles) Turn Left/Right is -10 through +10. 0 is straight.
  delay(5000);


//  WalkForward(10);
//  delay(1000);
//
//  TurnRight(8);
//  delay(1000);
//
//  WalkForward(10);
//  delay(1000);
//
//  TurnLeft(8);
//  delay(1000);
//
//  WalkForward(10);
//  delay(1000);

//  WalkBackward(10);
//  delay(1000);

}

