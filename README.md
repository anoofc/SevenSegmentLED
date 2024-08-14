# SevenSegmentLED Library Documentation
This document describes the SevenSegmentLED library for Arduino, which allows you to control a seven-segment LED display using NeoPixel LEDs.

Arrangement of pixels in seven segment should be as below

```cpp
           1
      8888888888
   6  88      88  2
      88   7  88
      8888888888
   5  88      88  3
      88      88
      8888888888
           4
```

# Dependencies
This library requires the following libraries to be installed in your Arduino IDE:
#### Adafruit_NeoPixel: https://github.com/adafruit/Adafruit_NeoPixel (v1.x.x or later)

## Optional:
You can enable debug output by setting TROUBLESHOOT to 1 in the header file (SevenSegmentLED.h). This will print the individual digit values to the serial monitor.
# Installation
There are two ways to install the library:

### Using Arduino:
 - Download the library as Zip from this github repository https://github.com/anoofc/SevenSegmentLED
 - Open Arduino IDE
 - Click Sketch > Include Library > Add .ZIP Library
 - Select the Downloaded ZIP File.
### Manual installation:
 - Close the Arduino IDE if it's open.
 - Navigate to your Arduino sketchbook folder (usually located in Documents/Arduino/libraries on Windows or Documents/Arduino/libraries on macOS).
 - Extract and Copy the SevenSegmentLED folder containing your library files inside the libraries folder.
 - Open the Arduino IDE.

## Usage

 - Include the library:

```cpp
#include "SevenSegmentLED.h"
``` 
 - Create an instance of the SevenSegmentLED class:

```cpp
// Define the number of LED pins connected (total LEDs) and the number of digits
int ledPin = 14;
int numDigits = 4;

SevenSegmentLED sevenSeg(ledPin, numDigits);
``` 

 - Initialize the display:

```cpp
sevenSeg.begin();
``` 

 - Display a number on a specific digit:

```cpp
// Define the number to display, color of the lit segments (red, green, blue), and digit number (0-based, leftmost digit)
sevenSeg.displayNumber(number, r, g, b, digit);

// Example: Display the digit 5 (red) on the second digit (from left) 
sevenSeg.displayNumber(5, 255, 0, 0, 1);
```

 - Display a larger number across all digits:

```cpp
// Define the number to display and color of the lit segments (red, green, blue)
sevenSeg.numberUpdate(number, r, g, b);

// Example: Display the number 1234 (green)
sevenSeg.numberUpdate(1234, 0, 255, 0);

```
## Authors

- [@anoofc](https://www.github.com/anoofc)


## 🔗 Let's Connect
[![linkedin](https://img.shields.io/badge/linkedin-0A66C2?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/anoofc)
[![twitter](https://img.shields.io/badge/twitter-1DA1F2?style=for-the-badge&logo=twitter&logoColor=white)](https://twitter.com/anoofc)


## Additional Notes
 - The displayNumber function allows you to control the color of both the lit segments and the off segments.
 - The numberUpdate function automatically breaks down a larger number and displays it across all digits (assuming you have enough digits in your display).
 - The TROUBLESHOOT flag enables debug output to the serial monitor, printing the individual digit values for debugging purposes.
 - This documentation provides a basic overview of how to use the SevenSegmentLED library. You can explore the code further to understand the details of each function and variable.