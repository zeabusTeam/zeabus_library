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

#include    <zeabus/sensor/imu::LORD_IMU_COMMUNICATION.hpp>

namespace _imu_protocol = zeabus::sensor::imu::LORD_MICROSTRAIN;

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
            void check_sum( );

            void check_sum( unsigned char MSB, unsigned char LSB );

            // This will calculate check sum and collect at this->MSB and this->LSB
            void find_check_sum( unsigned int size_packet );

        protected:
            unsigned char MSB;
            unsigned char LSB;

    }; // class Imu 

} // namespace packet

} // namespace zeabus

#endif // _ZEABUS_PACKET_IMU_HPP__
