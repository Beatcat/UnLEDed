/**
 *  @file
 *  @Author Septillion (https://github.com/sseptillion)
 *  @date 2016-08-15
 *  @brief Example how to use FadeLed with RGB-fading
 *  
 *  @details This is an example how to use FadeLed library when fading RGB LEDs so 
 *  they fade smoothly from one color to another. Here we pick a random 
 *  new color every 10 seconds and LED the RGB led fade to the new color 
 *  in 5 seconds. 
 *  
 *  The RGB LED is connected to pins 9, 10 and 11 for red, green en blue 
 *  respectively. Don't forget to add a current limiting resistor for each 
 *  color.
 *  
 *  Pin A0 is used to get a random seed and needs to be unconnected.
 */

#include <FadeLed.h>

//the RGB LED
FadeLed oneLed(2);
FadeLed twoLed(3);
FadeLed threeLed(4);
FadeLed fourLed(5);
FadeLed fiveLed(6);
FadeLed sixLed(7);

//used to time
unsigned long millisLast = -1;
const unsigned long Interval = 10;

void setup() {
  //Set update interval to 500ms
  FadeLed::setInterval(1);
  
  //set all colors to same time and to constant fade time
  //Each color change will take 5 seconds
  oneLed.setTime(500, true);
  twoLed.setTime(500, true);
  threeLed.setTime(500, true);
  fourLed.setTime(500, true);
  fiveLed.setTime(500, true);
  sixLed.setTime(500, true);
  
  //Give the random a random seed from the noise from the ADC of A0
  randomSeed(analogRead(A0));
}

void loop() {
  //We always need to call this
  FadeLed::update();
  
  //Change to a random color every Interval
  if(millis() - millisLast > Interval){
    //Save time for the next time
    millisLast += Interval;
    
    //set each color to a new random value to create a new random color
    oneLed.set(random(0, 100));
    twoLed.set(random(0, 100));
    threeLed.set(random(0, 100));
    fourLed.set(random(0, 100));
    fiveLed.set(random(0, 100));
    sixLed.set(random(0, 100));
  }
}
