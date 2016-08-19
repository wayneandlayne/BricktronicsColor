// Bricktronics Example: ColorLampBricktronicsBreakoutBoard
// http://www.wayneandlayne.com/bricktronics
//
// The Color sensor can also act like a red, green, or blue lamp.
// This example switches between these three colors in turn.
//
// Hardware used:
// * Wayne and Layne Bricktronics Breakout Board
//   https://store.wayneandlayne.com/products/bricktronics-breakout-board.html
// * LEGO NXT Color Sensor
//
// Software libraries used:
// * Wayne and Layne BricktronicsColor library
//   https://github.com/wayneandlayne/BricktronicsColor
//
// Written in 2016 by Matthew Beckler and Adam Wolf for Wayne and Layne, LLC
// To the extent possible under law, the author(s) have dedicated all
//   copyright and related and neighboring rights to this software to the
//   public domain worldwide. This software is distributed without any warranty.
// You should have received a copy of the CC0 Public Domain Dedication along
//   with this software. If not, see <http://creativecommons.org/publicdomain/zero/1.0/>.


// Include the Bricktronics libraries
#include <BricktronicsColor.h>


// For the color sensor, connect these pins on the Bricktronics Breakout board:
//  Pin 1 - Unused
//  Pin 2 - Connect to Ground
//  Pin 3 - Connect to Ground
//  Pin 4 - Connect to 5V
//  Pin 5 - Connect to any digital pin
//  Pin 6 - Connect to any analog input pin
//
// The BricktronicsColor() arguments are: clockPin, dataPin
// clockPin is where the breakout board's pin 5 is connected
// dataPin is where the breakout board's pin 6 is connected
//    This must be an analog pin.
//
BricktronicsColor c(8, 16);

void setup()
{
  // Initialize the color sensor connections
  c.begin();
}


void loop()
{
  c.begin(TYPE_COLORRED);
  delay(500);

  c.begin(TYPE_COLORBLUE);
  delay(500);

  c.begin(TYPE_COLORGREEN);
  delay(500);

  c.begin(TYPE_COLORNONE);
  delay(500);
}

