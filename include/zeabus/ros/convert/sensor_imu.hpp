// FILE			: sensor_imu.hpp
// AUTHOR		: K.Supasan
// CREATE ON	: 2019, September 20 (UTC+0)
// MAINTAINER	: K.Supasan

// MACRO DETAIL

// README
//  This library about conversation with sensor_msgs/Imu*

// REFERENCE

// MACRO SET

// MACRO CONDITION

#include    <vector>

#include    <iostream>

#include    <sensor_msgs/Imu.h>

#include    <zeabus/ros/convert/geometry_vector3.hpp>

#include    <zeabus/ros/convert/geometry_quaternion.hpp>

#ifndef _ZEABUS_ROS_CONVERT_SENSOR_IMU_HPP__
#define _ZEABUS_ROS_CONVERT_SENSOR_IMU_HPP__

namespace zeabus_ros
{

namespace convert
{

namespace sensor_imu
{

    bool bytes( std::vector< unsigned char >::iterator point , 
            sensor_msgs::Imu* message_ptr ,
            unsigned int offset_quaternion , 
            unsigned int offset_acceleration ,
            unsigned int offset_gyro_scope );

} // namespace sensor_imu

} // namespace convert

} // namespace zeabus_ros

#endif
