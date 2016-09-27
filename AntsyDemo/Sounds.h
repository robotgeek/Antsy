#ifndef SOUNDS_H
#define SOUNDS_H

#include "Lights.h"

#define SPKR_PIN 12

enum SoundIDs
{
  UP,
  DOWN,
  WHISTLE,
  LAUGH,
  OHH,
  UHOH,
  BEEPS
};
void SoundPlay( int soundid );
void SoundEnable()
{
  pinMode( SPKR_PIN, OUTPUT );
}

// Reference:  This list was adapted from the table located here:
//     http://www.phy.mtu.edu/~suits/notefreqs.html
const float  note_C0 = 16.35;  //C0
const float  note_Db0 = 17.32;  //C#0/Db0
const float  note_D0 = 18.35;  //D0
const float  note_Eb0 = 19.45;  //D#0/Eb0
const float  note_E0 = 20.6;  //E0
const float  note_F0 = 21.83;  //F0
const float  note_Gb0 = 23.12;  //F#0/Gb0
const float  note_G0 = 24.5;  //G0
const float  note_Ab0 = 25.96;  //G#0/Ab0
const float  note_A0 = 27.5;  //A0
const float  note_Bb0 = 29.14;  //A#0/Bb0
const float  note_B0 = 30.87;  //B0
const float  note_C1 = 32.7;  //C1
const float  note_Db1 = 34.65;  //C#1/Db1
const float  note_D1 = 36.71;  //D1
const float  note_Eb1 = 38.89;  //D#1/Eb1
const float  note_E1 = 41.2;  //E1
const float  note_F1 = 43.65;  //F1
const float  note_Gb1 = 46.25;  //F#1/Gb1
const float  note_G1 = 49;  //G1
const float  note_Ab1 = 51.91;  //G#1/Ab1
const float  note_A1 = 55;  //A1
const float  note_Bb1 = 58.27;  //A#1/Bb1
const float  note_B1 = 61.74;  //B1
const float  note_C2 = 65.41;  //C2 (Middle C)
const float  note_Db2 = 69.3;  //C#2/Db2
const float  note_D2 = 73.42;  //D2
const float  note_Eb2 = 77.78;  //D#2/Eb2
const float  note_E2 = 82.41;  //E2
const float  note_F2 = 87.31;  //F2
const float  note_Gb2 = 92.5;  //F#2/Gb2
const float  note_G2 = 98;  //G2
const float  note_Ab2 = 103.83;  //G#2/Ab2
const float  note_A2 = 110;  //A2
const float  note_Bb2 = 116.54;  //A#2/Bb2
const float  note_B2 = 123.47;  //B2
const float  note_C3 = 130.81;  //C3
const float  note_Db3 = 138.59;  //C#3/Db3
const float  note_D3 = 146.83;  //D3
const float  note_Eb3 = 155.56;  //D#3/Eb3
const float  note_E3 = 164.81;  //E3
const float  note_F3 = 174.61;  //F3
const float  note_Gb3 = 185;  //F#3/Gb3
const float  note_G3 = 196;  //G3
const float  note_Ab3 = 207.65;  //G#3/Ab3
const float  note_A3 = 220;  //A3
const float  note_Bb3 = 233.08;  //A#3/Bb3
const float  note_B3 = 246.94;  //B3
const float  note_C4 = 261.63;  //C4
const float  note_Db4 = 277.18;  //C#4/Db4
const float  note_D4 = 293.66;  //D4
const float  note_Eb4 = 311.13;  //D#4/Eb4
const float  note_E4 = 329.63;  //E4
const float  note_F4 = 349.23;  //F4
const float  note_Gb4 = 369.99;  //F#4/Gb4
const float  note_G4 = 392;  //G4
const float  note_Ab4 = 415.3;  //G#4/Ab4
const float  note_A4 = 440;  //A4
const float  note_Bb4 = 466.16;  //A#4/Bb4
const float  note_B4 = 493.88;  //B4
const float  note_C5 = 523.25;  //C5
const float  note_Db5 = 554.37;  //C#5/Db5
const float  note_D5 = 587.33;  //D5
const float  note_Eb5 = 622.25;  //D#5/Eb5
const float  note_E5 = 659.26;  //E5
const float  note_F5 = 698.46;  //F5
const float  note_Gb5 = 739.99;  //F#5/Gb5
const float  note_G5 = 783.99;  //G5
const float  note_Ab5 = 830.61;  //G#5/Ab5
const float  note_A5 = 880;  //A5
const float  note_Bb5 = 932.33;  //A#5/Bb5
const float  note_B5 = 987.77;  //B5
const float  note_C6 = 1046.5;  //C6
const float  note_Db6 = 1108.73;  //C#6/Db6
const float  note_D6 = 1174.66;  //D6
const float  note_Eb6 = 1244.51;  //D#6/Eb6
const float  note_E6 = 1318.51;  //E6
const float  note_F6 = 1396.91;  //F6
const float  note_Gb6 = 1479.98;  //F#6/Gb6
const float  note_G6 = 1567.98;  //G6
const float  note_Ab6 = 1661.22;  //G#6/Ab6
const float  note_A6 = 1760;  //A6
const float  note_Bb6 = 1864.66;  //A#6/Bb6
const float  note_B6 = 1975.53;  //B6
const float  note_C7 = 2093;  //C7
const float  note_Db7 = 2217.46;  //C#7/Db7
const float  note_D7 = 2349.32;  //D7
const float  note_Eb7 = 2489.02;  //D#7/Eb7
const float  note_E7 = 2637.02;  //E7
const float  note_F7 = 2793.83;  //F7
const float  note_Gb7 = 2959.96;  //F#7/Gb7
const float  note_G7 = 3135.96;  //G7
const float  note_Ab7 = 3322.44;  //G#7/Ab7
const float  note_A7 = 3520;  //A7
const float  note_Bb7 = 3729.31;  //A#7/Bb7
const float  note_B7 = 3951.07;  //B7
const float  note_C8 = 4186.01;  //C8
const float  note_Db8 = 4434.92;  //C#8/Db8
const float  note_D8 = 4698.64;  //D8
const float  note_Eb8 = 4978.03;  //D#8/Eb8

void beep(float noteFrequency, long noteDuration)
{
  int x;
  float microsecondsPerWave = 1000000 / noteFrequency;
  float millisecondsPerCycle = 1000 / (microsecondsPerWave * 2);
  float loopTime = noteDuration * millisecondsPerCycle;
  // Play the note for the calculated loopTime.
  for (x = 0; x < loopTime; x++)
  {
    LightsSet( HIGH, HIGH );
    digitalWrite(SPKR_PIN, HIGH);
    delayMicroseconds(microsecondsPerWave);
    LightsSet( LOW, LOW );
    digitalWrite(SPKR_PIN, LOW);
    delayMicroseconds(microsecondsPerWave);
  }
}

void sound_up()
{
  beep( note_C7, 50 ); //C
  beep( note_D7, 50 ); //D
  beep( note_E7, 50 ); //E
  beep( note_F7, 50 ); //F
  beep( note_G7, 50 ); //G
  beep( note_A7, 50 ); //A
  beep( note_B7, 50 ); //B
  beep( note_C8, 50 ); //C
}
void sound_down()
{
  beep( note_C8, 50 ); //C
  beep( note_B7, 50 ); //B
  beep( note_A7, 50 ); //A
  beep( note_G7, 50 ); //G
  beep( note_F7, 50 ); //F
  beep( note_E7, 50 ); //E
  beep( note_D7, 50 ); //D
  beep( note_C7, 50 ); //C
}

void sound_beeps()
{
  beep( note_A7, 100); //A
  beep( note_G7, 100); //G
  beep( note_E7, 100); //E
  beep( note_C7, 100); //C
  beep( note_D7, 100); //D
  beep( note_B7, 100); //B
  beep( note_F7, 100); //F
  beep( note_C8, 100); //C
  beep( note_A7, 100); //A
  beep( note_G7, 100); //G
  beep( note_E7, 100); //E
  beep( note_C7, 100); //C
  beep( note_D7, 100); //D
  beep( note_B7, 100); //B
  beep( note_F7, 100); //F
  beep( note_C8, 100); //C
}

void sound_whistle()
{
  for (int i = 1000; i < 5000; i = i * 1.05)
  {
    beep(i, 10);
  }
  delay(200);

  for (int i = 1000; i < 3000; i = i * 1.03)
  {
    beep(i, 10);
  }
  for (int i = 3000; i > 1000; i = i * .97)
  {
    beep(i, 10);
  }
}

void sound_ohh()
{
  for (int i = 1000; i < 2000; i = i * 1.02)
  {
    beep(i, 10);
  }
  for (int i = 2000; i > 1000; i = i * .98)
  {
    beep(i, 10);
  }
}

void sound_uhoh()
{
  for (int i = 1000; i < 1044; i = i * 1.01)
  {
    beep(i, 30);
  }
  delay(100);
  for (int i = 1244; i > 1108; i = i * .99)
  {
    beep(i, 30);
  }
}

void sound_laugh()
{
  for (int i = 1000; i < 2000; i = i * 1.10)
  {
    beep(i, 10);
  }
  delay(50);
  for (int i = 1000; i > 500; i = i * .90)
  {
    beep(i, 10);
  }
  delay(50);
  for (int i = 1000; i < 2000; i = i * 1.10)
  {
    beep(i, 10);
  }
  delay(50);
  for (int i = 1000; i > 500; i = i * .90)
  {
    beep(i, 10);
  }
  delay(50);
  for (int i = 1000; i < 2000; i = i * 1.10)
  {
    beep(i, 10);
  }
  delay(50);
  for (int i = 1000; i > 500; i = i * .90)
  {
    beep(i, 10);
  }
  delay(50);
  for (int i = 1000; i < 2000; i = i * 1.10)
  {
    beep(i, 10);
  }
  delay(50);
  for (int i = 1000; i > 500; i = i * .90)
  {
    beep(i, 10);
  }
  delay(50);
}

void SoundPlay( int soundid )
{
  switch ( soundid )
  {
  case UP:
    sound_up();
    break;
  case DOWN:
    sound_down();
    break;
  case WHISTLE:
    sound_whistle();
    break;
  case LAUGH:
    sound_laugh();
    break;
  case OHH:
    sound_ohh();
    break;
  case UHOH:
    sound_uhoh();
    break;
  case BEEPS:
    sound_beeps();
    break;
  }
}

//Reference: This code was adapted from: https://github.com/bq/zowiLibs
#define S_connection  0
#define S_disconnection 1
#define S_buttonPushed  2
#define S_mode1     3
#define S_mode2     4
#define S_mode3     5
#define S_surprise    6
#define S_OhOoh     7
#define S_OhOoh2    8
#define S_cuddly    9
#define S_sleeping    10
#define S_happy     11
#define S_superHappy  12
#define S_happy_short   13
#define S_sad       14
#define S_confused    15
#define S_insect1     16
#define S_insect2     17
#define S_insect3     18
void _tone( float noteFrequency, long noteDuration, int silentDuration )
{
  if( silentDuration == 0 )
  {
    silentDuration = 1;
  }

  beep(noteFrequency, noteDuration);
  delay(noteDuration); //milliseconds to microseconds
  delay(silentDuration);
}

void bendTones( float initFrequency, float finalFrequency, float prop, long noteDuration, int silentDuration )
{
  //Examples:
  //  bendTones (880, 2093, 1.02, 18, 1);
  //  bendTones (note_A5, note_C7, 1.02, 18, 0);

  if(silentDuration == 0) {silentDuration = 1;}

  if(initFrequency < finalFrequency)
  {
    for (int i = initFrequency; i < finalFrequency; i = i * prop)
    {
      _tone(i, noteDuration, silentDuration);
    }
  }
  else
  {
    for (int i = initFrequency; i > finalFrequency; i = i / prop)
    {
      _tone(i, noteDuration, silentDuration);
    }
  }
}

void sing( int songName )
{
  switch( songName )
  {
  case S_connection:
    _tone(note_E5, 50, 30);
    _tone(note_E6, 55, 25);
    _tone(note_A6, 60, 10);
    break;

  case S_disconnection:
    _tone(note_E5, 50, 30);
    _tone(note_A6, 55, 25);
    _tone(note_E6, 50, 10);
    break;

  case S_buttonPushed:
    bendTones (note_E6, note_G6, 1.03, 20, 2);
    delay(30);
    bendTones (note_E6, note_D7, 1.04, 10, 2);
    break;

  case S_mode1:
    bendTones (note_E6, note_A6, 1.02, 30, 10);  //1318.51 to 1760
    break;

  case S_mode2:
    bendTones (note_G6, note_D7, 1.03, 30, 10);  //1567.98 to 2349.32
    break;

  case S_mode3:
    _tone(note_E6, 50, 100); //D6
    _tone(note_G6, 50, 80); //E6
    _tone(note_D7, 300, 0); //G6
    break;

  case S_surprise:
    bendTones(800, 2150, 1.02, 10, 1);
    bendTones(2149, 800, 1.03, 7, 1);
    break;

  case S_OhOoh:
    bendTones(880, 2000, 1.04, 8, 3); //A5 = 880
    delay(200);

    for (int i = 880; i < 2000; i = i * 1.04)
    {
      _tone(note_B5, 5, 10);
    }
    break;

  case S_OhOoh2:
    bendTones(1880, 3000, 1.03, 8, 3);
    delay(200);

    for (int i = 1880; i < 3000; i = i * 1.03)
    {
      _tone(note_C6, 10, 10);
    }
    break;

  case S_cuddly:
    bendTones(700, 900, 1.03, 16, 4);
    bendTones(899, 650, 1.01, 18, 7);
    break;

  case S_sleeping:
    bendTones(100, 500, 1.04, 10, 10);
    delay(500);
    bendTones(400, 100, 1.04, 10, 1);
    break;

  case S_happy:
    bendTones(1500, 2500, 1.05, 20, 8);
    bendTones(2499, 1500, 1.05, 25, 8);
    break;

  case S_superHappy:
    bendTones(2000, 6000, 1.05, 8, 3);
    delay(50);
    bendTones(5999, 2000, 1.05, 13, 2);
    break;

  case S_happy_short:
    bendTones(1500, 2000, 1.05, 15, 8);
    delay(100);
    bendTones(1900, 2500, 1.05, 10, 8);
    break;

  case S_sad:
    bendTones(880, 669, 1.02, 20, 200);
    break;

  case S_confused:
    bendTones(1000, 1700, 1.03, 8, 2);
    bendTones(1699, 500, 1.04, 8, 3);
    bendTones(1000, 1700, 1.05, 9, 10);
    break;

  case S_insect1:
    bendTones(1600, 3000, 1.02, 2, 15);
    break;

  case S_insect2:
    bendTones(2000, 6000, 1.02, 2, 20);
    break;

  case S_insect3:
    bendTones(1600, 4000, 1.02, 2, 20);
    bendTones(4000, 3000, 1.02, 2, 20);
    break;

  }
}

#endif //--SOUNDS_H
