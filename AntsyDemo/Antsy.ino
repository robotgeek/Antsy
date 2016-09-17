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
//#include <SharpIR.h>

//####################################################//
// Sensor Setup
//####################################################//

#define ir A0
#define model 1080
int irSensorValue;  //variables to hold the last reading from the analog IR sensor.
int irSensorThreshold = 30;
int randomValue;
//SharpIR sharp(ir, 25, 93, model);



//####################################################//
//Setup
//####################################################//

void setup() 
{ 
  pinMode (ir, INPUT);  //initialize IR sensor analog input pin.
    
  //initialize servo objects, set min/max range values.
  centerServo.attach(CENTER, CENTER_MIN, CENTER_MAX);      // attaches/activates the center servo, sets min/max values
  rightServo.attach(RIGHT, RIGHT_MIN, RIGHT_MAX);  // attaches/activates the right servo, sets min/max values
  leftServo.attach(LEFT, LEFT_MIN, LEFT_MAX);  // attaches/activates the left servo, sets min/max values
  
  //use the writeMicroseconds to set the servos to their default positions
  centerServo.writeMicroseconds(centerServoValue); 
  rightServo.writeMicroseconds(rightServoValue);
  leftServo.writeMicroseconds(leftServoValue);
} 


//####################################################//
//Main Loop
//####################################################//

void loop() 
{ 
  
  WalkForward(10);
  delay(1000);
  
  TurnRight(8);
  delay(1000);

  WalkForward(10);
  delay(1000);

  TurnLeft(8);
  delay(1000);
  
  WalkForward(10);
  delay(1000);  

//  WalkBackward(10);
//  delay(1000);
// SharpIRObstacleAvoid();
}

//####################################################//
//Sharp IR Obstacle Avoidance Function
//####################################################//
/*
void SharpIRObstacleAvoid()
{
irSensorValue = sharp.distance();

  if(irSensorValue > irSensorThreshold)
  {
    WalkForward(3);
  }
  else if(irSensorValue < irSensorThreshold)
  {
    WalkBackward(3);
    randomValue = random(1, 10);
    
    if (randomValue <= 5)
    {
      TurnLeft(8);
    }
    else if (randomValue > 5)
    {
      TurnRight(8);
    }
  }
}
*/
