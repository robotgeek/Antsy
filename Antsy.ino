/***********************************************************************************
 *     ______            RobotGeek TriHex Demo              ______
 *
 *
 *  External Resources
 *
 ***********************************************************************************/


//Includes
#include <Servo.h> 
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
//Servo Pin Defines & Servo Objects
//####################################################//

#define CENTER 9       //Center Servo Digital Pin Assignment
#define RIGHT 10       //Right Servo Digital Pin Assignment
#define LEFT 11        //Left Servo Digital Pin Assignment

Servo centerServo, rightServo, leftServo;  // create servo objects to control the center, right, and left servos.


//####################################################//
//Center Servo Values & Ranges
//####################################################//

// Min/Max pulse values in microseconds to send to the servo
#define CENTER_MIN     1050  
#define CENTER_MAX     1950 
#define CENTER_CENTER  1500

int centerShiftRange = 400;  //Range of this value should be 300-400. Controls the amount of vertical lift provided by the center servo.
int centerRightDown = CENTER_CENTER - centerShiftRange;
int centerLeftDown = CENTER_CENTER + centerShiftRange;

// Legacy defines, for reference.
#define CENTER_RIGHTDOWN 1100  //Center vertical leg right side downward motion value. Lower value moves right side down further.
#define CENTER_LEFTDOWN  1900  //Center vertical leg left side downward motion value. Higher value moves the left side down further.


//####################################################//
//Right Servo Values & Ranges
//####################################################//

// Min/Max pulse values in microseconds to send to the servo
#define RIGHT_MIN     1300     
#define RIGHT_MAX     1700    
#define RIGHT_CENTER  1500

int rightSweepRange = 200;  //Range of this value should be 100-200. Controls the distance of horizontal sweep motion.
int rightFrontSweep = RIGHT_CENTER + rightSweepRange;
int rightBackSweep = RIGHT_CENTER - rightSweepRange;

// Legacy defines, for reference.
#define RIGHT_FRONTSWEEP 1700  //Right horizontal legs forward sweep value. Higher value moves right legs forward further.
#define RIGHT_BACKSWEEP  1300  //Right horizontal legs backward sweep value. Lower value moves right legs backward further.


//####################################################//
//Left Servo Values & Ranges
//####################################################//

// Min/Max pulse values in microseconds to send to the servo
#define LEFT_MIN     1300   
#define LEFT_MAX     1700
#define LEFT_CENTER  1500

int leftSweepRange = 200;  //Range of this value should be 100-200. Controls the distance of horizontal sweep motion.
int leftFrontSweep = LEFT_CENTER - leftSweepRange;
int leftBackSweep = LEFT_CENTER + leftSweepRange;

// Legacy defines, for reference.
#define LEFT_FRONTSWEEP  1300  //Left horizontal legs forward sweep value. Lower value moves left legs forward further.
#define LEFT_BACKSWEEP   1700  //Left horizontal legs backward sweep value. Higher value moves left legs backward further.

// Placeholder for interpolation implementation.
int centerServoValue = 1500;   //current positional value being sent to the center servo. 
int rightServoValue = 1500;  //current positional value being sent to the right servo. 
int leftServoValue = 1500;  //current positional value being sent to the left servo. 

// Delay values for walking sequences.
int delayValue = 180;
int delayValue2 = 250;


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
