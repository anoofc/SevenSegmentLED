#ifndef SevenSegmentLED_h     // Include guard to prevent the header file from being included more than once
#define SevenSegmentLED_h     // Define the header file if it has not been defined

#include <Adafruit_NeoPixel.h>      // Include the Adafruit NeoPixel library

// #define TROUBLESHOOT             // Uncomment to enable debug output (Optional)


class SevenSegmentLED {       // Define the SevenSegmentLED class

// Public methods and properties
// The public methods and properties are used to interact with the class
// The public methods and properties are used to set and get the values of the class properties
// The public methods and properties are used to perform actions on the class properties
public:
  SevenSegmentLED(int ledPin, int digits);
  uint8_t lcDigits = 0;
  void begin();
  void clear();
  void displayNumber(uint8_t number, uint8_t r, uint8_t g, uint8_t b, uint8_t digit);
  void numberUpdate(uint32_t number, uint8_t r, uint8_t g, uint8_t b);


// Private methods and properties
// The private methods and properties are used internally by the class
// The private methods and properties are used to perform internal operations
// The private methods and properties are not accessible from outside the class
private: 
  Adafruit_NeoPixel strip;              // Create an instance of the Adafruit NeoPixel class
  
  const uint8_t numbers[10][7] = {      // Define the numbers array
    {1,1,1,1,1,1,0}, // Zero
    {0,1,1,0,0,0,0}, // One
    {1,1,0,1,1,0,1}, // Two
    {1,1,1,1,0,0,1}, // Three
    {0,1,1,0,0,1,1}, // Four
    {1,0,1,1,0,1,1}, // Five
    {1,0,1,1,1,1,1}, // Six
    {1,1,1,0,0,0,0}, // Seven
    {1,1,1,1,1,1,1}, // Eight
    {1,1,1,1,0,1,1}  // Nine
  };
};

#endif
