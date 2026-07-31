# ESP32 OLED Joystick Controller 🕹️

Welcome to another project from **CodetoCircut**! This repository contains the code and wiring diagram to control a small graphical element on a 0.96-inch I2C OLED display using an analog joystick and an ESP32 microcontroller. 

## 🛠️ Hardware Requirements
* 1x ESP32 Development Board (30-pin version)
* 1x 0.96" I2C OLED Display (128x64)
* 1x Analog Joystick Module
* 1x Solderless Breadboard
* Jumper Wires

## 🔌 Wiring Setup
The project is completely solderless. Connect the components as follows:

**OLED Display:**
* `VCC` -> ESP32 `3V3`
* `GND` -> ESP32 `GND`
* `SCL` -> ESP32 `D22`
* `SDA` -> ESP32 `D21`

**Joystick Module:**
* `VCC` -> ESP32 `3V3`
* `GND` -> ESP32 `GND`
* `VRx` -> ESP32 `D34`
* `VRy` -> ESP32 `D35`

## 🚀 How to Use
1. Clone or download this repository.
2. Open the `.ino` file in the Arduino IDE.
3. Ensure you have the **Adafruit GFX** and **Adafruit SSD1306** libraries installed via the Library Manager.
4. Select your ESP32 board and COM port.
5. Upload the code and move the joystick to see the circle move on the screen!

📺 **Watch the build video on YouTube:** [Link to your Short]
🔔 **Subscribe:** [CodetoCircut](Link to your channel)
