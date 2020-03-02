// FILE			: geometry_vector3.cpp
// AUTHOR		: K.Supasan
// CREATE ON	: 2019, September 20 (UTC+0)
// MAINTAINER	: K.Supasan

// MACRO DETAIL

// README

// REFERENCE

// MACRO SET

// MACRO CONDITION

#include    <zeabus/ros/convert/geometry_vector3.hpp>

namespace zeabus_ros
{

namespace convert
{

namespace geometry_vector3
{

    bool bytes( std::vector< unsigned char >::iterator point ,
            geometry_msgs::Vector3* message_ptr , 
            unsigned int offset )
    {
        (void)zeabus::convert::bytes::to_float( point , &message_ptr->x , 0 + offset);
        (void)zeabus::convert::bytes::to_float( point , &message_ptr->y , 4 + offset);
        (void)zeabus::convert::bytes::to_float( point , &message_ptr->z , 8 + offset);
        return true;
    } // function bytes type source vector unsigned char and message Vector3

    void tf( const tf::Quaternion* ptr_input , geometry_msgs::Vector3* ptr_output )
    {
        ptr_output->x = ptr_input->x();
        ptr_output->y = ptr_input->y();
        ptr_output->z = ptr_input->z();
    } // function to set value of message from quatenrion

    void tf( const geometry_msgs::Vector3* ptr_input , tf::Quaternion* ptr_output )
    {
        *ptr_output = tf::Quaternion( ptr_input->x , ptr_input->y , ptr_input->z , 0 );
    } // function to init value quaternion from vector3 for rotation by quaternion

    void tf( const tf::Vector3* ptr_input , geometry_msgs::Vector3* ptr_output )
    {
        ptr_output->x = ptr_input->x();
        ptr_output->y = ptr_input->y();
        ptr_output->z = ptr_input->z();
    }

    void tf( const geometry_msgs::Vector3* ptr_input , tf::Vector3* ptr_output )
    {
        *ptr_output = tf::Vector3( ptr_input->x , ptr_input->y , ptr_input->z );
    }

    void array( const geometry_msgs::Vector3* ptr_source , boost::array< double , 3 >* ptr_target ) 
    {
        ptr_target->at( 0 ) = ptr_source->x;
        ptr_target->at( 1 ) = ptr_source->y;
        ptr_target->at( 2 ) = ptr_source->z;
    } // function to copy vector3 to boost::array

    void array( const boost::array< double , 3 >* ptr_source , geometry_msgs::Vector3* ptr_target )
    {
        ptr_target->x = ptr_source->at( 0 );
        ptr_target->y = ptr_source->at( 1 );
        ptr_target->z = ptr_source->at( 2 );
    } // function to copy boost::array to vector3

    tf::Vector3 tf( const geometry_msgs::Vector3* ptr_source )
    {
        return tf::Vector3( ptr_source->x , ptr_source->y , ptr_source->z );
    }

    geometry_msgs::Vector3 tf( const tf::Vector3* ptr_source )
    {
        geometry_msgs::Vector3 result;
        result.x = ptr_source->x();
        result.y = ptr_source->y();
        result.z = ptr_source->z();
        return result;
    }

    tf::Vector3 tf( const geometry_msgs::Vector3& source )
    {
        return tf::Vector3( source.x , source.y , source.z );
    }

    geometry_msgs::Vector3 tf( const tf::Vector3& source )
    {
        geometry_msgs::Vector3 result;
        result.x = source.x();
        result.y = source.y();
        result.z = source.z();
        return result;
    }

    void array( const geometry_msgs::Vector3& ptr_source , boost::array< double , 3 >* ptr_target ) 
    {
        ptr_target->at( 0 ) = ptr_source.x;
        ptr_target->at( 1 ) = ptr_source.y;
        ptr_target->at( 2 ) = ptr_source.z;
    } // function to copy vector3 to boost::array

    void array( const boost::array< double , 3 >& ptr_source , geometry_msgs::Vector3* ptr_target )
    {
        ptr_target->x = ptr_source.at( 0 );
        ptr_target->y = ptr_source.at( 1 );
        ptr_target->z = ptr_source.at( 2 );
    } // function to copy boost::array to vector3

} // namespace geometry_vector3

} // namespace convert

} // namespace zeabus_ros
