# vacuum_pressure
![env](https://github.com/HARUYA-YUDA/vacuum_pressure/blob/master/env.JPG)
## Download
 - Download it wherever you want
 - It's recommended to put in src/

## How to Introduce Demo
1. Connect robotic arm through U2D2
1. Connect pressure sensor through arduino

1. Wake mikata arm up by launch file  
  $ roslaunch mikata_arm_bringup bringup.launch

1. Run the code for pressure sensor by arduinoIDE  
  $ /opt/arduino-1.8.7/arduino  
  You might need to put the command two times.  
  $ rosrun rosserial_python serial_node.py /dev/ttyACM0  
  $ rostopic echo /pressure_raw_data  
  $ rosservice call /enable_all  
  $ rosrun mikata_suck demo  


## How to Work only demo.ino
Check where is the arduino in your computer  
  $ ls /dev/ttyACM*  
- Run the code by arduinoIDE  
  $ roscore  
  $ rosrun rosserial_python serial_node.py /dev/ttyACM0  

## Sensor
----
VUSd11-6US
 - Feature  
It answer nine 0V in 10 answers when it vacuum.  
 - Like followings
```
0
0
0
1
0
0
0
0
0
0
```

## Environment
---
 - Allienware 13
 - ArduinoUNO
 - mikata arm
```
Ubuntu16.04
ROS, kinetic
Arduino1.8.7
```
