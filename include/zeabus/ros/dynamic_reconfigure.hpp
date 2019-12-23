// FILE			: path_file.hpp
// AUTHOR		: K.Supasan
// CREATE ON	: 2019, December 23 (UTC+0)
// MAINTAINER	: K.Supasan

// MACRO DETAIL

// README

// REFERENCE

// MACRO SET

// MACRO CONDITION

#include    <ros/ros.h>

#include    <cstdio>

#include    <zeabus/ros/path_file.hpp>

#ifndef _ZEABUS_ROS_DYNAMIC_RECONFIGURE_HPP__
#define _ZEABUS_ROS_DYNAMIC_RECONFIGURE_HPP__

namespace zeabus_ros
{

    class DynamicReconfigure
    {

        public:
            DynamicReconfigure();

            void dump( const std::string package_name, 
                    const std::string directory, 
                    const std::string file_name, 
                    const std::string node_name );

            void dump( const std::string full_path,
                    const std::string node_name );

            void load( const std::string package_name,
                    const std::string directory,
                    const std::string file_name,
                    const std::string node_name );

            void load( const std::string full_path,
                    const std::string node_name );

    };

} // namespace zeabus_ros

#endif // _ZEABUS_ROS_DYNAMIC_RECONFIGURE_HPP__
