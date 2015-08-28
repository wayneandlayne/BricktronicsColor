// Bricktronics Example: ColorButton
// http://www.wayneandlayne.com/bricktronics
// This example uses a LEGO NXT Pushbutton Sensor and Color Sensor.
// 
// When the button is pressed, a single reading from the color sensor is taken
// and converted into a color name and printed over the Serial Console.
//
// Written in 2015 by Matthew Beckler and Adam Wolf for Wayne and Layne, LLC
// To the extent possible under law, the author(s) have dedicated all
//   copyright and related and neighboring rights to this software to the
//   public domain worldwide. This software is distributed without any warranty.
// You should have received a copy of the CC0 Public Domain Dedication along
//   with this software. If not, see <http://creativecommons.org/publicdomain/zero/1.0/>. 


// Include the Bricktronics Button and ColorSensor libraries
#include <BricktronicsButton.h>
#include <BricktronicsColor.h>


// This example can be run in three different ways. Pick one, and un-comment
// the code lines corresponding to your chosen method. Comment-out the lines
// for the other methods that you aren't using.

// 1. With a Bricktronics Shield - Include these lines and be sure to
// call BricktronicsShield::begin() in the setup() function below.
// You also need to install the Adafruit MCP23017 library:
//	https://github.com/adafruit/Adafruit-MCP23017-Arduino-Library
// Select the sensor ports for the Button (SENSOR_1 through SENSOR_4)
// and ColorSensor (SENSOR_3 or SENSOR_4) in their constructors below.
// If your chosen port has jumpers (ports 3 and 4), connect pins 2-3 and
// 4-5 for the button, and connect only pins 3-4 for the color sensor.
//
// Config 1 - arduino:avr:uno
//#include <Wire.h>
//#include <Adafruit_MCP23017.h>
//#include <BricktronicsShield.h>
//BricktronicsButton b(BricktronicsShield::SENSOR_1);
//BricktronicsColor c(BricktronicsShield::SENSOR_3);
// Config end

// 2. With a Bricktronics Megashield - Include these lines but do not
// call BricktronicsShield::begin() in the setup() function below.
// Select the sensor ports for the button (SENSOR_1 through SENSOR_4)
// and color sensor (SENSOR_1 through SENSOR_4) in their constructors below.
// If your chosen port has jumpers, connect pins 2-3 and 4-5 for the button,
// and connect only pins 3-4 for the color sensor.
//
// Config 2 - arduino:avr:mega:cpu=atmega2560
//#include <BricktronicsMegashield.h>
//BricktronicsButton b(BricktronicsMegashield::SENSOR_1);
//BricktronicsColor c(BricktronicsMegashield::SENSOR_3);
// Config end

// 3. With two Bricktronics Breakout boards - No additional includes needed, just
// update the pin assignments in the button and color sensor constructors below.
//
// For the pushbutton, connect these pins on the Bricktronics Breakout board:
//  Pin 1 - Connect to any digital input pin
//  Pin 2 - Connect to Ground
//  Pin 3 - Connect to Ground
//  Pin 4 - Connect to 5V
//  Pin 5 - No connection
//  Pin 6 - No connection
//
// For the color sensor, connect these pins on the Bricktronics Breakout board:
//  Pin 1 - Unused
//  Pin 2 - Connect to Ground
//  Pin 3 - Connect to Ground
//  Pin 4 - Connect to 5V
//  Pin 5 - Connect to any digital pin
//  Pin 6 - Connect to any analog input pin
//
// The BricktronicsButton() argument is simply the pin where the button's
// pin 1 is connected.
//
// The BricktronicsColor() arguments are: clockPin, dataPin
// clockPin is where the breakout board's pin 5 is connected
// dataPin is where the breakout board's pin 6 is connected
//    This must be an analog pin.
//
// Config 3 - arduino:avr:uno
//BricktronicsButton b(7);
//BricktronicsColor c(8, 16);
// Config end

void setup() 
{
  // Be sure to set your serial console to 115200 baud
  Serial.begin(115200);

  // Only call this if you are using a Bricktronics Shield,
  // otherwise leave it commented-out.
  // Config 1 - arduino:avr:uno
  //BricktronicsShield::begin();
  // Config end

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

