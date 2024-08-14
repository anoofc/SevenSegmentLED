#include <Arduino.h>
#include <SevenSegmentLED.h>    // Include the SevenSegmentLED library


#define LEDPIN 25             // Pin number for the LED strip
#define DIGITS 4              // Number of digits in the display

SevenSegmentLED display(LEDPIN, DIGITS);    // Create an instance of the SevenSegmentLED class



void setup() {
  display.begin();                              // Initialize the display
}

void loop() {
  display.numberUpdate(1234, 255, 0, 0);        // Display the number 1234 in red
  delay(1000);
  display.numberUpdate(9876, 0, 255, 0);        // Display the number 9876 in green
  delay(1000);
  display.numberUpdate(5432, 0, 0, 255);        // Display the number 5432 in blue
}
