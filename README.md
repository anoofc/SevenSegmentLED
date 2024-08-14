# SevenSegmentLED Library Documentation
This document describes the SevenSegmentLED library for Arduino, which allows you to control a seven-segment LED display using NeoPixel LEDs.

# Dependencies
This library requires the following libraries to be installed in your Arduino IDE:
## Adafruit_NeoPixel: https://github.com/adafruit/Adafruit_NeoPixel (v1.x.x or later)
Optional:

You can enable debug output by setting TROUBLESHOOT to 1 in the header file (SevenSegmentLED.h). This will print the individual digit values to the serial monitor.
Installation
Download the library files:
Save the code you provided (both SevenSegmentLED.h and SevenSegmentLED.cpp) in a folder named SevenSegmentLED.
Install the library:
There are two ways to install the library:
Using the Library Manager (recommended):
Open the Arduino IDE.
Go to Sketch > Include Library > Manage Libraries.
Search for "SevenSegmentLED" (if it doesn't appear automatically).
If you find it, install the library.
If not, click on "Add .ZIP Library" and select the folder containing your downloaded library files.
Manual installation:
Close the Arduino IDE if it's open.
Navigate to your Arduino sketchbook folder (usually located in Documents/Arduino/libraries on Windows or Documents/Arduino/libraries on macOS).
Place the SevenSegmentLED folder containing your library files inside the libraries folder.
Restart the Arduino IDE.
Usage
1. Include the library:

C++
#include "SevenSegmentLED.h"
Use code with caution.

2. Create an instance of the SevenSegmentLED class:

C++
// Define the number of LED pins connected (total LEDs) and the number of digits
int ledPin = 14;
int numDigits = 4;

SevenSegmentLED sevenSeg(ledPin, numDigits);
Use code with caution.

3. Initialize the display:

C++
sevenSeg.begin();
Use code with caution.

4. Display a number on a specific digit:

C++
// Define the number to display, color of the lit segments (red, green, blue), off segment color, and digit number (0-based, leftmost digit)
sevenSeg.displayNumber(number, r, g, b, color2, digit);

// Example: Display the digit 5 (red) on the second digit (from left) with black off segments
sevenSeg.displayNumber(5, 255, 0, 0, BLACK, 1);
Use code with caution.

5. Display a larger number across all digits:

C++
// Define the number to display and color of the lit segments (red, green, blue)
sevenSeg.numberUpdate(number, r, g, b);

// Example: Display the number 1234 (green)
sevenSeg.numberUpdate(1234, 0, 255, 0);
Use code with caution.

Additional Notes
The displayNumber function allows you to control the color of both the lit segments and the off segments.
The numberUpdate function automatically breaks down a larger number and displays it across all digits (assuming you have enough digits in your display).
The TROUBLESHOOT flag enables debug output to the serial monitor, printing the individual digit values for debugging purposes.
This documentation provides a basic overview of how to use the SevenSegmentLED library. You can explore the code further to understand the details of each function and variable.