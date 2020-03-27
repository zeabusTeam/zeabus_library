// FILE			: geometry_quaternion.hpp
// AUTHOR		: K.Supasan
// CREATE ON	: 2019, September 20 (UTC+0)
// MAINTAINER	: K.Supasan

// MACRO DETAIL

// README

// REFERENCE

// MACRO SET

// MACRO CONDITION

#include    <geometry_msgs/Quaternion.h>

#include    <tf/LinearMath/Quaternion.h>

#include    <zeabus/convert/bytes.hpp>

#include    <nav_msgs/Odometry.h>

#ifndef _ZEABUS_ROS_CONVERT_GEOMETRY_QUATERNION_HPP__
#define _ZEABUS_ROS_CONVERT_GEOMETRY_QUATERNION_HPP__

namespace zeabus_ros
{

namespace convert
{

namespace geometry_quaternion 
{

    bool bytes( std::vector< unsigned char >::iterator point , 
            geometry_msgs::Quaternion* message_ptr ,
            unsigned int offset = 0);

    void tf( const tf::Quaternion* source , geometry_msgs::Quaternion* target ); 
    void tf( const geometry_msgs::Quaternion* source , tf::Quaternion* target );

    void tf( const nav_msgs::Odometry* source ,  tf::Quaternion* target ); 
    void tf( const nav_msgs::Odometry source ,  tf::Quaternion* target ); 

} // namespace geometry_quaternion

} // namespace convert

} // namespace zeabus_ros

#endif // _ZEABUS_ROS_CONVERT_GEOMETRY_QUATERNION_HPP__
