/*
EW202 Lab 5.1 Calibration Test
D Evangelista 2019
*/

#include "mbed.h"
#include "stdio.h"

// calibration coefficients from Matlab polyfit
#define CAL_A -59.7382
#define CAL_B 79.7480   
#define CAL_C -2.9079

Serial pc(USBTX,USBRX);
AnalogIn sensor(p20);

// function to apply the calibration
float calibration(float);

int main(void){
    pc.printf("EW202 Lab 5.1 Calibration Test\n");
    pc.printf("D Evangelista, 2019\n");
    
    while(1){
        pc.printf("%f\n",calibration(sensor.read()));
        wait(0.2); 
        }
    }
    
    
float calibration(float x){
    /**
    Apply calibration to height sensor using coefficients from Matlab polyfit
    */
    return CAL_A*x*x+CAL_B*x+CAL_C;
    }
