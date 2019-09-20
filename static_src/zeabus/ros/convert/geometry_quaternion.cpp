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
        (void)zeabus::convert::bytes::to_float( point , &message_ptr->w , 0 );
        (void)zeabus::convert::bytes::to_float( point , &message_ptr->x , 4 );
        (void)zeabus::convert::bytes::to_float( point , &message_ptr->y , 8 );
        (void)zeabus::convert::bytes::to_float( point , &message_ptr->z , 12 );
    } // function bytes type source vector unsigned char and message Vector3

} // namespace geometry_quaternion

} // namespace convert

} // namespace zeabus_ros
