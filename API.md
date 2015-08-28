# BricktronicsColor API

This library interfaces with LEGO NXT and EV3 color sensors. It can be used with the [Bricktronics Shield](https://store.wayneandlayne.com/products/bricktronics-shield-kit.html), [Bricktronics Megashield](https://store.wayneandlayne.com/products/bricktronics-megashield-kit.html), or standalone with the [Bricktronics Breakout Board](https://store.wayneandlayne.com/products/bricktronics-breakout-board.html). For the shield/megashield, use the constructor below with the `BricktronicsSensorSettings` struct, otherwise use the constructor below that accepts the clock and data pin numbers.

## Connection with [Bricktronics Shield](https://store.wayneandlayne.com/products/bricktronics-shield-kit.html) and [Bricktronics Megashield](https://store.wayneandlayne.com/products/bricktronics-megashield-kit.html)

Use the pushbutton sensor sensor port 3 or 4 on the Bricktronics Shield, or any port on the Bricktronics Megashield. For the sensor port jumpers, connect only pins 3-4.

Constructor usage for Bricktronics Shield
```C++
#include <Wire.h>
#include <Adafruit_MCP23017.h>
#include <BricktronicsShield.h>
#include <BricktronicsColor.h>
BricktronicsColor c(BricktronicsShield::SENSOR_3);
```

Constructor usage for Bricktronics Megashield
```C++
#include <BricktronicsMegashield.h>
#include <BricktronicsColor.h>
BricktronicsColor c(BricktronicsMegashield::SENSOR_1);
```

## Connection with [Bricktronics Breakout Board](https://store.wayneandlayne.com/products/bricktronics-breakout-board.html)

* Pin 1 - Unused
* Pin 2 - Connect to Ground
* Pin 3 - Connect to Ground
* Pin 4 - Connect to 5V
* Pin 5 - Connect to any digital pin
* Pin 6 - Connect to any analog input pin

Constructor usage for Bricktronics Breakout Board:
```C++
#include <BricktronicsColor.h>
BricktronicsColor c(pinFive, pinSix);
```

## Quick Example

```C++
#include <BricktronicsColor.h>

// Use one of the constructor options listed above.
BricktronicsColor c(8, 16);

void setup()
{
    Serial.begin(115200);
    c.begin();
}

void loop()
{
    c.printColor(c.getColor());
    delay(100);
}
```

## `BricktronicsColor(uint8_t clockPin, uint8_t dataPin)`

Constructor - Simple constructor that accepts the clock and data pins

**Parameters**

* `uint8_t clockPin` - The Arduino pin number where the button's pin 5 is connected.
* `uint8_t dataPin` - The Arduino pin number where the button's pin 5 is connected. Must be an analog input pin.


## `BricktronicsColor(const BricktronicsSensorSettings &settings)`

Constructor - Advanced constructor that accepts a SensorSettings struct to also override the low-level Arduino functions.

**Parameters**

* `const BricktronicsSensorSettings &settings` - A const reference to the struct containing all the sensor settings. Get these structs from the [BricktronicsShield](https://github.com/wayneandlayne/BricktronicsShield) or [BricktronicsMegashield](https://github.com/wayneandlayne/BricktronicsMegashield) library.


## `void begin(void)`

Set up the sensor library internals and pin modes. During the setup() function, call this function once for each instance in your sketch.

## `void begin(uint8_t modeType)`

Set up the sensor library internals and pin modes. During the setup() function, call this function once for each instance in your sketch. This variant changes the mode, either TYPE_COLORFUL (default), or TYPE_COLOR{RED,GREEN,BLUE,NONE}. See enum section below.

**Parameters**

* `uint8_t modeType` - Provide one of TYPE_COLORFUL, TYPE_COLORRED, TYPE_COLORGREEN, TYPE_COLORBLUE, or TYPE_COLORNONE.


More to come...
