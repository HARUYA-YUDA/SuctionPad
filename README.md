# vacuum_pressure

## How to Introduce Demo
----
###connect robotic arm through U2D2
###connect pressure sensor through arduino

###wake mikata arm up by launch file
$ roslaunch mikata_arm_bringup bringup.launch

###run the code for pressure sensor by arduinoIDE
$ /opt/arduino-1.8.7/arduino
you might need to put the command two times.
$ rosrun rosserial_python serial_node.py /dev/ttyACM0
$ rostopic echo /pressure_raw_data
$ rosservice call /enable_all
$ rosrun mikata_suck demo


## How to Work only demo.ino
----
check where is the arduino in your computer
$ ls /dev/ttyACM*
- run the code by arduinoIDE
$ roscore
$ rosrun rosserial_python serial_node.py /dev/ttyACM0

## Sensor
----
VUS11-6US
###Feature
It answer nine 0V in 10 answers when it vacuum.


## Environment
---
 - Allienware 13
 - ArduinoUNO
```
Ubuntu16.04
ROS, kinetic
Arduino1.8.7
```
