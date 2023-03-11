//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"

#include "user_interface.h"
#include "photo_booth_system.h"
#include "motion_sensor.h"
#include "matrix_keypad.h"
#include "display.h"
#include "motor.h"
#include "coin_slot.h"
#include "servo_motor.h"
#include "coin_slot.h"
#include <string>

//=====[Declaration of private defines]========================================

#define DISPLAY_REFRESH_TIME_REPORT_MS 1000
#define DISPLAY_REFRESH_TIME_ALARM_MS 300

//=====[Declaration of private data types]=====================================

typedef enum {
    DISPLAY_ALARM_STATE,
    DISPLAY_REPORT_STATE
} displayState_t;

//=====[Declaration and initialization of public global objects]===============

DigitalOut led(D14);
DigitalOut test(LED3);

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//char codeSequenceFromUserInterface[CODE_NUMBER_OF_KEYS];

//=====[Declaration and initialization of private global variables]============

static displayState_t displayState = DISPLAY_REPORT_STATE;
static int numberOfPictures = 0;

//=====[Declarations (prototypes) of private functions]========================

//=====[Implementations of public functions]===================================

void userInterfaceInit()
{
    //matrixKeypadInit( SYSTEM_TIME_INCREMENT_MS );    
    motionSensorInit();
    breakBeamInit();
    displayInit();
}

void userInterfaceUpdate()
{
    count();
    matrixKeypadUpdate();
}

//=====[Implementations of private functions]==================================

void countdown(){
    displayInit();
    displayCharPositionWrite(0, 0);
    displayStringWrite("3...");
    delay(1000);
    displayCharPositionWrite(4, 0);
    displayStringWrite("2...");
    delay(1000);
    displayCharPositionWrite(8, 0);
    displayStringWrite("1...");
    delay(1000);
    led = HIGH;
    delay(100);
    led = LOW;
}

static void printPhoto(){
    displayInit();
    displayCharPositionWrite(0,0);
    displayStringWrite("Printing :)");
    gateOpen();
    gateClose();
    coinsEnteredReset();
    curtainOpen();
    curtainClose();
    motionSensorActivate();
}

static int charToInt(char character){
    int integer = character - '0';
    return integer;
}

void takePhoto(){
    bool complete = 0;
    //while(!complete){
        if(curtainOpened()){
            if(coinsEntered()){
                displayInit();
                displayCharPositionWrite(0,0);
                displayStringWrite("4 pictures.");
                displayCharPositionWrite(0,1);
                displayStringWrite("Say cheese!");
                delay(5000);
                //int numPics = charToInt(matrixKeypadUpdate());
                for(int i = 0; i < 4; i++){
                    countdown();
                    complete = true;
                }
                printPhoto();
                writeComplete(false);
            }
        }
    } 
//}
