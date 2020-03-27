// FILE			: geometry_quaternion.cpp
// AUTHOR		: K.Supasan
// CREATE ON	: 2019, September 20 (UTC+0)
// MAINTAINER	: K.Supasan

// MACRO DETAIL

// README

// REFERENCE

// MACRO SET

// MACRO CONDITION

#include    <zeabus/ros/convert/geometry_quaternion.hpp>

namespace zeabus_ros
{

namespace convert
{

namespace geometry_quaternion
{

    bool bytes( std::vector< unsigned char >::iterator point ,
            geometry_msgs::Quaternion* message_ptr , 
            unsigned int offset )
    {
        (void)zeabus::convert::bytes::to_float( point , &message_ptr->w , 0 + offset );
        (void)zeabus::convert::bytes::to_float( point , &message_ptr->x , 4 + offset );
        (void)zeabus::convert::bytes::to_float( point , &message_ptr->y , 8 + offset );
        (void)zeabus::convert::bytes::to_float( point , &message_ptr->z , 12 + offset );
        return true;
    } // function bytes type source vector unsigned char and message Vector3

    void tf( const tf::Quaternion* source , geometry_msgs::Quaternion* target )
    {
        target->w = source->w();
        target->x = source->x();
        target->y = source->y();
        target->z = source->z();
    } // function get move data from tf:;Quaternion to Quaternion message 

    void tf( const geometry_msgs::Quaternion* source , tf::Quaternion* target )
    {
        *target = tf::Quaternion( source->x , source->y , source->z , source->w );
    } // function get move data from geometry_msgs:;Quaternion to tf::Quaternion

    void tf( const nav_msgs::Odometry source , tf::Quaternion* target )
    {
        *target = tf::Quaternion( source.pose.pose.orientation.x , 
                source.pose.pose.orientation.y , 
                source.pose.pose.orientation.z , 
                source.pose.pose.orientation.w );
    } // function get move data from geometry_msgs:;Quaternion to tf::Quaternion

    void tf( const nav_msgs::Odometry* source , tf::Quaternion* target )
    {
        *target = tf::Quaternion( source->pose.pose.orientation.x , 
                source->pose.pose.orientation.y , 
                source->pose.pose.orientation.z , 
                source->pose.pose.orientation.w );
    } // function get move data from geometry_msgs:;Quaternion to tf::Quaternion


} // namespace geometry_quaternion

} // namespace convert

} // namespace zeabus_ros
