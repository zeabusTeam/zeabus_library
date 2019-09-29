// FILE			: node.hpp
// AUTHOR		: K.Supasan
// CREATE ON	: 2019, September 19 (UTC+0)
// MAINTAINER	: K.Supasan

// MACRO DETAIL

// README

// REFERENCE
//  ref01 : https://en.cppreference.com/w/cpp/thread/thread/join
//  ref02 : https://en.cppreference.com/w/cpp/error/system_error

// MACRO SET

// MACRO CONDITION

#include    <thread>

#include    <iostream>

#include    <ros/ros.h>

#include    <zeabus/escape_code.hpp>

#ifndef _ZEABUS_ROS_NODE_HPP__
#define _ZEABUS_ROS_NODE_HPP__

namespace zeabus_ros
{

    class Node
    {
        public : 
            // ros::init_node and spin for you
            Node( int argv , char** argc , std::string node_name );

            ~Node();

            void spin();

            void join();

        protected:
            // Below function is function for split therad and run that
            void thread_spin();

            std::string node_name;

            std::thread thread_id;

            bool state; // If you spin will true if you join will false

    }; // class object Node

} // namespace zeabus

#endif // _ZEABUS_ROS_NODE_HPP__
