// FILE			: node.hpp
// AUTHOR		: K.Supasan
// CREATE ON	: 2019, September 19 (UTC+0)
// MAINTAINER	: K.Supasan

// MACRO DETAIL

// README

// REFERENCE

// MACRO SET

// MACRO CONDITION

#include    <thread>

#include    <iostream>

#include    <ros/ros.h>

#include    <zeabus/escape_code.hpp>

#ifndef _ZEABUS_ROS_NODE_HPP__
#define _ZEABUS_ROS_NODE_HPP__

namespace zeabus
{

namespace ros
{

    class Node
    {
        public : 
            // ros::init_node and spin for you
            Node( int argv , char** argc , std::string node_name );

            ~Node();

            bool spin();

            void join();

        protected:
            // Below function is function for split therad and run that
            void thread_spin();

            std::string node_name;

            std::thread thread_id;

    }; // class object Node

} // namespace ros

} // namespace zeabus

#endif // _ZEABUS_ROS_NODE_HPP__
