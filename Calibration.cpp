/*
Calibration program

Ashwyn Chadha - 20550128
Jenny Dong - 20572161
Rayyan Ghani - 20561743
Yaning Tan - 20556308
*/
#include "UW_GENE_121.h"

void main (){
  int refl1 = 0, refl2 = 0, threshold1, threshold2;
  
  for (int i = 1; i <=4; i++){
    //LEDs indicate dark or light calibration
    if (i == 1)
      LEDon(RED_LED);
    else {
      LEDoff(RED_LED);
      LEDon(GREEN_LED);
    }
    //indicator bar indicates # button presses
    LEDnum(i);
    while(getSensor(BUTTON) == 0); 
    //wait until button is pressed to collect data
    refl1 += getSensor(REFLECT_1);
    refl2 += getSensor(REFLECT_2);
    //wait for next button press to get next value
    wait1Msec(100);
    while(getSensor(BUTTON) == 1);
    wait1Msec(100);
    while(getSensor(BUTTON) == 0);
  }
  
  LEDoff(GREEN_LED);
  
  //average of light and dark values
  threshold1 = int (refl1/4.0);
  threshold2 = int (refl2/4.0);
  
  //filler operation so that threshold 1 and 2 will show up on watch
  int sum = threshold1 + threshold2;
}
