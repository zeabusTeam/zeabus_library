// FILE			: geometry_vector3.hpp
// AUTHOR		: K.Supasan
// CREATE ON	: 2019, September 20 (UTC+0)
// MAINTAINER	: K.Supasan

// MACRO DETAIL

// README
//  This library about conversation with geometry_msgs/Vector3

// REFERENCE

// MACRO SET

// MACRO CONDITION

#include    <geometry_msgs/Vector3.h>

#include    <tf/LinearMath/Quaternion.h>

#include    <tf/LinearMath/Vector3.h>

#include    <boost/array.hpp>

#include    <zeabus/convert/bytes.hpp>

#ifndef _ZEABUS_ROS_CONVERT_GEOMETRY_VECTOR3_HPP__
#define _ZEABUS_ROS_CONVERT_GEOMETRY_VECTOR3_HPP__

namespace zeabus_ros
{

namespace convert
{

namespace geometry_vector3 
{

    bool bytes( std::vector< unsigned char >::iterator point , 
            geometry_msgs::Vector3* message_ptr ,
            unsigned int offset = 0 ); 

    void tf( const geometry_msgs::Vector3* ptr_input , tf::Quaternion* ptr_result );
    void tf( const tf::Quaternion* ptr_input , geometry_msgs::Vector3* ptr_result );

    void array( const geometry_msgs::Vector3* ptr_source , boost::array< double , 3 >* ptr_target );
    void array( const boost::array< double , 3 >* ptr_source , geometry_msgs::Vector3* ptr_target );
    void array( const geometry_msgs::Vector3& ptr_source , boost::array< double , 3 >* ptr_target );
    void array( const boost::array< double , 3 >& ptr_source , geometry_msgs::Vector3* ptr_target );

    void tf( const tf::Vector3* ptr_input , geometry_msgs::Vector3* ptr_result );
    void tf( const geometry_msgs::Vector3* ptr_input , tf::Vector3* ptr_result );

    tf::Vector3 tf( const geometry_msgs::Vector3* ptr_source );
    geometry_msgs::Vector3 tf( const tf::Vector3* ptr_source );

    tf::Vector3 tf( const geometry_msgs::Vector3& source );
    geometry_msgs::Vector3 tf( const tf::Vector3& source );
} // namespace geometry_vector3

} // namespace convert

} // namespace zeabus_ros

#endif // _ZEABUS_ROS_CONVERT_GEOMETRY_VECTOR3_HPP__
