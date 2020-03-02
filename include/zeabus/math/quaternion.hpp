// FILE			: quaternion.hpp
// AUTHOR		: K.Supasan
// CREATE ON	: 2020, Febuary 25 (UTC+0)
// MAINTAINER	: K.Supasan

// MACRO DETAIL

// README
//  This is externsion from tf::Quaternion and conversation about message
//  This will support about quaternion part
//  All this part main convention is yaw pitch roll

// REFERENCE

// MACRO SET

// MACRO CONDITION

#include    <tf/LinearMath/Quaternion.h>

#include    <tf/LinearMath/Vector3.h>

#include    <geometry_msgs/Quaternion.h>

#include    <boost/array.hpp>

#include    <cmath>

#ifndef _ZEABUS_MATH_QUATENRION_HPP__
#define _ZEABUS_MATH_QUATENRION_HPP__

namespace zeabus
{

namespace math
{
    void get_euler( const tf::Quaternion source, 
            double* roll , double* pitch , double* yaw );

    void get_euler( const geometry_msgs::Quaternion source,
            double* roll , double* pitch , double* yaw );

    void rotation( const tf::Quaternion& quaternion , tf::Vector3* vector );
    void inv_rotation( const tf::Quaternion& quaternion , tf::Vector3* vector );

    void rotation( const tf::Quaternion& quaternion , boost::array< double , 3 >* vector );
    void inv_rotation( const tf::Quaternion& quaternion , boost::array< double , 3 >* vector );

} // namespace mat

} // namespace zeabus

#endif // _ZEABUS_MATH_QUATENRION_HPP__
