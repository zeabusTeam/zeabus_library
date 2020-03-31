// FILE			: nav_odometry.hpp
// AUTHOR		: K.Supasan
// CREATE ON	: 2020, March 20 (UTC+0)
// MAINTAINER	: K.Supasan

// MACRO DETAIL

// README

// REFERENCE

// MACRO SET

// MACRO CONDITION

#include    <nav_msgs/Odometry.h>

#include    <tf/transform_datatypes.h>

#include    <tf/LinearMath/Quaternion.h>

#ifndef _ZEABUS_ROS_CONVERT_NAV_ODOMETRY_HPP__
#define _ZEABUS_ROS_CONVERT_NAV_ODOMETRY_HPP__

namespace zeabus_ros
{

namespace convert
{

namespace nav_odometry
{

    void tf( const tf::StampedTransform* source , nav_msgs::Odometry* dest );

    void tf( const nav_msgs::Odometry* source , tf::StampedTransform* dest );

} // namesapce nav_odometry

} // namesapce convert

} // namespace zeabus_ros

#endif // _ZEABUS_ROS_CONVERT_NAV_ODOMETRY_HPP__
