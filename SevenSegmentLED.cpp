#include "SevenSegmentLED.h"      // Include the SevenSegmentLED header file


// Constructor
SevenSegmentLED::SevenSegmentLED(int ledPin, int digits) : strip(digits*7, ledPin, NEO_GRB + NEO_KHZ800) {    // Constructor to initialize the display with the number of digits and the pin number of the LED strip
  lcDigits = digits;                // Set the number of digits
  }

// Initialize the display
void SevenSegmentLED::begin() {     // Function to initialize the display
  strip.begin();                    // Initialize the strip
  strip.show();                     // Update the strip
}

// Display a number on the specified digit
void SevenSegmentLED::displayNumber(uint8_t number, uint8_t r, uint8_t g, uint8_t b, uint8_t digit) {   // Input the number to be displayed, the r,g,b values of color of the display and the digit to display the number on
  int baseIndex = 7 * digit;            // Calculate the base index of the digit
  for (int i = 0; i < 7; i++) {         // Loop through the 7 segments of the digit
    strip.setPixelColor(baseIndex + i, numbers[number][i] ? strip.Color(r, g, b) : strip.Color(0, 0, 0));   // Set the color of the segment based on the number
  }
  strip.show();            // Update the strip
}

void SevenSegmentLED::clear() {   // Function to Clear the display
  strip.clear();                  // Clear the strip
  strip.show();                   // Update the strip
}

// Update the display with a number
void SevenSegmentLED::numberUpdate(uint32_t number, uint8_t r, uint8_t g, uint8_t b) {    // Input the number to be displayed and the r,g,b values of color of the display
  uint8_t digits[lcDigits];                             // Array to store the digits of the number
  for (int i = 0; i < lcDigits; i++) {                  // Loop through the digits
    digits[i] = number % 10;                            // Get the last digit of the number        
    number /= 10;                                       // Remove the last digit from the number and repeat the process                
  }

  for (int i = 0; i < lcDigits; i++) {                      // Loop through the digits
    displayNumber(digits[i], r, g, b, (lcDigits-1) - i);    // Display the digits on the display
  }

  #ifdef TROUBLESHOOT     // Print the digits to the serial monitor for troubleshooting (Optional) (Uncomment TROUBLESHOOT in Header file to enable)
  for (int i = (lcDigits-1); i >= 0; i--) {
    Serial.print("Digit " + String(lcDigits - 1 - i) + ": " + String(digits[i]));
    if (i > 0) Serial.print("\t");
  }
  Serial.println();
  #endif
}