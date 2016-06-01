BricktronicsColor
=================

**BricktronicsColor v1.2 - A software library for LEGO NXT color sensors.**

More details at http://www.wayneandlayne.com/bricktronics/

**To Download**
Click the "Clone or download" button on the upper-right side of this page below the pink bar, then select "Download ZIP". Rename the uncompressed folder BricktronicsColor. Check that the BricktronicsColor folder contains BricktronicsColor.cpp and BricktronicsColor.h

Place the BricktronicsColor library folder into your `<arduinosketchfolder>/libraries/` folder. You may need to create the libraries subfolder if this is your first installed library. Restart the Arduino IDE.

**API Highlights**
* `BricktronicsColor(uint8_t clockPin, uint8_t dataPin)` - Constructor
* `void begin(void)` - Call the begin function in your setup() function
* `uint8_t getColor(void)` - Reads the sensor and returns a `COLOR_*` value.
* `void printColor(uint8_t color)` - Prints out a human-readable color name to the Serial port.
* More API details in [API.md](API.md)

**If you want to use color sensors with your Bricktronics Shield or Megashield, you may also be interested in these libraries:**
* [BricktronicsShield Arduino Library v1.2](https://github.com/wayneandlayne/BricktronicsShield)
* [BricktronicsMegashield Arduino Library v1.2](https://github.com/wayneandlayne/BricktronicsMegashield)

_Wayne and Layne, LLC and our products are not connected to or endorsed by the LEGO Group. LEGO, Mindstorms, and NXT are trademarks of the LEGO Group._

