# 🔒 HAND GESTURE ENABLED SECURITY SYSTEM WITH RC4 ENCRYPTION

## 💡 Abstract / Project Overview

This project implements a smart, contactless access control solution using hand gestures detected by a PAJ7620U2 sensor.The primary goal is to enhance hygiene and security by enabling users to unlock a door with a predefined gesture sequence.The system uses an Arduino Uno microcontroller for processing, and incorporates **RC4 encryption** to secure stored access passwords.Additionally, it provides real-time monitoring by sending instant email alerts via the **Resend API** upon unauthorized access attemptsThe solution is low-cost, scalable, and highly suitable for smart homes, offices, and healthcare environment.

## ✨ Key Novelty and Features

* **Gesture Sensor:** Utilizes the PAJ7620U2 sensor to recognize **9 predefined gestures** in real-time.
* **Hygienic Interface:** Provides a hands-free, touchless interface, addressing hygiene concerns and offering accessibility for mobility challenges.
* **Robust Security (RC4):** Implements the **RC4 encryption algorithm** for secure storage and verification of access credentials.
* **Real-Time Alerts (IoT):** Integrates the **Resend API** to send reliable, instant security email notifications upon unauthorized attempts.
* **Customizable:** Allows for customizable gesture sequences for specific functions like "open," "lock," or "denied".
* **Performance:** Demonstrates a gesture recognition accuracy of approximately **95%** and a swift response time of **1–2 seconds**.

## 🛠️ Components and Software Required

| Component/Software | Quantity | Purpose |
| :--- | :--- | :--- |
| **Arduino Uno** | 1 | Microcontroller Unit (Central Processing Unit)  |
| **PAJ7620 Sensor** | 1 | Gesture Recognition Sensor  |
| **16x2 LCD Interface** | 1 | Display Real-time Status and Feedback  |
| **Breadboard** | 1 | Prototyping and testing electronic circuits |
| **Jumper Wires** | As Required (around 20) | [cite_start]Connection Between Parts |
| **Arduino IDE** | - | Programming the Arduino (C/C++ programming) |

## 🏗️ System Architecture

The system is built upon three main components and several software modules:

1.  **Microcontroller Unit (Arduino Uno):** Serves as the central processing unit.It receives input from the PAJ7620U2, interprets the gesture using an algorithm, and makes the access decision.
2.  **Gesture Sensor Module (PAJ7620U2):** Detects up to 9 unique hand gestures in real-time (e.g., up, down, left, right, forward, backward, clockwise, counter-clockwise, and wave).The sensor operates by emitting and detecting infrared light reflection.
3.  **Display Module (16×2 LCD):** Provides immediate feedback to the user, displaying messages like "Access Granted," "Access Denied," or the recognized gesture.
4.  **Security Module (RC4 Encryption):** Verifies the encrypted access code stored in the Arduino when a valid gesture sequence is identified.
5.  **Notification Module (Resend API):** Triggers an email notification to the administrator via serial communication upon unauthorized or invalid gesture attempts.

## 🖼️ Implementation

The system uses the Arduino Uno, PAJ7620 sensor, and the 16x2 LCD, typically arranged on a breadboard for prototyping.The LCD displays messages such as "Enter gesture" on startup , "Wrong, locked" after two incorrect attempts , and "Unlocked" upon successful authentication.




## 🔮 Future Enhancements

The project can be expanded with the following enhancements:

* **AI-Based Gesture Recognition:** Implement machine learning models to recognize custom, user-personalized gestures beyond the PAJ7620's predefined set.
* **IoT and Cloud Integration:** Add Wi-Fi/Bluetooth modules to enable real-time cloud syncing for remote access control, activity logs, and monitoring via mobile apps.
* **Multimodal Authentication:** Increase security by combining gesture recognition with other factors like facial recognition or voice commands.

