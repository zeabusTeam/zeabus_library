// FILE			: connector.hpp
// AUTHOR		: K.Supasan
// CREATE ON	: 2019, September 16 (UTC+0)
// MAINTAINER	: K.Supasan

// MACRO DETAIL

// README

// REFERENCE

// MACRO SET

// MACRO CONDITION

#include    <ros/ros.h>

#include    <zeabus/packet/imu.hpp>

#include    <zeabus/escape_code.hpp>

#include    <zeabus/serial/synchronous_port.hpp>

#include    <zeabus/sensor/imu/LORD_IMU_COMMUNICATION.hpp>

namespace _imu_protocol = zeabus::sensor::imu::LORD_MICROSTRAIN;

#ifndef _ZEABUS_SENSOR_IMU_CONNECTOR_HPP__
#define _ZEABUS_SENSOR_IMU_CONNECTOR_HPP__

namespace zeabus
{

namespace sensor
{

namespace imu
{

    class Connector : public zeabus::serial::SynchronousPort 
    {
        public:
            Connector( std::string full_path );

            // This command will stop stream and set imu ready for setting
            bool set_idle( unsigned int round = 5 ); 

            bool ping( unsigned int round = 5 ); // ping command

            bool resume( unsigned int round = 5 ); // this command to continue stream

            void set_imu_rate( int rate );

            bool set_imu_message_format( unsigned char first_type , 
                    unsigned char second_type ,
                    unsigned char thrid_type ,
                    unsigned int round = 5 );

            bool enable_imu_data_stream( unsigned int round = 5 );

            bool read_stream();

            bool capture_gyro_bias();

        protected:
            unsigned char front_rate;
            unsigned char back_rate;

            // read_reply can only check desciptor byte can't check all
            //  will return false in case descriptor don't equal
            bool read_reply( unsigned char descriptor_byte );

            // connect will manage about send data and read data compare for you
            bool connect( unsigned int round , std::string function );
            zeabus::packet::Imu sender;
            zeabus::packet::Imu reader;

    }; // zeabus::sensor::imu::Connector object

} // namespace imu

} // namespace sensor

} // namespace zeabus

#endif // _ZEABUS_SENSOR_IMU_CONNECTOR_HPP__
