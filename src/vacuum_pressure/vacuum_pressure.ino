/*
**
** This is calibrated for VUS11-6US
**
*/
#include <ros.h>
#include <ros/time.h>
#include <sensor_msgs/FluidPressure.h>
#include <std_msgs/Float64.h>

ros::NodeHandle  nh;

std_msgs::Float64 pressure_raw_data;
sensor_msgs::FluidPressure pressure_data;
ros::Publisher pub_pressure_raw_data( "pressure_raw_data", &pressure_raw_data);
ros::Publisher pub_pressure_data( "pressure_data", &pressure_data);

const int analog_pin = 0;
unsigned long range_timer;

double getRawdata(int pin_num){
    double data;
    // Get data
    data = analogRead(pin_num);
    // calculate to V
    data *= 0.00488281;
    return data;
}

double getPressure(int pin_num){
    float data;
    // Get data
    data = analogRead(pin_num);
    // Caldulate V to Pa
    // I'm not sure.
    data *= 0.00488281;
    data -= 1;
    if (data<0) return 0;
    data *= -25000;
    return data;
}

char frameid[] = "/vacuum_pressure";

void setup()
{
  nh.initNode();
  nh.advertise(pub_pressure_raw_data);
  nh.advertise(pub_pressure_data);
  
  pressure_data.header.frame_id =  frameid;
  // Variance is unknown
  pressure_data.variance = 0;
  
}

void loop()
{
  // publish the range value every 50 milliseconds
  //   since it takes that long for the sensor to stabilize
  if ( (millis()-range_timer) > 50){
    pressure_raw_data.data = getRawdata(analog_pin);
    pressure_data.fluid_pressure = getPressure(analog_pin);
    pub_pressure_raw_data.publish(&pressure_raw_data);
    pub_pressure_data.publish(&pressure_data);
    range_timer =  millis() + 50;
  }
  nh.spinOnce();
}
