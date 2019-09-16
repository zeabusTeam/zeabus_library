// FILE			: connector.cpp
// AUTHOR		: K.Supasan
// CREATE ON	: 2019, September 16 (UTC+0)
// MAINTAINER	: K.Supasan

// MACRO DETAIL

// README

// REFERENCE

// MACRO SET

// MACRO CONDITION

#include    <zeabus/sensor/imu/connector.hpp>

namespace zeabus
{

namespace sensor
{

namespace imu
{

    Connector::Connector( std::string full_path ) : SynchronousPort( full_path )
    {
        if( not ros::ok() )
        {
            std::cout   << zeabus::escape_code::bold_yellow 
                        << "WARNING ! Please init node before\n"
                        << zeabus::escape_code::normal_white;
        }
    } // function initail | constructor

    bool Connector::set_idle( unsigned int round )
    {
        // prepare packet for set_idle command
        this->sender.init_header();
        this->sender.push( _imu_protocol::COMMAND::BASE::DESCRIPTOR , 0x02 , 0x02 ,
                _imu_protocol::COMMAND::BASE::IDLE );
        this->sender.add_check_sum();

        bool result = this->connect( round , "set_idle" );
        return result;
    } // Connector::set_idle

    bool Connector::ping( unsigned int round )
    {
        // prepare packet for ping command
        this->sender.init_header();
        this->sender.push( _imu_protocol::COMMAND::BASE::DESCRIPTOR , 0x02 , 0x02 ,
                _imu_protocol::COMMAND::BASE::PING );
        this->sender.add_check_sum();

        bool result = this->connect( round , "ping" );
        return result;
    } //  Connector::ping

    void Connector::set_imu_rate( int rate )
    {
        this->front_rate = ( unsigned char )( ( rate & 0xff00 ) >> 8);
        this->back_rate = ( unsigned char)( rate & 0xff );
    } // Connector::set_imu_rate();

    bool Connector::set_imu_message_format( unsigned char first_type ,
            unsigned char second_type ,
            unsigned char third_type ,
            unsigned int round )
    {
        // prepare packet for set imu message format
        this->sender.init_header();
        this->sender.push( _imu_protocol::COMMAND::SENSOR::DESCRIPTOR , 0x0d , 0x0d ,
                _imu_protocol::COMMAND::SENSOR::IMU_MESSAGE_FORMAT , 0x01 , 0x03 ,
                first_type , this->front_rate , this->back_rate , // type one
                second_type , this->front_rate , this->back_rate , // type second
                third_type , this->front_rate , this->back_rate ); // type third
        this->sender.add_check_sum();

        bool result = this->connect( round , "set_imu_message_format" );
        return result;
    } // Connector::set_imu_message_format

    bool Connector::enable_imu_data_stream( unsigned int round )
    {
        // prepare packet for enable_imu_data_stream
        // can look on page 57
        this->sender.init_header();
        this->sender.push( _imu_protocol::COMMAND::SENSOR::DESCRIPTOR , 0x0a , 
                0x05 , _imu_protocol::COMMAND::SENSOR::CONTINUOUS , 0x01 , 0x01 , 0x01 ,
                0x05 , _imu_protocol::COMMAND::SENSOR::CONTINUOUS , 0x01 , 0x03 , 0x00 );
        this->sender.add_check_sum();

        bool result = this->connect( round , "enable_imu_data_stream" );
        return result;
    } // Connector::enable_imu_data_stream

    bool Connector::capture_gyro_bias()
    {
        std::cout   << "Start capture gyro bias\n";
        bool result = this->resume( 10 );
        // In between capture gyro bias you must stream data of IMU
        if( result )
        {
            // prepare packet for start capture gyro bias
            this->sender.init_header();
            this->sender.push( _imu_protocol::COMMAND::SENSOR::DESCRIPTOR , 0x04 , 0x04 ,
                    _imu_protocol::COMMAND::SENSOR::CAPTURE_GYRO_BIAS , 0x0b , 0xb8 );
            this->sender.add_check_sum();

            unsigned int num_check; 
            num_check = this->write_data( this->sender.pointer() , this->sender.size() );
            if( num_check != ( this->sender.size() ) )
            {
                std::cout   << "Failure to write data for capture gyro bias\n";
                result = false;
            }
        }

        if( result )
        {
            result = false;
            for( int count = 0 ; ros::ok() && ( ! result ) ; )
            {
                if( count == 10 )
                {
                    std::cout   << "capture_gyro_bias try to read data\n";
                    count = 0;
                }

                if( this->read_reply( this->sender[2] ) )
                {
                    // check packet reader
                    if( this->reader[5] == 0xf1 && 
                            this->reader[6] == 0x39 && 
                            this->reader[7] == 0x00 )
                    {
                        std::cout   << "capture_gyro_bias success get data\n";
                        result = true;
                    }
                }
                count++;
            } // loop for read data
        }

        std::vector< unsigned char > gyro_bias;
        for( unsigned int run = 10 ; ( run < 22 ) && result ; run++ )
        {
            gyro_bias.push_back( this->reader[ run ] );
        }
        // prepare packet for set new value of gyro bias
        this->sender.init_header();
        this->sender.push( _imu_protocol::COMMAND::SENSOR::DESCRIPTOR , 0x0f , 0x0f ,
                _imu_protocol::COMMAND::SENSOR::GYRO_BIAS , 0x01 );
        for( unsigned int run = 0 ; ( run < 12 ) && result ; run++ )
        {
            this->sender.push( gyro_bias[ run ] );
        }

        if( result )
        {
            this->sender.add_check_sum();
            unsigned int num_check = this->write_data( this->sender.pointer() , 
                    this->sender.size() );
            if( num_check == this->sender.size() )
            {
                result = false;
                while( (! result ) && ros::ok() )
                {
                    if( this->read_reply( this->sender[2] ) )
                    {
                        if( ( this->reader[6] == 0x38 ) && ( this->reader[7] == 0x00 ) )
                        {
                            result = true;
                            std::cout   << "Success to write gyro bias\n";
                        }
                    }
                }
            }
        }
        return result;
    } // Connector::capture_gyro_bias 

    // Function for easy connect to imu by write and read
    bool Connector::connect( unsigned int round , std::string function )
    {
        bool result = false;
        unsigned int num_check = this->write_data( this->sender.pointer(), this->sender.size() );
        unsigned int count = round;
        if( num_check == this->sender.size() )
        {
            count = 0;
        }
        else
        {
            std::cout   << zeabus::escape_code::bold_red << "FATAL : "
                        << zeabus::escape_code::normal_white << "Failure to write for "
                        << function << "\n";
        }

        while( ros::ok() && count < round )
        {
            if( this->read_reply( this->sender[2] ) )
            {
                // If ok that mean data correct pattern and check sum is ok
                result = ( ( *( this->reader.end() - 3 ) ) == 0x00 );
                if( result )
                {
                    std::cout   << "Success command " << function << "\n";
                    break;
                }
            }
            count++;
        }

        return result;
    } // Connector::connect

    bool Connector::read_reply( unsigned char descriptor_byte )
    {
        bool result = false;
        std::vector<unsigned char> buffer;
        unsigned int size;
        while( ros::ok() )
        {
            (void)this->read_data( &buffer , 1 );
            if( buffer[0] != 'u' ) continue;
            
            (void)this->read_data( &buffer , 1 );
            if( buffer[0] != 'e' ) continue;

            size = this->read_data( &buffer , 2 );
            if( size != 2 ) continue;

            // Start create buffer for read
            this->reader.init_header();
            this->reader.push( buffer[0] , buffer[1] );

            size = buffer[1] + 2; // Payload length and check sum
            size = this->read_data( &buffer , size );
            if( size != buffer.size() ) continue;

            for( unsigned int run = 0 ; run < size ; run++ )
            {
                this->reader.push( buffer[run] );
            }

            if( ( this->reader[2] == descriptor_byte ) && this->reader.check_sum() )
            {
                result = true;
            }
            break;
        }
        return result;
    }

} // namespace imu

} // namespace sensor

} // namespace zeabus
