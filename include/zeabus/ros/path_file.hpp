// FILE			: path_file.hpp
// AUTHOR		: K.Supasan
// CREATE ON	: 2019, December 22 (UTC+0)
// MAINTAINER	: K.Supasan

// MACRO DETAIL

// README

// REFERENCE

// MACRO SET

// MACRO CONDITION

#include    <ros/ros.h>

#include    <ros/package.h>

namespace zeabus_ros
{

    // We auto push '/' for you
    std::string get_full_path( std::string package_name , 
            std::string sub_directory , 
            std::string file_name );

} // namespace zeabus_ros

