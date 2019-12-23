// FILE			: dynamic_reconfigure.cpp
// AUTHOR		: K.Supasan
// CREATE ON	: 2019, December 23 (UTC+0)
// MAINTAINER	: K.Supasan

// MACRO DETAIL

// README

// REFERENCE

// MACRO SET

// MACRO CONDITION

#include    <zeabus/ros/dynamic_reconfigure.hpp>

namespace zeabus_ros
{

    DynamicReconfigure::DynamicReconfigure()
    {
        ;
    }

    void DynamicReconfigure::dump( const std::string package_name, 
            const std::string directory, 
            const std::string file_name, 
            const std::string node_name )
    {
        this->dump( get_full_path( package_name, directory, file_name ) , node_name );
    }

    void DynamicReconfigure::dump( const std::string full_path,
            const std::string node_name )
    {
        std::string command = "rosrun dynamic_reconfigure dynparam dump " + node_name +
                " " + full_path + " &";
        std::system( command.c_str() );
        ros::Duration( 0.1 ).sleep();
    }

    void DynamicReconfigure::load( const std::string package_name,
            const std::string directory,
            const std::string file_name,
            const std::string node_name )
    {
        this->load( get_full_path( package_name, directory, file_name ) , node_name );
    }

    void DynamicReconfigure::load( const std::string full_path,
            const std::string node_name )
    {
        std::string command = "rosrun dynamic_reconfigure dynparam load " + node_name +
                " " + full_path + " &";
        std::system( command.c_str() );
        std::cout   << "load waiting for 3 second ========> ";
        ros::Duration( 3 ).sleep();
        std::cout   << "Finish load\n";
    }

} // namespace zeabus_ros

