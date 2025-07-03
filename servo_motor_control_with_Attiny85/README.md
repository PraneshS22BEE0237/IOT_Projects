# Servo Motor Control with ATtiny85

A dual servo motor control system using ATtiny85 microcontroller with potentiometer-based positioning control

## 📋 Project Overview

This project demonstrates how to control two servo motors using an ATtiny85 microcontroller. The servo positions are controlled by two potentiometers connected to analog inputs. The project includes a custom SoftwareServo library implementation optimized for ATtiny85's limited resources.

## 🔧 Components Required

| Component | Quantity | Description |
|-----------|----------|-------------|
| ATtiny85 | 1 | 8-bit microcontroller |
| Positional Micro Servo | 2 | Standard 9g servo motors |
| 5V Power Supply | 1 | External power source |
| 250kΩ Potentiometer | 2 | Variable resistors for position control |
| Breadboard | 1 | For prototyping connections |
| Jumper Wires | As needed | For connections |
| Capacitors | 2-3 | 100µF and 10µF for power filtering |

## 🔌 Pin Configuration

### ATtiny85 Pinout:
```
     ATtiny85
    ┌─────────┐
    │1 ●    8 │ VCC (5V)
PB3 │2      7 │ PB2 (A1) - Not used
PB4 │3      6 │ PB1 (Pin 1) - Servo 2
GND │4      5 │ PB0 (Pin 0) - Servo 1
    └─────────┘
```

### Connections:
- **Pin 0 (PB0)**: Servo 1 control signal
- **Pin 1 (PB1)**: Servo 2 control signal  
- **A2 (PB4)**: Potentiometer 1 analog input
- **A3 (PB3)**: Potentiometer 2 analog input
- **VCC**: 5V power supply
- **GND**: Ground

## 📐 Circuit Diagram

```
VCC (5V) ──┬── ATtiny85 Pin 8
           │
           ├── Servo1 VCC
           │
           ├── Servo2 VCC
           │
           └── Potentiometer VCC pins

ATtiny85 Pin 5 (PB0) ── Servo1 Signal
ATtiny85 Pin 6 (PB1) ── Servo2 Signal
ATtiny85 Pin 3 (PB4/A2) ── Potentiometer1 Wiper
ATtiny85 Pin 2 (PB3/A3) ── Potentiometer2 Wiper

GND ──┬── ATtiny85 Pin 4
      │
      ├── Servo1 GND
      │
      ├── Servo2 GND
      │
      └── Potentiometer GND pins
```

## 💻 Software Features

### Custom SoftwareServo Library
- **Optimized for ATtiny85**: Lightweight implementation for resource-constrained environment
- **Multiple Servo Support**: Can control multiple servos simultaneously
- **Precise Timing**: Uses Timer0 for accurate pulse generation
- **Configurable Range**: Adjustable minimum and maximum pulse widths

### Key Functions:
- `attach(pin)`: Attach servo to a digital pin
- `write(angle)`: Set servo position (0-180 degrees)
- `read()`: Get current servo angle
- `setMinimumPulse(pulse)`: Set minimum pulse width (540µs default)
- `setMaximumPulse(pulse)`: Set maximum pulse width (2400µs default)
- `refresh()`: Update servo positions (call every 20ms)

## 🚀 How It Works

1. **Analog Input Reading**: The ATtiny85 reads analog values from two potentiometers connected to pins A2 and A3
2. **Value Mapping**: Analog readings (0-1023) are mapped to servo angles (0-180 degrees)
3. **PWM Generation**: The SoftwareServo library generates precise PWM signals for servo control
4. **Continuous Update**: The main loop continuously updates servo positions based on potentiometer values

## 📝 Code Structure

```cpp
// Custom SoftwareServo class implementation
class SoftwareServo {
    // Private members for pin, angle, pulse timing
    // Public methods for servo control
};

// Main program
void setup() {
    // Initialize analog pins and attach servos
}

void loop() {
    // Read potentiometer values
    // Map to servo angles
    // Update servo positions
    // Refresh servo signals
}
```

## ⚙️ Programming the ATtiny85

### Using Arduino IDE:

1. **Install ATtiny Board Package**:
   - Add `http://drazzy.com/package_drazzy.com_index.json` to Board Manager URLs
   - Install "ATTinyCore" by Spence Konde

2. **Board Settings**:
   - Board: "ATtiny25/45/85"
   - Processor: "ATtiny85"
   - Clock: "Internal 16 MHz"
   - Programmer: "USBasp" or "Arduino as ISP"

3. **Upload Process**:
   - Connect programmer to ATtiny85
   - Select correct board and programmer
   - Upload the code

## 🔋 Power Requirements

- **Supply Voltage**: 5V (recommended for servo operation)
- **Current**: ~500mA (depending on servo load)
- **Power Filtering**: Use capacitors to filter power supply noise

## 🛠️ Troubleshooting

### Common Issues:

1. **Servos not responding**:
   - Check power connections
   - Verify signal wire connections
   - Ensure adequate power supply current

2. **Erratic servo movement**:
   - Add power supply filtering capacitors
   - Check for loose connections
   - Verify potentiometer connections

3. **Programming issues**:
   - Check programmer connections
   - Verify board settings in Arduino IDE
   - Ensure proper fuse settings

## 📈 Possible Enhancements

- [ ] Add servo speed control
- [ ] Implement position feedback
- [ ] Add wireless control (ESP8266/nRF24L01)
- [ ] Create position presets
- [ ] Add LCD display for position monitoring
- [ ] Implement servo calibration routine

## 📄 Files in this Repository

- `servo_motor_control1.ino` - Main Arduino sketch with SoftwareServo library
- `componentlist.csv` - Bill of materials
- `Copy of Servo Control With Attiny85.png` - Circuit diagram image
- `Servo_motor_control.pdf` - Project documentation
- `README.md` - This file


