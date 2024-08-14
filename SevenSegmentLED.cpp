#include "SevenSegmentLED.h"      // Include the SevenSegmentLED header file

// Constructor
SevenSegmentLED::SevenSegmentLED(int ledPin, int digits) : strip(digits*7, ledPin, NEO_GRB + NEO_KHZ800) { }

// Initialize the display
void SevenSegmentLED::begin() {
  strip.begin();  // Initialize the LED strip
  strip.show();   // Initialize all pixels to 'off'
}

// Display a number on the specified digit
void SevenSegmentLED::displayNumber(uint8_t number, uint8_t r,uint8_t g, uint8_t b, uint32_t color2, uint8_t digit) {   // Define the displayNumber (Number to display, (Red, Green, Blue) Color of the segment, Off Segment Colour, Digit Number 0-4)
  for (int i = 0; i < 7; i++) {                                 // Loop through the 7 segments of the display
    if (numbers[number][i] == 1) {                              // Check if the segment should be turned on
      strip.setPixelColor(i + (7 * digit), strip.Color(r,g,b)); // Set the color of the segment with given color
    } else {
      strip.setPixelColor(i + (7 * digit), color2);             // Set the color of the segment to black
    }
  }
  strip.show();   // Update the display
}

// Update the display with a number
void SevenSegmentLED::numberUpdate(uint16_t number, uint8_t r, uint8_t g, uint8_t b) {    // Define the numberUpdate (Number to display, Red, Green, Blue)
  uint8_t digit0 = number % 10;                 // Get the value of the first digit
  uint8_t digit1 = (number / 10) % 10;          // Get the value of the second digit
  uint8_t digit2 = (number / 100) % 10;         // Get the value of the third digit
  uint8_t digit3 = (number / 1000) % 10;        

  displayNumber(digit0, r,g,b, BLACK, 3);       // Display the first digit
  displayNumber(digit1, r,g,b, BLACK, 2);       // Display the second digit
  displayNumber(digit2, r,b,g, BLACK, 1);       // Display the third digit
  displayNumber(digit3, r,b,g, BLACK, 0);       // Display the fourth digit

  #ifdef TROUBLESHOOT                   // Check if the TROUBLESHOOT flag is set
  Serial.println("Digit 3: " + String(digit3) + "\t Digit 2: " + String(digit2) + "\t Digit 1: " + String(digit1) + "\t Digit 0: " + String(digit0));   // Print the value of the digits to the serial monitor
  #endif
}