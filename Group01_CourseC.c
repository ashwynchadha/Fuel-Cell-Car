/*
Course C
Ashwyn Chadha - 20550128
Jenny Dong - 20572161
Rayyan Ghani - 20561743
Yaning Tan - 20556308
*/

#include "UW_GENE_121.h"

void leftTurn(int pwr, int delay){
  setMotor(MOTOR_A, 0);
  setMotor(MOTOR_B, -pwr);
  wait1Msec(delay);
}

void rightTurn(int pwr, int delay) {
  setMotor(MOTOR_A,pwr);
  setMotor(MOTOR_B, 0);
  wait1Msec(delay);
}
void drive( int pwr, int delay){
  setMotor (MOTOR_A, pwr);
  setMotor (MOTOR_B, -pwr);
  wait1Msec (delay);        
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
  int delay = 10;
  
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
  
  resetTimer(); 
  while(getSensor(BUTTON)== 0 && time100() < 64) { 
  //line follows for 6.4 seconds
    if (sensorState != getSensorState(threshold1, threshold2)) { 
    //only change direction if conditions are different than before. 
      sensorState = getSensorState(threshold1,threshold2);
      if (sensorState == 0) { //go straight
        drive(15, delay);
      } else if (sensorState == 1){
        rightTurn(15,delay);
      } else if (sensorState == 2){
        leftTurn(15, delay);
      } else if (sensorState == 3){
        rightTurn(15, delay);
      }  
    }
  } 
  //hard code exit 2
  rightTurn(pwr,2400);
  drive(pwr,9400);
  leftTurn(pwr,1500);
  drive(pwr,20000);
}