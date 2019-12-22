// FILE			: path_file.cpp
// AUTHOR		: K.Supasan
// CREATE ON	: 2019, December 22 (UTC+0)
// MAINTAINER	: K.Supasan

// MACRO DETAIL

// README

// REFERENCE

// MACRO SET

// MACRO CONDITION

#include    <zeabus/ros/path_file.hpp>

namespace zeabus_ros
{

    std::string get_full_path( std::string package_name , 
            std::string sub_directory , 
            std::string file_name )
    {
        return ros::package::getPath( package_name ) + '/' + sub_directory + '/' + file_name;
    }


} // namespace zeabus_ros
