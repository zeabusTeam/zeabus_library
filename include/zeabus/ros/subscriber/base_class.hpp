// FILE			: base_class.hpp
// AUTHOR		: K.Supasan
// CREATE ON	: 2019, October 24 (UTC+0)
// MAINTAINER	: K.Supasan

// MACRO DETAIL

// README

// REFERENCE

// MACRO SET

// MACRO CONDITION

#include    <iostream>

#include    <ros/ros.h>

#include    <mutex>

#ifndef _ZEABUS_ROS_SUBSCRIBER_BASE_HPP__
#define _ZEABUS_ROS_SUBSCRIBER_BASE_HPP__

namespace zeabus_ros
{

namespace subscriber
{

    template< class data_type >
    class BaseClass
    {
        public:
            BaseClass( ros::NodeHandle* ptr_node_handle , data_type* ptr_data );

            void callback( const data_type& message );

            void callback_timestamp( const data_type& message );

            void setup_mutex_data( std::mutex* ptr_mutex_data );

            void setup_subscriber( std::string topic , unsigned int queue_size );

            void setup_subscriber_timestamp( std::string topic , unsigned int queue_size );

            BaseClass();

            void setup_base( ros::NodeHandle* ptr_node_handle , data_type* ptr_data );

        protected:
            data_type* ptr_data;

            std::mutex* ptr_mutex_data;

            ros::NodeHandle* ptr_node_handle;

            ros::Subscriber subscribe_server;

    };

} // namespace subscriber

} // namespace zeabus_ros

#include    <zeabus/ros/subscriber/base_class.cpp>
#endif // _ZEABUS_ROS_SUBSCRIBER_BASE_HPP__
