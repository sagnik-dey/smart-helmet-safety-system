# Smart Helmet Safety System

A proof-of-concept embedded safety prototype developed using an STM32 microcontroller, an MPU6050 motion sensor, and an ST12-3004PA inductive proximity sensor.

The project demonstrates real-time sensor interfacing and proximity-based audible alerts using a physical hardware prototype. The broader smart helmet concept also explores features such as accident detection, ignition interlocking, and emergency notification as proposed future extensions.

## Overview

Road accidents involving two-wheelers can result in serious injuries, particularly when safety measures such as helmet usage and rapid accident response are not available.

This project explores a smart helmet safety system using embedded sensors and a microcontroller-based prototype. The implemented hardware uses an STM32 development board, an MPU6050 accelerometer and gyroscope, an ST12-3004PA inductive proximity sensor, and an active buzzer.

The prototype demonstrates sensor interfacing and real-time proximity detection. When the inductive sensor detects a nearby metallic object, the system activates an audible buzzer alert. The MPU6050 is used to acquire motion and acceleration data.

> **Note:** The physical prototype implements sensor interfacing, MPU6050 data acquisition, inductive proximity detection, and buzzer-based alerts. Features such as motorcycle ignition control, GPS tracking, GSM/Bluetooth emergency alerts, and a fully implemented accident-detection algorithm were part of the broader proposed system but were not implemented in the physical prototype.
