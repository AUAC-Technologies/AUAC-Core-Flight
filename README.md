# Autonomous Unmanned Aerial Companion (AUAC)

<p align = "center">
<img src = "https://github.com/nyameaama/AUAC-Drone/blob/Production/docs/AUAC_assets/original/AUAC_LOGO.jpg" width = "195" height = "195"/>
</p>

### Project Goal:
The AUAC system is designed to be a dynamic personal storage system which can accompany an individual wherever they go. The goal of this project is to design a UAV which can aid and assist in the transportation of personal items such as phones,keys and minimal tier items. This project is aimed to be a proof of concept which is not meant to progress past the design stage. [Detailed Description](https://github.com/nyameaama/Autonomous-UAV/blob/master/docs/description.md)

## Control 
The AUAC drone runs a closed-loop feedback system. The control system looks at the current output and alters it to the desired condition with the control action in the system based on the output of the drone. The feedback system consists of 4 PID controllers for control of pitch, yaw and roll. For more information on tuning. [Link]()

### Project Hardware RoadMap:

Across all releases there would be iterative UAV body design to allow for higher load capacity.

![alt text](https://github.com/nyameaama/Autonomous-UAV/blob/master-platformio/CAD%20models/Body%20Prototype/Screen%20Shot%202020-06-28%20at%206.02.01%20PM%2010.28.38%20AM.png)

Initial body design. See docs for design updates

#### Release 1.0
* UAV design with load capacity of ...[(Technicalities)](https://github.com/nyameaama/Autonomous-UAV/blob/master-platformio/docs/technical.md)
* ATMEGA 2560 based microcontroller running on an arduino development board for UAV computer
* ATMEGA 328p based microcontroller running on UAV remote
* HC-SRO5 bluetooth modules x2
* GPS modules x2

#### Release 2.0
* Increased UAV load capacity
* Custom PCBs for controllers 

### Project Firmware RoadMap:

#### Release 1.0
* Autonomous UAV localisation and tracking between remote and vehicle based on GPS and bluetooth
* Active Obstacle Avoidance using ultrasonics

#### Release 2.0 
* Implementation of liDAR or camera for object detection and tracking

#### Future releases
* Mobile app to use as remote
* System for recognizing No-Fly-Zones
* Gesture Recognition
