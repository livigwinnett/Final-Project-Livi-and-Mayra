//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"

#include "motor.h"
#include "motion_sensor.h"
#include "display.h"

//=====[Declaration of private defines]========================================

#define MOTOR_UPDATE_TIME 9

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

DigitalOut motorM1Pin(PF_2);
DigitalOut motorM2Pin(PE_3);

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

motorDirection_t motorDirection;
motorDirection_t motorState;

//=====[Declaration and initialization of private global variables]============

static bool curtainComplete = false;

//=====[Declarations (prototypes) of private functions]========================

//=====[Implementations of public functions]===================================

void motorControlInit()
{
    motorM1Pin = OFF;
    motorM2Pin = OFF;
}

motorDirection_t motorDirectionRead()
{
    return motorDirection;
}

void curtainOpen(){
    if(motionSensorRead() && curtainComplete == false){
        displayCharPositionWrite(0,0);
        displayStringWrite("Enter 4 coins.");
        motorM1Pin = ON;
        motorM2Pin = OFF;
        delay(10000);
        motorM1Pin = OFF;
        motorM2Pin = OFF;
        motionSensorDeactivate();
        delay(3000);
        curtainClose();
        curtainComplete = true;
    }
}

bool curtainOpened(){
    return curtainComplete;
}

void writeComplete(bool complete){
    curtainComplete = complete;
}

void curtainClose(){
    motorM1Pin = OFF;
    motorM2Pin = ON;
    delay(3000);
    motorM1Pin = OFF;
    motorM2Pin = OFF;
}

//=====[Implementations of private functions]==================================
