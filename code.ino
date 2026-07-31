#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

// Initialize display
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Joystick analog pins
const int joyX = 34; 
const int joyY = 35; 

// Starting position (center of the screen)
int xPos = SCREEN_WIDTH / 2;
int yPos = SCREEN_HEIGHT / 2;

void setup() {
  Serial.begin(115200);
  
  // Initialize the OLED with I2C address 0x3C
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Loop forever if display fails
  }
  
  display.clearDisplay();
}

void loop() {
  // Read joystick values (ESP32 ADC goes from 0 to 4095)
  int xVal = analogRead(joyX);
  int yVal = analogRead(joyY);

  // Determine movement based on joystick tilt
  if (xVal < 1500) xPos -= 2; // Move left
  if (xVal > 2500) xPos += 2; // Move right
  
  if (yVal < 1500) yPos -= 2; // Move up 
  if (yVal > 2500) yPos += 2; // Move down
  
  // Keep the circle from going off-screen
  xPos = constrain(xPos, 4, SCREEN_WIDTH - 5);
  yPos = constrain(yPos, 4, SCREEN_HEIGHT - 5);

  // Draw the frame
  display.clearDisplay();
  display.fillCircle(xPos, yPos, 4, WHITE);
  display.display();
  
  // Brief delay for smooth movement
  delay(20);
}
