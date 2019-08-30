// FILE			: base_class.hpp
// AUTHOR		: K.Supasan
// CREATE ON	: 2019, August 25 (UTC+0)
// MAINTAINER	: K.Supasan

// MACRO DETAIL

// README
// SENSOR OPTION DOCUMENTS
//      baud rate       : rate for send symbol of message. learn in DATA COMMUNICATION
//      flow control    : The ability to stop and restart flow without any loss of bytes
//      parity          : method of detecting error in transmission
//      stop bits       : stop bits sent at the end of every character
//      character_size  : size bits of character
//      reference       : https://www.tldp.org/HOWTO/Serial-HOWTO-4.html
//                        https://en.wikipedia.org/wiki/Serial_port#Parity


// REFERENCE
//  ref01   : https://theboostcpplibraries.com/boost.system

// MACRO SET

// MACRO CONDITION

#include    <boost/asio.hpp>

#include    <boost/core/noncopyable.hpp>

#include    <vector>

namespace _boost_errc = boost::system::errc;
namespace _boost_serial_port = boost::asio::serial_port_base;
namespace _boost_error_code = boost::system::error_code;

namespace zeabus
{

namespace serial
{

    class BaseClass : private boost::noncopyable
    {
    
        public:
            BaseClass( std::string device_path );
            ~BaseClass();

            bool open_port();
            bool close_port();
            bool is_open();
            
            // Below 2 function will return about size of data
            virtual unsigned int read_data( std::vector<unsigned char>* buffer 
                , unsigned int size , int* error_code = NULL ) = 0;

            virtual unsigned int write_data( std::vector<unsigned char>* buffer 
                , unsigned int size , int* error_code = NULL ) = 0;

            // Below 2 function will use 2 above function but will already convert to string
            virtual unsigned int read_data( std::string* message , int* error_code = NULL )=0;
            virtual unsigned int write_data( std::string* message , int* error_code = NULL )=0;

            // because we want to compile this to library and reduce time of compile main code
            // that reason make we can't use template to build below function
            bool set_option_port( _boost_serial_port::baud_rate data );
            bool set_option_port( _boost_serial_port::flow_control data );
            bool set_option_port( _boost_serial_port::parity data );
            bool set_option_port( _boost_serial_port::stop_bits data );
            bool set_option_port( _boost_serial_port::character_size data );

        protected:
            std::string device_path:            // This variable collect path to dervice
            boost::asio::io_service io_service; // each port must have port service
            boost::asio::serial_port io_port;
            
    }; // class BaseClass

} // namespace serial

} // namespace zeabus
