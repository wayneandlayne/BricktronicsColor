// Bricktronics Example: ColorButtonBricktronicsBreakoutBoard
// http://www.wayneandlayne.com/bricktronics
//
// Color sensor readings are taken repeatedly, and when they change,
// they're debounced so the colors don't switch back and forth rapidly.
// The debounced color is printed to the serial console.
// This isn't necessarily the simplest or best way to debounce,
// but it works for what we're using it for!
//
// Hardware used:
// * Wayne and Layne Bricktronics Breakout Board
//   https://store.wayneandlayne.com/products/bricktronics-megashield-kit.html
// * LEGO NXT Color Sensor
//
// Software libraries used:
// * Wayne and Layne Bricktronics Breakout Board
//   https://store.wayneandlayne.com/products/bricktronics-breakout-board.html
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
  // Be sure to set your serial console to 115200 baud
  Serial.begin(115200);

  // Initialize the color sensor connections
  c.begin();
}

char stable = 0;
char lastColor = c.getColor();
char newReading;

void loop()
{
  stable = 0;
  newReading = c.getColor();

  if (newReading != lastColor)
  {
    while (stable < 10)
    {
      delay(10);

      if (c.getColor() == newReading)
      {
        stable += 1;
      }
      else
      {
        newReading = c.getColor();
        stable = 0;
      }
    }

    if (newReading != lastColor)
    {
      c.printColor(newReading);
      Serial.println();
      lastColor = newReading;
    }
  }

  delay(10);
}

