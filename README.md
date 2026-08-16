# Smart Helmet Safety System

A proof-of-concept embedded safety prototype developed using an STM32 microcontroller, an MPU6050 motion sensor, and an ST12-3004PA inductive proximity sensor.

The project demonstrates real-time sensor interfacing and proximity-based audible alerts using a physical hardware prototype. The broader smart helmet concept also explores features such as accident detection, ignition interlocking, and emergency notification as proposed future extensions.

## Overview

Road accidents involving two-wheelers can result in serious injuries, particularly when safety measures such as helmet usage and rapid accident response are not available.

This project explores a smart helmet safety system using embedded sensors and a microcontroller-based prototype. The implemented hardware uses an STM32 development board, an MPU6050 accelerometer and gyroscope, an ST12-3004PA inductive proximity sensor, and an active buzzer.

The prototype demonstrates sensor interfacing and real-time proximity detection. When the inductive sensor detects a nearby metallic object, the system activates an audible buzzer alert. The MPU6050 is used to acquire motion and acceleration data.

> **Note:** The physical prototype implements sensor interfacing, MPU6050 data acquisition, inductive proximity detection, and buzzer-based alerts. Features such as motorcycle ignition control, GPS tracking, GSM/Bluetooth emergency alerts, and a fully implemented accident-detection algorithm were part of the broader proposed system but were not implemented in the physical prototype.

## Implemented Features

The physical prototype demonstrates the following functionality:

- **STM32-based embedded prototype** for sensor interfacing and control
- **MPU6050 interfacing** for real-time accelerometer and gyroscope data acquisition
- **ST12-3004PA inductive proximity sensing** for detecting nearby metallic objects
- **Buzzer-based alert system** activated when the proximity sensor detects a metallic object
- **Real-time sensor monitoring** through the program's main control loop
- Physical hardware implementation using a development board, sensors, breadboard, and connecting circuitry

## Proposed Features

The broader smart helmet system was designed with several additional safety features that were proposed but not implemented in the physical prototype:

- Helmet-wearing detection
- Motorcycle ignition interlock using a relay
- Accident detection using calibrated MPU6050 thresholds
- GPS-based location tracking
- GSM or Bluetooth-based emergency notification
- Automatic alerts to predefined emergency contacts

## Hardware Components

| Component | Role |
|---|---|
| **STM32 Development Board** | Central microcontroller used for sensor interfacing and control |
| **MPU6050** | Provides accelerometer and gyroscope data for motion monitoring |
| **ST12-3004PA Inductive Proximity Sensor** | Detects nearby metallic objects |
| **Active Buzzer** | Generates an audible alert when triggered by the proximity sensor |
| **Breadboard and Jumper Wires** | Used for prototyping and hardware connections |
| **Power Supply** | Provides power to the prototype hardware |

## Hardware Prototype

The system was developed and tested as a physical proof-of-concept prototype using an STM32 development board, MPU6050 motion sensor, ST12-3004PA inductive proximity sensor, active buzzer, and breadboard-based connections.

### Prototype Setup

![Smart Helmet Hardware Prototype](images/hardware_protoype_1.jpg)

### Sensor and Circuit Setup

![Smart Helmet Sensor Setup](images/hardware_protoype_2.jpg)

## System Architecture

The implemented prototype uses two sensors connected to the STM32 microcontroller. The MPU6050 provides motion data, while the ST12-3004PA inductive proximity sensor detects nearby metallic objects. Based on the sensor input, the microcontroller controls the buzzer output.

![System Block Diagram](docs/blockdiag.png)

## Working Principle

The prototype operates through continuous sensor monitoring:

1. The STM32 initializes the connected sensors and output devices.
2. The MPU6050 provides real-time accelerometer and gyroscope data for motion monitoring.
3. The ST12-3004PA inductive proximity sensor continuously checks for the presence of a nearby metallic object.
4. The sensor state is read by the microcontroller.
5. When a metallic object is detected, the STM32 activates the active buzzer.
6. The buzzer remains active for the programmed alert duration and is then turned off.
7. The system continues monitoring the sensors in a continuous loop.

### Implemented Control Flow

```text
Start
  ↓
Initialize STM32, MPU6050 and Buzzer
  ↓
Read MPU6050 Motion Data
  ↓
Read Inductive Proximity Sensor
  ↓
Metal Object Detected?
   ├── Yes → Activate Buzzer
   │
   └── No  → Keep Buzzer OFF
              ↓
       Continue Monitoring
```
## Proposed Smart Helmet System

The project was initially conceptualized as a broader motorcycle safety system. The following features were included in the proposed architecture but were not implemented in the physical prototype:

- Helmet-wearing verification
- Motorcycle ignition control using a relay
- Accident detection based on sensor thresholds
- GPS location retrieval
- Emergency alerts to predefined contacts

The flowchart below represents this proposed full-system workflow.

> **Note:** GPS, emergency communication, ignition interlocking, and automatic accident response were conceptual/proposed features and are not claimed as implemented functionality in this repository.

![Proposed Smart Helmet System Flowchart](docs/proposed_system_flowchart.png)

## Code Overview

The firmware interfaces with the MPU6050 using the `Wire`, `Adafruit_MPU6050`, and `Adafruit_Sensor` libraries.

The program performs the following operations:

- Initializes serial communication
- Configures the buzzer and inductive sensor GPIO pins
- Initializes and configures the MPU6050
- Reads real-time accelerometer and gyroscope data
- Reads the state of the inductive proximity sensor
- Activates the buzzer when a metallic object is detected
- Continuously repeats the monitoring process

The source code is available here:

[`smart_helmet.ino`](code/smart_helmet.ino)

## Technical Documentation

An unpublished technical paper prepared as part of this academic project is included in the repository.

The paper discusses the broader smart helmet safety concept, system architecture, and proposed extensions beyond the implemented prototype.

> **Note:** Some features discussed in the technical paper, including ignition control, GPS-based tracking, emergency communication, and accident-response functionality, were proposed or simulated concepts and were not implemented in the physical prototype.

[View the Project Technical Paper](docs/project_technical_paper.pdf)

## Project Structure

```text
smart-helmet-safety-system/
│
├── README.md
│
├── code/
│   └── smart_helmet.ino
│
├── docs/
│   ├── block_diagram.png
│   ├── proposed_system_flowchart.png
│   └── project_technical_paper.pdf
│
└── images/
    ├── hardware_prototype_1.jpg
    └── hardware_prototype_2.jpg
```

## Future Improvements

Potential extensions for the project include:

- Implementing calibrated impact-detection thresholds using MPU6050 data
- Integrating reliable helmet-wearing detection
- Adding a relay-based motorcycle ignition interlock
- Adding GPS for location tracking
- Integrating GSM or Bluetooth communication for emergency alerts
- Designing a dedicated PCB instead of a breadboard prototype
- Improving power management for battery-operated deployment
- Integrating the prototype into an actual helmet for real-world testing
