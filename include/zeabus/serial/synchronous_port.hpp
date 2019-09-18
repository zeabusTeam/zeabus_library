// FILE			: synchronous_port.hpp
// AUTHOR		: K.Supasan
// CREATE ON	: 2019, September 07 (UTC+0)
// MAINTAINER	: K.Supasan

// MACRO DETAIL

// README
//  LETTER01 :
//      This time I desize about when you read and write.
//      It not my reposible to detect and warn you.
//      It only interfacce to boost library
//  

// REFERENCE
//  ref01 : https://theboostcpplibraries.com/boost.system
//  ref02 : https://en.cppreference.com/w/cpp/language/try_catch

// MACRO SET

// MACRO CONDITION

#include    <zeabus/serial/base_class.hpp>

#ifndef _ZEABUS_SERIAL_SYNCHRONOUS_PORT_HPP__
#define _ZEABUS_SERIAL_SYNCHRONOUS_PORT_HPP__

namespace zeabus
{

namespace serial
{

    class SynchronousPort : public BaseClass
    {

        public:
            SynchronousPort( std::string device_path );

            // Below 2 function will return about size of data
            unsigned int read_data( std::vector<unsigned char>* buffer 
                , unsigned int size , int* error_code = NULL );

            unsigned int write_data( std::vector<unsigned char>* buffer 
                , unsigned int size , int* error_code = NULL );

            // Below 2 function will use 2 above function but will already convert to string
            unsigned int read_data( std::string* message , int* error_code = NULL );
            unsigned int write_data( std::string* message , int* error_code = NULL );

    }; // class SynchronousPort

} // namespace serial

} // namespace zeabus

#endif
