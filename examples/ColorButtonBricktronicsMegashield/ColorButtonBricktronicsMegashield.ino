// Bricktronics Example: ColorButtonBricktronicsMegashield
// http://www.wayneandlayne.com/bricktronics
//
// When the button is pressed, a single reading from the color sensor is taken
// and converted into a color name and printed over the Serial Console.
//
// Hardware used:
// * Wayne and Layne Bricktronics Megashield
//   https://store.wayneandlayne.com/products/bricktronics-megashield-kit.html
// * LEGO NXT Pushbutton Sensor
// * LEGO NXT Color Sensor
//
// Software libraries used:
// * Wayne and Layne BricktronicsButton library
//   https://github.com/wayneandlayne/BricktronicsButton
// * Wayne and Layne BricktronicsColor library
//   https://github.com/wayneandlayne/BricktronicsColor
// * Wayne and Layne BricktronicsMegashield library
//   https://github.com/wayneandlayne/BricktronicsMegashield
// * Adafruit MCP23017 library
//   https://github.com/adafruit/Adafruit-MCP23017-Arduino-Library
//
// Written in 2016 by Matthew Beckler and Adam Wolf for Wayne and Layne, LLC
// To the extent possible under law, the author(s) have dedicated all
//   copyright and related and neighboring rights to this software to the
//   public domain worldwide. This software is distributed without any warranty.
// You should have received a copy of the CC0 Public Domain Dedication along
//   with this software. If not, see <http://creativecommons.org/publicdomain/zero/1.0/>. 


// Include the Bricktronics libraries
#include <BricktronicsMegashield.h>
#include <BricktronicsButton.h>
#include <BricktronicsColor.h>


// Select the sensor ports for the button (SENSOR_1 through SENSOR_4)
// and color sensor (SENSOR_1 through SENSOR_4) in their constructors below.
// If your chosen port has jumpers, connect pins 2-3 and 4-5 for the button,
// and connect only pins 3-4 for the color sensor.
BricktronicsButton b(BricktronicsMegashield::SENSOR_1);
BricktronicsColor c(BricktronicsMegashield::SENSOR_3);


void setup() 
{
  // Be sure to set your serial console to 115200 baud
  Serial.begin(115200);

  // Initialize the button and color sensor connections
  b.begin();
  c.begin();
}


void loop()
{
  // Wait until the button is pressed
  while (b.isReleased())
  {
    // Nothing to do here
  }
  // To get here, the button was pushed!

  c.printColor(c.getColor());
  Serial.println();

  // In order to debounce the button, we wait a little bit here
  delay(100);

  // Wait until the button is released
  while (b.isPressed())
  {
    // Nothing to do here
  }

  // In order to debounce the button, we wait a little bit here
  delay(100);
}

