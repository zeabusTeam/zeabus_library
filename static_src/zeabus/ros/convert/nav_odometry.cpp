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

    void tf( const nav_msgs::Odometry* source , tf::StampedTransform* dest )
    {
        *dest = tf::StampedTransform( tf::Transform( tf::Quaternion(
                        source->pose.pose.orientation.x,
                        source->pose.pose.orientation.y,
                        source->pose.pose.orientation.z,
                        source->pose.pose.orientation.w ), 
                tf::Vector3( source->pose.pose.position.x,
                        source->pose.pose.position.y,
                        source->pose.pose.position.z ) 
                ),
                source->header.stamp,
                source->header.frame_id,
                source->child_frame_id
        );
    }

} // namespace geometry_quaternion

} // namespace convert

} // namespace zeabus_ros
