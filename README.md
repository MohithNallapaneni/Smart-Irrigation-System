Smart Irrigation System
Overview:

The Smart Irrigation System is an Arduino UNO based automation project designed to optimize water usage in agriculture and gardening. The system automatically monitors soil moisture, rain conditions, temperature, humidity, and water flow to intelligently control a water pump.

The project reduces water wastage by turning the pump ON only when the soil is dry and no rain is detected. It also includes a manual override switch and an LCD display for real-time monitoring.

The pump can also be controlled and monitored through the mobile application with the help of HC-05 bluetooth module.


Components Used:
| Component                   | Purpose                                   |
| --------------------------- | ----------------------------------------- |
| Arduino UNO                 | Main microcontroller                      |
| Soil Moisture Sensor        | Measures soil moisture level              |
| Rain Sensor Module          | Detects rainfall                          |
| DHT11 Sensor                | Measures temperature and humidity         |
| HC-05 bluetooth Module      | Remote Control Through mobile             |
| Water Flow Sensor (YF-S401) | Measures water flow rate                  |
| Relay Module                | Controls water pump                       |
| DC Water Pump               | Pumps water to plants                     |
| 16x2 LCD Display            | Displays system status                    |
| Potentiometer               | Adjusts LCD contrast                      |
| Push Button Switch          | Manual pump control                       |
| 1N4007 Diode                | Protects against back EMF                 |
| Breadboard                  | Circuit connections                       |
| Jumper Wires                | Electrical connections                    |
| Resistors (220Ω, 1kΩ, 10kΩ) | Current limiting and signal stabilization |
| External Power Supply       | Powers the water pump                     |

Working Principle
1.The soil moisture sensor continuously monitors the moisture level in the soil.
2.If the soil becomes dry and no rain is detected, the Arduino activates the relay module.
3.The relay switches ON the water pump to irrigate the plants.
4.If rain is detected, the system automatically stops the pump to prevent water wastage.
5.The DHT11 sensor measures temperature and humidity conditions.
6.The water flow sensor monitors the amount of water flowing through the pipe.
7.A manual override switch allows the user to turn ON the pump manually when required.
8.All sensor values and system status are displayed on the 16x2 LCD display and Serial Monitor.
9.The bluetooth Module constantly sends the information to the mobile and keeps checking for the response/ command.

Features:
Automatic irrigation control
Soil moisture monitoring
Rain detection system
Temperature and humidity monitoring
Water flow measurement
Manual pump override
Real-time LCD display
Relay controlled water pump
Water conservation system
Modular and expandable design
Control & Monitoring through mobile 

Challenges Faced:
LCD initially displayed only black boxes due to contrast and wiring issues.
Relay operation conflicted with Bluetooth communication.
DHT11 sensor initially showed reading errors due to library conflict.
Flow sensor calibration required repeated testing.
Managing multiple sensor connections on a breadboard was difficult.

What I Learned:
Working with Arduino UNO and embedded systems
Sensor interfacing and analog/digital signal processing
Relay based load control
LCD interfacing and troubleshooting
Interrupt handling using flow sensor
Power management and common grounding
Importance of diode protection in inductive loads
Circuit debugging and hardware troubleshooting
Real-time monitoring using Serial Monitor and LCD

Future Improvements:
ESP32 can be used instead of Arduino which can provide remote access/control through wifi.
Implement IoT cloud monitoring
Add automatic scheduling system
Use solar power for energy efficiency
Add water tank level monitoring
Design a PCB for compact implementation
Add alerts

Demo Video:


