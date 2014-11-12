/*
Course A
Ashwyn Chadha - 20550128
Jenny Dong - 20572161
Rayyan Ghani - 20561743
Yaning Tan - 20556308
*/

#include "UW_GENE_121.h"

int HIGH = 40;
int LOW = 15;

#include "UW_GENE_121.h"

int HIGH = 40;
int LOW = 15;

void drive( int pwr, int delay){
  setMotor (MOTOR_A, pwr);
  setMotor (MOTOR_B, -pwr);
  wait1Msec (delay);        
}

void rightTurn(int delay) {
  setMotor(MOTOR_A,pwr);
  setMotor(MOTOR_B, 0);
  wait1Msec(delay);
}

void veerRight (float ratio, int delay){
    setMotor(MOTOR_A, -HIGH);
    setMotor(MOTOR_B, ratio*HIGH);
    wait1Msec(delay);
}

void veerLeft (float ratio, int delay){
    setMotor(MOTOR_A, int (-ratio*HIGH));
    setMotor(MOTOR_B, int (HIGH));
    wait1Msec(delay);
}
void main () 
{	
	// MOTOR_A is currently in reverse
	initialize();
        wait1Msec(200);
        
        //turn off motors at start
        setMotor (MOTOR_A, 0);
        setMotor (MOTOR_B, 0);
        
        //start car by clicking button
        while (getSensor(BUTTON) == 0);
        wait1Msec (100);
        while (getSensor(BUTTON) == 1);
        
        //hard code for exit 3
        drive(HIGH, 5000);   
        veerRight(1.25, 9400);   
        turnRight(1790);
        veerRight(1.17,8000);
        veerLeft(1.17,8000);
        
        //turn off motors at the end 
        setMotor (MOTOR_A, 0);
        setMotor (MOTOR_B, 0);
}