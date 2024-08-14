// Must have the Adarfuit NeoPixel library installed
// Author: Anoof C   (https://github.com/anoofc/)
// Date  : 14/08/2024
// Description: This is an example of how to use the SevenSegmentLED library to display numbers on a 4-digit 7-segment LED display
//              The example displays the numbers 1234, 9876, and 5432 in red, green, and blue respectively
//              The example uses the numberUpdate method to display the numbers on the display
//              The example uses the clear method to clear the display after displaying each number
//              The example uses the delay function to pause the program for 1 second between displaying each number


#include <Arduino.h>
#include <SevenSegmentLED.h>    // Include the SevenSegmentLED library


#define LEDPIN 25             // Pin number for the LED strip
#define DIGITS 4              // Number of digits in the display

SevenSegmentLED display(LEDPIN, DIGITS);    // Create an instance of the SevenSegmentLED class



void setup() {
  display.begin();                              // Initialize the display
  display.numberUpdate(8888, 255, 0, 0);        // Display the number 8888 in red
  delay(1000);
  display.clear();                              // Clear the display    
}

void loop() {
  // Example: Display the numbers 1234, 9876, and 5432 in red, green, and blue respectively
  display.numberUpdate(1234, 255, 0, 0);        // Display the number 1234 in red
  delay(1000);
  display.numberUpdate(9876, 0, 255, 0);        // Display the number 9876 in green
  delay(1000);
  display.numberUpdate(5432, 0, 0, 255);        // Display the number 5432 in blue
  delay(1000);

  display.clear();                              // Clear the display
  // Example: Display the digit 5 (red) on the second digit (from left)
  display.displayNumber(5, 255, 0, 0, BLACK, 1);
  delay(1000);
}
