/******************************************************************************
Walking.h
 *****************************************************************************/

#ifndef WALKING
#define WALKING

//####################################################//
//Servo Pin Defines
//####################################################//

#define CENTER 9       //Center Servo Digital Pin Assignment
#define RIGHT 10       //Right Servo Digital Pin Assignment
#define LEFT 11        //Left Servo Digital Pin Assignment

//####################################################//
//Center Servo Values & Ranges
//####################################################//

// Min/Max pulse values in microseconds to send to the servo
#define CENTER_MIN     1050  
#define CENTER_MAX     1950 
#define CENTER_CENTER  1500

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

// Legacy defines, for reference.
#define LEFT_FRONTSWEEP  1300  //Left horizontal legs forward sweep value. Lower value moves left legs forward further.
#define LEFT_BACKSWEEP   1700  //Left horizontal legs backward sweep value. Higher value moves left legs backward further.

// Placeholder for interpolation implementation.
extern int centerServoValue;   //current positional value being sent to the center servo. 
extern int rightServoValue;  //current positional value being sent to the right servo. 
extern int leftServoValue;  //current positional value being sent to the left servo. 

// Delay values for walking sequences.
extern int delayValue;
extern int delayValue2;


//####################################################//
//Servo Objects
//####################################################//

extern Servo centerServo, rightServo, leftServo;  // create servo objects to control the center, right, and left servos.

//####################################################//
//Center Servo Values & Ranges
//####################################################//

extern int centerShiftRange;  //Range of this value should be 300-400. Controls the amount of vertical lift provided by the center servo.
extern int centerRightDown;
extern int centerLeftDown;


//####################################################//
//Right Servo Values & Ranges
//####################################################//

extern int rightSweepRange;  //Range of this value should be 100-200. Controls the distance of horizontal sweep motion.
extern int rightSweepRangeOffset;
extern int rightFrontSweep;
extern int rightBackSweep;


//####################################################//
//Left Servo Values & Ranges
//####################################################//

extern int leftSweepRange;  //Range of this value should be 100-200. Controls the distance of horizontal sweep motion.
extern int leftSweepRangeOffset;
extern int leftFrontSweep;
extern int leftBackSweep;

//####################################################//
//FORWARD WALKING POSES
//####################################################//

void RightUpForward(int leftOffset, int rightOffset);

void LeftUpForward(int leftOffset, int rightOffset);

void RightCenterForward();

void LeftCenterForward();

void Center();

//####################################################//
//BACKWARD WALKING POSES
//####################################################//

void RightUpBackward();

void LeftUpBackward();

void RightCenterBackward();

void LeftCenterBackward();



//####################################################//
// RIGHT TURN WALKING POSES
//####################################################//

void RightUpTurnRight();

void LeftUpTurnRight();

void RightCenterTurnRight();

void LeftCenterTurnRight();


//####################################################//
//LEFT TURN WALKING POSES
//####################################################//

void RightUpTurnLeft();

void LeftUpTurnLeft();

void RightCenterTurnLeft();

void LeftCenterTurnLeft();


//####################################################//
//WALK CYCLE FUNCTIONS
//####################################################//

void TurnRight(int cycle);

void TurnLeft(int cycle);

void WalkForward(int cycle);

void WalkBackward(int cycle);

void DriveForward(int turn, int cycle);

#endif
