/*
Course B
Ashwyn Chadha - 20550128
Jenny Dong - 20572161
Rayyan Ghani - 20561743
Yaning Tan - 20556308
*/

#include "UW_GENE_121.h"

void leftTurn(int pwr, int sec){
  setMotor(MOTOR_A, 0);
  setMotor(MOTOR_B, -pwr);
  wait1Msec(sec);
}

void rightTurn(int pwr, int sec) {
  setMotor(MOTOR_A,pwr);
  setMotor(MOTOR_B, 0);
  wait1Msec(sec);
}

void drive( int pwr, int sec){
setMotor (MOTOR_A, pwr);
setMotor (MOTOR_B, -pwr);
wait1Msec (sec);        
}

int getSensorState(int threshold1, int threshold2){ 
  //straight = 0, left = 1, right = 2, both = 3;
  
  int reflValue1 = getSensor (REFLECT_1);
  int reflValue2 = getSensor (REFLECT_2);
  
  if (reflValue1 > threshold1 && reflValue2 > threshold2)
    //both white
    return 0; 
  else if (reflValue1 < threshold1 && reflValue2 > threshold2)
    //dark on left
    return 1;
  else if (reflValue1 > threshold1 && reflValue2 < threshold2)
    //dark on right
    return 2;
  else //both dark
    return 3;
}

void main (void)
{
  initialize();
  wait1Msec(200);
  
  //initialize values
  int pwr = 15;
  int sensorState = -1;
  
  //determine these values by running the calibration program first
  int threshold1 = 150;
  int threshold2 = 150;
  int sec = 10;
  
  //initialize motors and LED indicators
  setMotor (MOTOR_A, 0);
  setMotor (MOTOR_B, 0);
  LEDnum(0);
  LEDoff(RED_LED);
  LEDoff(GREEN_LED);

  //waits for a button press
  while(getSensor(BUTTON) == 0);
  wait1Msec(100);
  while(getSensor(BUTTON) == 1);
  
  
  //line following 
  while(getSensor(BUTTON)== 0) {
    if (sensorState != getSensorState(threshold1, threshold2)) { 
    //only change direction if conditions are different than before. 
      sensorState = getSensorState(threshold1,threshold2);
      if (sensorState == 0) { //go straight
        drive(15, sec);
      } else if (sensorState == 1){
        rightTurn(15,sec);
      } else if (sensorState == 2){
        leftTurn(15, sec);
      } else if (sensorState == 3){
        //turns right at forks: takes exit 4
        rightTurn(15, sec); 
      }  
    }
  } 
}