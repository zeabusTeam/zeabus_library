// FILE			: nav_odometry.cpp
// AUTHOR		: K.Supasan
// CREATE ON	: 2019, September 20 (UTC+0)
// MAINTAINER	: K.Supasan

// MACRO DETAIL

// README

// REFERENCE

// MACRO SET

// MACRO CONDITION

#include    <zeabus/ros/convert/nav_odometry.hpp>

namespace zeabus_ros
{

namespace convert
{

namespace nav_odometry
{

    void tf( const tf::StampedTransform* source , nav_msgs::Odometry* dest )
    {
        tf::Vector3 tf_vector = source->getOrigin();
        tf::Quaternion tf_quaternion = source->getRotation();
        dest->header.stamp = source->stamp_;
        dest->header.frame_id = source->frame_id_;
        dest->child_frame_id = source->child_frame_id_;
        dest->pose.pose.position.x = tf_vector.x();
        dest->pose.pose.position.y = tf_vector.y();
        dest->pose.pose.position.z = tf_vector.z();
        dest->pose.pose.orientation.x = tf_quaternion.x();
        dest->pose.pose.orientation.y = tf_quaternion.y();
        dest->pose.pose.orientation.z = tf_quaternion.z();
        dest->pose.pose.orientation.w = tf_quaternion.w();
    }

} // namespace geometry_quaternion

} // namespace convert

} // namespace zeabus_ros
