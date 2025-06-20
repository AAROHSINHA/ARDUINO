# Gesture-Controlled LEDs using Mediapipe and Arduino

This project allows you to control 5 LEDs using hand gestures detected by a webcam. It uses **Mediapipe** in Python to track hand landmarks and sends finger status to an **Arduino Uno** via serial communication. The Arduino then lights up LEDs based on which fingers are raised.

## 🔧 Tech Stack
- Python (OpenCV, Mediapipe, PySerial)
- Arduino Uno
- 5 LEDs + Resistors
- Breadboard & Jumper Wires
- USB for Serial Communication

## 🎯 Features
- Real-time hand gesture tracking
- Control 5 LEDs using one hand
- Python script sends 5-bit string (e.g., `"10101"`) over serial
- Arduino lights up LEDs accordingly

## 🖐 Gesture Logic
- Each finger (Thumb, Index, Middle, Ring, Pinky) corresponds to an LED
- Finger is "raised" based on Mediapipe landmark position logic
- `'1'` means LED ON, `'0'` means LED OFF

## 🛠 Setup

### Arduino
- Connect 5 LEDs to digital pins (e.g., 8–12)
- Load the provided Arduino sketch
- Use `Serial.begin(9600)` for communication

### Python
- Install dependencies:
  ```bash
  pip install opencv-python mediapipe pyserial
