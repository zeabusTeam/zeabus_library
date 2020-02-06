// FILE			: static_tf.hpp
// AUTHOR		: K.Supasan
// CREATE ON	: 2019, Febuary 06 (UTC+0)
// MAINTAINER	: K.Supasan

// MACRO DETAIL

// README

// REFERENCE

// MACRO SET

// MACRO CONDITION

#include    <mutex>

#include    <thread>

#include    <iostream>

#include    <cstdlib>

#include    <ros/ros.h>

#include    <std_msgs/Time.h>

#include    <zeabus/file.hpp>

#include    <zeabus/ros/path_file.hpp>

#include    <tf/LinearMath/Quaternion.h>

#include    <tf/transform_broadcaster.h>

#include    <geometry_msgs/TransformStamped.h>

#include    <zeabus/ros/convert/geometry_quaternion.hpp>

namespace zeabus_ros
{

    class StaticTF
    {

        public:
            StaticTF();
            // We have must have descontructor for join thread
            ~StaticTF();
            // When you setup I will collect all data to our variable
            bool setup( zeabus::FileCSV* ptr_file );
            // Spin is activate mode static transform broadcaster
            void spin( double rate = 10); 
            // This should be use thread active because I will use loop ros::ok()
            // You can run by spin
            void broadcast( double value_rate );
            // Use to print all data
            void report_information();
        protected:
            tf::TransformBroadcaster broadcaster;
            
            geometry_msgs::TransformStamped* tf_message;

            unsigned int size;

            std::thread thread_id;

            std::string* frame_id;
            std::string* child_frame;
            double* translation_x;
            double* translation_y;
            double* translation_z;
            double* rotation_x;
            double* rotation_y;
            double* rotation_z;

        private:
            zeabus::FileCSV* ptr_file;
            
            ros::Time stamp;

    };

} // namespace zeabus_ros
