# ADHD Focused Blinking Light - ESP32/M5StickC Plus
## Description
This project is a heart rate simulator developed for the ESP32 and M5StickC Plus platforms. It is designed to mimic the rhythm of a human heartbeat using an LED. The simulation starts with a heartbeat rate of 120, 85, 70 beats per minute (BPM), representing a faster heartbeat, and gradually slows down to a resting rate of 65 BPM. This project can be used for relaxation assistance, psychological experiments, educational purposes, or simply as a technology demonstration.
# ADHD Focused Blinking Light - ESP32/M5StickC Plus Project
## Features

- **Heart Rate Simulation**: Simulates a human heartbeat using an LED, starting at 120,85,70 BPM.
- **Gradual Heart Rate Transition**: Heart rate gradually decreases from high BPM to 65 BPM over a period, adjustable between 20 to 60 minutes.
- **Time-Controlled Transition**: Utilizes the `millis()` function for timing the transition of the heart rate.
- **Hardware Compatibility**: Specifically designed for M5StickC Plus but compatible with other ESP32 devices. M5StickC Plus features a built-in LED and a display for showing the heart rate.
- **Display Functionality**: Current heart rate (BPM) displayed on the M5StickC Plus screen for interactive user experience.
- **Serial Logging**: Outputs heart rate data to a connected computer for monitoring and debugging purposes.

## Inspiration

This project was inspired by a [Hacker News post](https://news.ycombinator.com/item?id=38274782), discussing a simple yet effective hack using a blinking LED to sync with one's heartbeat to induce focus and calmness.

## Hardware Requirements

- ESP32 or M5StickC Plus
- LED (if using a standard ESP32)
- Appropriate resistors and wiring (for ESP32)

## Software Requirements

- Arduino IDE
- ESP32/M5StickC Plus specific libraries

## Installation

[M5StickC Plus Quick Start](https://docs.m5stack.com/en/quick_start/m5stickc_plus/arduino)
1. Clone this repository to your local machine.
2. Open the project in Arduino IDE.
3. Install necessary libraries (details provided in the `Libraries` section).
4. Connect your ESP32 or M5StickC Plus to your computer.
5. Select the appropriate board and port in the Arduino IDE.
6. Upload the code to your board.

## Usage

- Power on the ESP32/M5StickC Plus.
- The LED will start blinking at high BPM and gradually slow down to 65 BPM.
- The current BPM is displayed on the M5StickC Plus screen (if using M5StickC Plus).
- Monitor the serial output for heart rate data (optional).

## License

see the LICENSE.md file for details.
