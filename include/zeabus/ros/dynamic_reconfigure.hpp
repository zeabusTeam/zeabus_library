// FILE			: dynamic_reconfigure.hpp
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

#include    <dynamic_reconfigure/server.h>

#include    <mutex>
#include    <iostream>

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

    template< class config_type >
    class DynamicReconfigureServer
    {
        public:
            DynamicReconfigureServer( config_type* ptr_default_config );

            void setup_variable( config_type* ptr_config_data,
                    std::mutex* ptr_lock_data,
                    int* ptr_level_data );
            void spin();
            void callback( config_type& config , uint32_t level );

            dynamic_reconfigure::Server< config_type > server_reconfigure;
//            dynamic_reconfigure::Server< config_type >::CallbackType function_reconfigure;

        protected:
            config_type* ptr_default_config; // use to collect dafault data
            config_type* ptr_config_data; // use to connect current config data
            std::mutex* ptr_lock_data; // use to collect mutex access data
            int* ptr_level_data; // use to collect level of config message
            

    };

} // namespace zeabus_ros

//#include    <zeabus/ros/dynamic_reconfigure.cpp>
#endif // _ZEABUS_ROS_DYNAMIC_RECONFIGURE_HPP__
