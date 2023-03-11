#include "coin_slot.h"
#include "mbed.h"
#include "arm_book_lib.h"
#include "display.h"

DigitalIn breakBeam(D10);
static int coins = 0;
DigitalOut offLed(LED1);

void breakBeamInit(){
    breakBeam.mode(PullUp);
    displayCharPositionWrite(0,0);
    displayStringWrite("Enter 4 coins.");
}

static bool coinDetected(){
    if(breakBeam == OFF){
        offLed = ON;
    } else{
        offLed = OFF;
    }
    return breakBeam == OFF;
}

int count(){
    if (coinDetected()){
        coins = coins + 1;
        delay(1000);
    }
    return coins;
}

bool coinsEntered(){
    return coins >= 4;
}

void coinsEnteredReset(){
    coins = 0;
}
