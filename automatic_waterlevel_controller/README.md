# Automatic Water Level Controller

An Arduino-based automatic water level monitoring and control system designed to maintain optimal water levels in tanks or reservoirs. This project features real-time water level measurement, automatic pump control, manual override capabilities, and a user-friendly LCD display interface.

## 📋 Table of Contents
- [Overview](#overview)
- [Features](#features)
- [Hardware Components](#hardware-components)
- [Circuit Diagram](#circuit-diagram)
- [Pin Configuration](#pin-configuration)
- [Software Features](#software-features)
- [Installation](#installation)
- [Usage](#usage)
- [How It Works](#how-it-works)
- [Simulation](#simulation)
- [Troubleshooting](#troubleshooting)
- [Contributing](#contributing)
- [License](#license)

## 🔍 Overview

This Automatic Water Level Controller is an IoT-based solution that monitors water levels using an ultrasonic sensor and automatically controls a water pump to maintain desired water levels. The system includes both automatic and manual operation modes, making it suitable for various applications such as water tanks, overhead tanks, and irrigation systems.

**Author:** PRANESH S

## ✨ Features

- **Real-time Water Level Monitoring**: Uses HC-SR04 ultrasonic sensor for accurate distance measurement
- **Automatic Pump Control**: Automatically turns pump ON when water level drops below 30% and OFF when tank is full (99%)
- **Manual Override**: Switch between automatic and manual modes
- **LCD Display**: 16x2 LCD shows water level percentage and pump status
- **EEPROM Storage**: Stores calibration settings permanently
- **Manual Calibration**: Set reference water level using push button
- **Visual Indicators**: LED indicators for system status
- **Relay Control**: Safe pump control using relay module

## 🔧 Hardware Components

| Component | Quantity | Description |
|-----------|----------|-------------|
| Arduino Uno | 1 | Main microcontroller |
| HC-SR04 Ultrasonic Sensor | 1 | Water level measurement |
| 16x2 LCD Display | 1 | Display interface |
| Relay Module (5V) | 1 | Pump control |
| Push Button | 1 | Manual calibration |
| Slide Switch | 1 | Auto/Manual mode selection |
| Potentiometer | 1 | LCD contrast adjustment |
| LED | 1 | Status indicator |
| Resistors | 2 | 1kΩ (for LED and pull-up) |
| Jumper Wires | - | Connections |
| Breadboard/PCB | 1 | Circuit assembly |

## 📊 Circuit Diagram

![Schematic Diagram](schematic.png)

The circuit consists of:
- Arduino Uno as the main controller
- HC-SR04 sensor for water level measurement
- 16x2 LCD for displaying information
- Relay module for pump control
- Control switches and indicators

## 📌 Pin Configuration

| Arduino Pin | Component | Function |
|-------------|-----------|----------|
| Pin 2 | LCD RS | LCD Register Select |
| Pin 3 | LCD Enable | LCD Enable |
| Pin 4 | LCD D4 | LCD Data Pin 4 |
| Pin 5 | LCD D5 | LCD Data Pin 5 |
| Pin 6 | LCD D6 | LCD Data Pin 6 |
| Pin 7 | LCD D7 | LCD Data Pin 7 |
| Pin 8 | HC-SR04 Trig | Ultrasonic Trigger |
| Pin 9 | HC-SR04 Echo | Ultrasonic Echo |
| Pin 10 | Push Button | Calibration Button |
| Pin 11 | Slide Switch | Mode Selection |
| Pin 12 | Relay | Pump Control |
| 5V | VCC | Power Supply |
| GND | Ground | Common Ground |

## 💻 Software Features

### Core Functions:
- **Water Level Calculation**: Converts ultrasonic sensor readings to percentage
- **Automatic Control Logic**: Maintains water level between 30% and 99%
- **Mode Switching**: Toggle between automatic and manual operation
- **Calibration System**: Set reference point for accurate measurements
- **EEPROM Storage**: Persistent storage of calibration data
- **Real-time Display**: Continuous monitoring and status updates

### Control Logic:
```
IF water_level < 30% AND auto_mode = ON
    THEN pump = ON
IF water_level > 99%
    THEN pump = OFF
```

## 🚀 Installation

### Hardware Setup:
1. Connect the components according to the circuit diagram
2. Ensure proper power supply connections
3. Mount the ultrasonic sensor at the top of the water tank
4. Install the relay and pump connections safely

### Software Setup:
1. Install Arduino IDE
2. Install required library:
   ```
   LiquidCrystal (usually pre-installed)
   ```
3. Upload the `sketch.ino` code to Arduino Uno
4. Power up the system

## 📖 Usage

### Initial Setup:
1. Power on the system
2. The LCD will display "WATER LEVEL: 0%" and "PUMP:OFF MANUAL"
3. Fill the tank to desired maximum level
4. Switch to AUTO mode using the slide switch
5. Press and hold the calibration button to set reference level
6. The system will store this as 100% level in EEPROM

### Operation Modes:

**Automatic Mode:**
- Switch slide switch to AUTO position
- System automatically controls pump based on water level
- Pump turns ON when level drops below 30%
- Pump turns OFF when level reaches 99%

**Manual Mode:**
- Switch slide switch to MANUAL position
- Use push button to manually toggle pump ON/OFF
- Useful for maintenance or emergency situations

### Display Information:
- **Top Line**: "WATER LEVEL: XX%" - Current water level percentage
- **Bottom Line**: "PUMP:ON/OFF AUTO/MANUAL" - Pump status and operation mode

## ⚙️ How It Works

1. **Water Level Measurement**:
   - HC-SR04 sensor measures distance to water surface
   - Distance is converted to water level percentage using calibrated reference
   - Percentage = (reference_level - current_distance) × 100 / reference_level

2. **Automatic Control**:
   - System monitors water level continuously
   - When level drops below 30%, pump activates
   - When level reaches 99%, pump deactivates
   - Prevents dry running and overflow

3. **Manual Override**:
   - Switch to manual mode for direct control
   - Push button toggles pump state
   - Useful for testing and maintenance

4. **Data Storage**:
   - EEPROM stores calibration data permanently
   - Settings retained even after power loss
   - Maximum value limited to 150 for safety

## 🌐 Simulation

This project can be simulated online using Wokwi:
- **Project URL**: https://wokwi.com/projects/435108331971342337
- Test all features without physical hardware
- Modify distance settings to simulate different water levels
- Observe pump control behavior in real-time

## 🔧 Troubleshooting

### Common Issues:

**LCD Display Not Working:**
- Check all LCD connections
- Adjust contrast using potentiometer
- Verify 5V power supply

**Inaccurate Water Level Readings:**
- Recalibrate the system
- Check ultrasonic sensor mounting
- Ensure sensor is not obstructed

**Pump Not Responding:**
- Check relay connections
- Verify pump power supply
- Test in manual mode first

**System Not Remembering Settings:**
- Check EEPROM write operations
- Verify calibration procedure
- Reset and recalibrate if needed

### Calibration Tips:
- Ensure tank is at desired maximum level during calibration
- Hold calibration button until LCD updates
- Recalibrate if readings seem inaccurate
- Maximum calibration value is limited to 150 inches for safety

## 🤝 Contributing

Contributions are welcome! Please feel free to:
- Report bugs and issues
- Suggest new features
- Submit pull requests
- Improve documentation

## 📝 License

This project is open source and available under the [MIT License](LICENSE).

## 📞 Contact

**Project Author:** PRANESH S

For questions, suggestions, or support, please create an issue in this repository.

---

⭐ **Star this repository if you found it helpful!**

## 🔗 Related Projects

- [Arduino Water Level Sensor Projects](https://github.com/topics/water-level-sensor)
- [Home Automation Systems](https://github.com/topics/home-automation)
- [IoT Projects with Arduino](https://github.com/topics/iot-arduino)
