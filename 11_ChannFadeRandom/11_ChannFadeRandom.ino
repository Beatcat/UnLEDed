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
FadeLed sevenLed(8);
FadeLed eightLed(9);
FadeLed nineLed(10);
FadeLed tenLed(11);
FadeLed elevenLed(12);
FadeLed twelveLed(13);
//used to time
unsigned long millisLast = -1;
const unsigned long Interval = 10;

void setup() {
  //Set update interval to 500ms
  FadeLed::setInterval(1);
  
  //set all colors to same time and to constant fade time
  //Each color change will take 5 seconds
  oneLed.setTime(1000, true);
  twoLed.setTime(1000, true);
  threeLed.setTime(1000, true);
  fourLed.setTime(1000, true);
  fiveLed.setTime(1000, true);
  sixLed.setTime(1000, true);
  sevenLed.setTime(1000, true);
  eightLed.setTime(1000, true);
  nineLed.setTime(1000, true);
  tenLed.setTime(1000, true);
  elevenLed.setTime(1000, true);
  twelveLed.setTime(1000, true);
  
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
    oneLed.set(random(0, 256));
    twoLed.set(random(0, 256));
    threeLed.set(random(0, 256));
    fourLed.set(random(0, 256));
    fiveLed.set(random(0, 256));
    sixLed.set(random(0, 256));
    sevenLed.set(random(0, 256));
    eightLed.set(random(0, 256));
    nineLed.set(random(0, 256));
    tenLed.set(random(0, 256));
    elevenLed.set(random(0, 256));
    twelveLed.set(random(0, 256));
  }
}
