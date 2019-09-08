// FILE			: synchronous_port.cpp
// AUTHOR		: K.Supasan
// CREATE ON	: 2019, September 08 (UTC+0)
// MAINTAINER	: K.Supasan

// MACRO DETAIL

// README

// REFERENCE

// MACRO SET

// MACRO CONDITION

#include    <zeabus/serial/synchronous_port.hpp>

namespace zeabus
{

namespace serial
{

    SynchronousPort::SynchronousPort( std::string device_path ) : BaseClass( device_path ){}

    // Below 2 function will return about size of data
    unsigned int SynchronousPort::read_data( std::vector<unsigned char>* buffer , 
            unsigned int size , 
            int* error_code )
    {

        if( buffer->size() < size ) // Make sure you buffer have length >= desire to read
        {
            buffer->resize( size );
        }

        boost::system::error_code boost_error;

        unsigned int size_data =  boost::asio::read( this->io_port , 
                boost::asio::buffer( *buffer , size ) ,
                boost_error );

        *error_code = boost_error.value();

        return size_data;

    } // function read_data

    unsigned int SynchronousPort::write_data( std::vector< unsigned char>* buffer , 
            unsigned int size ,
            int* error_code )
    {

        boost::system::error_code boost_error;

        unsigned int size_data = boost::asio::read( this->io_port ,
                boost::asio::buffer( *buffer , size ) ,
                boost_error );

        *error_code = boost_error.value();

        return size_data;
    }  // function write_data

    // Below 2 function will use 2 above function but will already convert to string
    unsigned int SynchronousPort::read_data( std::string* message , int* error_code )
    {

        boost::system::error_code boost_error = 
                _boost_errc::make_error_code( _boost_errc::success ); // Start by success read

        bool continue_read = true; // For start by want to continue read data

        unsigned int size_message = 0;

        *message = ""; // We must to clear origin data

        char buffer; // use to buufer for use read library

        while( continue_read && ( boost_error == _boost_errc::success ) )
        {
            size_message += boost::asio::read( this->io_port ,
                    boost::asio::buffer( &buffer , 1 ) ,
                    boost_error );

            switch( buffer )
            {
            case '\n':
                continue_read = false;
            case '\0':
            case '\r':
                break;
            default :
                *message += buffer;
            } // End SWITCH-CASE to anlysis data

        } // End loop for read data

        *error_code = boost_error.value();

        return size_message;
            
    } // End function read_data overload? for in case tou want to read string 

    unsigned int SynchronousPort::write_data( std::string* message , int* error_code )
    {
        boost::system::error_code boost_error;
    
        unsigned int size_message = boost::asio::write( this->io_port ,
                boost::asio::buffer( *message ) ,
                boost::asio::transfer_all() ,
                boost_error );

        *error_code = boost_error.value();

        return size_message;
    } // End function write data

} // namespace serial

} // namespace zeabus
