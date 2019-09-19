// FILE			: node.cpp
// AUTHOR		: K.Supasan
// CREATE ON	: 2019, September 19 (UTC+0)
// MAINTAINER	: K.Supasan

// MACRO DETAIL

// README

// REFERENCE

// MACRO SET

// MACRO CONDITION

#include    <zeabus/ros/node.hpp>

namespace zeabus
{

namespace ros
{

    Node::Node( int argv , char** argc , std::string node_name )
    {
        ros::init( argv , argc , node_name );
        this->node_name = node_name;
    } // Node::Node

    Node::~Node()
    {
        ros::shutdown();
        this->join();
    } // Node::~Node

    bool Node::spin()
    {
        this->thread_id = std::thread( std::bind( &zeabus::ros::Node::thread_spin , this ) );
        return true;
    } // Node::spin

    void Node:;join()
    {

    } // Node::join

    void Node::thread_spin()
    {
        std::cout   << zeabus::escape_code::normal_margenta << this->node_name
                    << " start spin thread\n" << zeabus::escape_code::normal_white;
        ros::spin();
        std::cout   << zeabus::escape_code::normal_margenta << this->node_name
                    << " end spin thread\n" << zeabus::escape_code::normal_white;
    } // Node::thread_spin

} // namespace ros

} // namespace zeabus
