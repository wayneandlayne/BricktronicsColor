// Bricktronics Example: ColorLamp
// http://www.wayneandlayne.com/bricktronics
// This example uses a LEGO NXT Color Sensor.
//
// The Color sensor can also act like a red, green, or blue lamp.
// This example switches between these three colors in turn.
//
// Written in 2015 by Matthew Beckler and Adam Wolf for Wayne and Layne, LLC
// To the extent possible under law, the author(s) have dedicated all
//   copyright and related and neighboring rights to this software to the
//   public domain worldwide. This software is distributed without any warranty.
// You should have received a copy of the CC0 Public Domain Dedication along
//   with this software. If not, see <http://creativecommons.org/publicdomain/zero/1.0/>. 


// Include the BricktronicsColor library
#include <BricktronicsColor.h>


// This example can be run in three different ways. Pick one, and un-comment
// the code lines corresponding to your chosen method. Comment-out the lines
// for the other methods that you aren't using.

// 1. With a Bricktronics Shield - Include these lines and be sure to
// call BricktronicsShield::begin() in the setup() function below.
// You also need to install the Adafruit MCP23017 library:
//	https://github.com/adafruit/Adafruit-MCP23017-Arduino-Library
// Select the sensor port for the BricktronicsColor (SENSOR_3 or SENSOR_4) below.
// Use the jumpers to connect only pins 3-4 for the color sensor.
//
// Config 1 - arduino:avr:uno
//#include <Wire.h>
//#include <Adafruit_MCP23017.h>
//#include <BricktronicsShield.h>
//BricktronicsColor c(BricktronicsShield::SENSOR_3);
// Config end

// 2. With a Bricktronics Megashield - Include these lines but do not
// call BricktronicsShield::begin() in the setup() function below.
// Select the sensor port for the BricktronicsColor (SENSOR_1 through SENSOR_4) below.
// Use the jumpers to connect only pins 3-4 for the color sensor.
//
// Config 2 - arduino:avr:mega:cpu=atmega2560
//#include <BricktronicsMegashield.h>
//BricktronicsColor c(BricktronicsMegashield::SENSOR_3);
// Config end

// 3. With a Bricktronics Breakout board - No additional includes needed, just
// update the pin assignments in the BricktronicsColor constructor below.
//
// The BricktronicsColor() arguments are: clockPin, dataPin
// There are a few considerations for pin assignments:
//      dataPin - This must be an analog pin.
//
// Config 3 - arduino:avr:uno
//BricktronicsColor c(8, 16);
// Config end


void setup()
{
  // Only call this if you are using a Bricktronics Shield,
  // otherwise leave it commented-out.
  // Config 1 - arduino:avr:uno
  //BricktronicsShield::begin();
  // Config end

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

