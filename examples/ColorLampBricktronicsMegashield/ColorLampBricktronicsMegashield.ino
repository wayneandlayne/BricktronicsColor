// Bricktronics Example: ColorLampBricktronicsMegashield
// http://www.wayneandlayne.com/bricktronics
//
// The Color sensor can also act like a red, green, or blue lamp.
// This example switches between these three colors in turn.
//
// Hardware used:
// * Wayne and Layne Bricktronics Megashield
//   https://store.wayneandlayne.com/products/bricktronics-meagshield-kit.html
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


// Select the sensor port for the BricktronicsColor (SENSOR_1 through SENSOR_4) below.
// Use the jumpers to connect only pins 3-4 for the color sensor.
BricktronicsColor c(BricktronicsMegashield::SENSOR_3);


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

