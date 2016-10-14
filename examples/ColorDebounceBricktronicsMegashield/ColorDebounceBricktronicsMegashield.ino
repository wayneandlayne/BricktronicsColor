// Bricktronics Example: ColorButtonBricktronicsMegashield
// http://www.wayneandlayne.com/bricktronics
//
// Color sensor readings are taken repeatedly, and when they change,
// they're debounced so the colors don't switch back and forth rapidly.
// The debounced color is printed to the serial console.
// This isn't necessarily the simplest or best way to debounce,
// but it works for what we're using it for!
//
// Hardware used:
// * Wayne and Layne Bricktronics Megashield
//   https://store.wayneandlayne.com/products/bricktronics-megashield-kit.html
// * LEGO NXT Color Sensor
//
// Software libraries used:
// * Wayne and Layne BricktronicsMegashield library
//   https://github.com/wayneandlayne/BricktronicsMegashield
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
#include <BricktronicsMegashield.h>
#include <BricktronicsColor.h>


// Select the sensor port (SENSOR_1 through SENSOR_4) in the constructor below.
// Use the jumpers to connect only pins 3-4 for the color sensor.
BricktronicsColor c(BricktronicsMegashield::SENSOR_3);


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

