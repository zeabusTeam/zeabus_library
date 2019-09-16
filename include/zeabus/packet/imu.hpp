// FILE			: imu.hpp
// AUTHOR		: K.Supasan
// CREATE ON	: 2019, September 16 (UTC+0)
// MAINTAINER	: K.Supasan

// MACRO DETAIL

// README

// REFERENCE

// MACRO SET

// MACRO CONDITION

#include    <zeabus/packet/base_class.hpp>

#ifndef _ZEABUS_PACKET_IMU_HPP__
#define _ZEABUS_PACKET_IMU_HPP__

namespace zeabus
{

namespace packet
{

    class Imu : public BaseClass< unsigned char >
    {

        public: 
            Imu();

            ~Imu();

            // This function use to check_sum in pattern of IMU Loard Microstrain Protocol
            //  function check_sum() will compare with last two element
            //  function check_sum( 2 parameter ) will find check sum all packet and checkt it
            bool check_sum( );

            bool check_sum( unsigned char MSB, unsigned char LSB );

            void add_check_sum();

            // This will calculate check sum and collect at this->MSB and this->LSB
            void find_check_sum( unsigned int size_packet );

            // Init protocal of IMU packet
            void init_header();

            std::vector< unsigned char >::iterator end();

        protected:
            unsigned char MSB;
            unsigned char LSB;

    }; // class Imu 

} // namespace packet

} // namespace zeabus

#include    <zeabus/packet/imu.cpp>

#endif // _ZEABUS_PACKET_IMU_HPP__
