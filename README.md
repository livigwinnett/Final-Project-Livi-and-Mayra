# Livi Gwinnett and Mayra Morales
# Say Cheese and Take a Pic 
# 03.11.23
# The photobooth will start with a PIR sensor. If motion is detected the curtain opens by rotating a DC motor, then closes so the booth can be used. Once inside, an LCD prompts the user to enter four coins. A break beam sensor counts the coins entered. Once four are entered, the screen tells the users four photos will be taken. Then, the screen displays a countdown and an LED flashes four times, representing a picture being taken. Then a servo motor on the outside of the booth rotates, dropping the "photos" and the curtain opens and closes, ready to run again. 
# coin slot module:
# Uses the break beam to count how many coins have been entered. Has a function that reads if at least four have been entered to allow the rest of the system to work. Reset function that brings the coins sensed back to zero for the next run.
# Code from scratch based off of DigitalIn.
# display module:
# Code taken from chapter 7.
# motion sensor module:
# 
# Code taken from chapter 6.
# motor module:
# Controls the curtain using a DC motor. Has the openCurtain() function which is the first part of the main function. Functions based off of chapter 7 but modified to be  a digital rather than an interrupt. 
# photo booth system:
# Has an initializing function and calls all the other main functions.
# Code based on the smart home system module from previous projects.
# servo motor module:
# Controls a servo motor acting as the photo dispenser. Has an initialize, gate open, and gate close functions. 
# Code from scratch from the servo motor lab.
# user interface module:
# Has the second main function, takePhoto(), which uses the input from the break beam and the outputs on the LCD screen and the LED. Then after the four countdowns and flashes are done, the function opens and closes the servo. 
# We have tests on the PIR sensor and so that when they are sensing LED1 and LED2 will turn on on the nucleo board.
# The hardware we used includes a PIR sensor, DC motor, servo motor, break beam, LCD screen (potentiometer), LED
