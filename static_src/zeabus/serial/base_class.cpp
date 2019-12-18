// FILE			: base_class.cpp
// AUTHOR		: K.Supasan
// CREATE ON	: 2019, August 30 (UTC+0)
// MAINTAINER	: K.Supasan

// MACRO DETAIL

// README

// REFERENCE

// MACRO SET

// MACRO CONDITION

#include    <zeabus/serial/base_class.hpp>

namespace zeabus
{

namespace serial
{
    
    BaseClass::BaseClass( std::string device_path ) : io_port( this->io_service )
    {
        this->device_path = device_path;
    } // function BaseClass::BaseClass

    BaseClass::~BaseClass()
    {
        bool result = this->close_port();
        if( ! result )
        {
            std::cout   << "Warning unsuccess close port " << this->device_path << "\n";
        }
    } // function BaseClass::~BaseClass

    bool BaseClass::open_port()
    {
        bool result;
        try
        {
            this->io_port.open( this->device_path );
            result = true;
        }
        catch( const std::exception& error_message )
        {
            std::cerr << "Error from exception : " <<error_message.what() << "\n";
            result = false;
        } // Finish try-catch
        return result;
    } // function BaseClass::open_port

    bool BaseClass::close_port()
    {
        bool result;
        _boost_error_code error_code;
        this->io_port.close( error_code );
        
        if( error_code == _boost_errc::success )
        {
            result = true;
        }
        else
        {
            result = false;
        }
        return result;
    } // function BaseClass::close_port

    bool BaseClass::is_open()
    {
        return this->io_port.is_open();
    } // function BaseClass::is_open()

    // The next is same name function but use overload for reduce compile time
    bool BaseClass::set_option_port( _boost_serial_port::baud_rate data )
    {
        bool result;    // init variable for return result of set option
        _boost_error_code error_code;
        this->io_port.set_option( data , error_code );
        if( error_code != _boost_errc::success )
        {
            result = false;
        }
        else
        {
            result = true;
        }
        return result;
    } // function BaseClass::set_option_port

    bool BaseClass::set_option_port( _boost_serial_port::flow_control data )
    {
        bool result;    // init variable for return result of set option
        _boost_error_code error_code;
        this->io_port.set_option( data , error_code );
        if( error_code != _boost_errc::success )
        {
            result = false;
        }
        else
        {
            result = true;
        }
        return result;
    } // function BaseClass::set_option_port

    bool BaseClass::set_option_port( _boost_serial_port::parity data )
    {
        bool result;    // init variable for return result of set option
        _boost_error_code error_code;
        this->io_port.set_option( data , error_code );
        if( error_code != _boost_errc::success )
        {
            result = false;
        }
        else
        {
            result = true;
        }
        return result;
    } // function BaseClass::set_option_port

    bool BaseClass::set_option_port( _boost_serial_port::stop_bits data )
    {
        bool result;    // init variable for return result of set option
        _boost_error_code error_code;
        this->io_port.set_option( data , error_code );
        if( error_code != _boost_errc::success )
        {
            result = false;
        }
        else
        {
            result = true;
        }
        return result;
    } // function BaseClass::set_option_port

    bool BaseClass::set_option_port( _boost_serial_port::character_size data )
    {
        bool result;    // init variable for return result of set option
        _boost_error_code error_code;
        this->io_port.set_option( data , error_code );
        if( error_code != _boost_errc::success )
        {
            result = false;
        }
        else
        {
            result = true;
        }
        return result;
    } // function BaseClass::set_option_port


} // namespace serial

} // namespace zeabus
