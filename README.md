# Breath Analyzer using Arduino Nano

## Overview
This project is a simple breath analyzer that measures alcohol concentration in the breath and displays the results on an OLED display. The system uses an Arduino Nano as the main controller, along with the following components:
- MQ-3 Gas Sensor (Alcohol)
- DHT11 Sensor (Temperature and Humidity)
- OLED Display
- Buzzer

The device can be used as a simple tool to estimate alcohol content in a user's breath. When alcohol is detected above a certain threshold, the buzzer will sound an alert.

## Components
- **Arduino Nano**: Controls the whole system and reads data from the sensors.
- **MQ-3 Sensor**: Detects the alcohol content in the breath.
- **DHT11 Sensor**: Measures ambient temperature and humidity.
- **OLED Display**: Displays the alcohol level and environmental data.
- **Buzzer**: Sounds an alert if alcohol content exceeds a preset limit.
- **Resistors and Wires**: For connections.

## Circuit Diagram
[Provide a link or an image of the circuit diagram here]

## Wiring Connections

| Component       | Pin Description | Arduino Nano Pin |
|-----------------|-----------------|------------------|
| MQ-3 Sensor     | VCC             | 5V               |
|                 | GND             | GND              |
|                 | A0              | A0               |
| DHT11 Sensor    | VCC             | 5V               |
|                 | GND             | GND              |
|                 | Data            | D4               |
| OLED Display    | VCC             | 3.3V             |
|                 | GND             | GND              |
|                 | SDA             | A4               |
|                 | SCL             | A5               |
| Buzzer          | Positive        | D2               |
|                 | Negative        | GND              |

## Libraries Required
To run the code, the following libraries need to be installed in the Arduino IDE:
- **Adafruit GFX Library**
- **Adafruit SSD1306** (for OLED display)
- **DHT sensor library**

Install these from the Arduino Library Manager for easy integration.
### Upload The Code

## How It Works
1. MQ-3 Sensor: The MQ-3 gas sensor is used to detect the alcohol content in the user's breath. It outputs an analog signal based on the concentration of alcohol.
2. DHT11 Sensor: Measures the ambient temperature and humidity.
3. OLED Display: The OLED screen displays the current temperature, humidity, and alcohol level.
4. Buzzer: The buzzer is triggered when the alcohol level exceeds the set threshold, giving an audible alert.

## Calibration
- The MQ-3 sensor needs calibration for accurate measurements. You can perform calibration by exposing the sensor to known concentrations of alcohol and noting the analog readings. Adjust the threshold in the code (if (alcoholLevel > 400)) based on your calibration results.

## Notes
- Ensure the MQ-3 sensor is preheated for a few minutes for accurate readings.
- The DHT11 sensor should be placed away from heat sources to prevent incorrect temperature readings.

## Future Improvements
- Add Bluetooth: To send data wirelessly to a smartphone.
- Data Logging: Store alcohol concentration data over time for monitoring purposes.
- Enclosure Design: Create an ergonomic enclosure for portable use.

## License
- This project is open-source and free to use for personal and educational purposes.

# Author
[Pratham Sapkal]
