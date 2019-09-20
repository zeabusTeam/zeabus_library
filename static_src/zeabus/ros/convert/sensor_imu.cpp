// FILE			: sensor_imu.cpp
// AUTHOR		: K.Supasan
// CREATE ON	: 2019, September 20 (UTC+0)
// MAINTAINER	: K.Supasan

// MACRO DETAIL

// README

// REFERENCE

// MACRO SET

// MACRO CONDITION

#include    <zeabus/ros/convert/sensor_imu.hpp>

namespace zeabus_ros
{

namespace convert
{

namespace sensor_imu
{

    bool bytes( std::vector< unsigned char>::iterator point , 
            sensor_msgs::Imu* message_ptr ,
            unsigned int offset_quaternion ,
            unsigned int offset_acceleration ,
            unsigned int offset_gyro_scope )
    {
        (void)zeabus_ros::convert::geometry_quaternion::bytes( point , 
                &message_ptr->orientation ,
                offset_quaternion );
        (void)zeabus_ros::convert::geometry_vector3::bytes( point ,
                &message_ptr->linear_acceleration , 
                offset_acceleration );
        (void)zeabus_ros::convert::geometry_vector3::bytes( point , 
                &message_ptr->angular_velocity ,
                offset_gyro_scope );
        return true; // Don't mean anything
    }

} // namespace sensor_imu

} // namespace convert

} // namespace zeabus_ros
