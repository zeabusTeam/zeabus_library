// FILE			: geometry_vector3.cpp
// AUTHOR		: K.Supasan
// CREATE ON	: 2019, September 20 (UTC+0)
// MAINTAINER	: K.Supasan

// MACRO DETAIL

// README

// REFERENCE

// MACRO SET

// MACRO CONDITION

#include    <zeabus/ros/convert/geometry_vector3.hpp>

namespace zeabus_ros
{

namespace convert
{

namespace geometry_vector3
{

    bool bytes( std::vector< unsigned char >::iterator point ,
            geometry_msgs::Vector3* message_ptr , 
            unsigned int offset )
    {
        (void)zeabus::convert::bytes::to_float( point , &message_ptr->x , 0 + offset);
        (void)zeabus::convert::bytes::to_float( point , &message_ptr->y , 4 + offset);
        (void)zeabus::convert::bytes::to_float( point , &message_ptr->z , 8 + offset);
        return true;
    } // function bytes type source vector unsigned char and message Vector3

} // namespace geometry_vector3

} // namespace convert

} // namespace zeabus_ros
