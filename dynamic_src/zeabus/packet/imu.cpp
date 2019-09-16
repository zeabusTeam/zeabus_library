// FILE			: imu.cpp
// AUTHOR		: K.Supasan
// CREATE ON	: 2019, September 16 (UTC+0)
// MAINTAINER	: K.Supasan

// MACRO DETAIL

// README

// REFERENCE

// MACRO SET

// MACRO CONDITION

namespace zeabus
{

namespace packet
{

    Imu::Imu() : BaseClass() {} // function construction

    Imu::~Imu() {}// function deconstuction

    bool Imu::check_sum()
    {
        unsigned int size = this->size();
        this->find_check_sum( size - 2 );
        bool result = false;
        if( ( (*this)[ size - 1 ] == this->LSB ) && (*this)[ size - 2 ] == this->MSB )
        {
            result = true;
        }
        return result;
        
    } // Imu::check_sum()

    bool Imu::check_sum( unsigned char MSB , unsigned char LSB )
    {
        bool result = false;
        this->find_check_sum( this->size() );
        if( ( this->LSB == LSB ) && ( this->MSB == MSB ) )
        {
            result = true;
        }
        return result;
    } // Imu::check_sum( 2 parameter ) overload

    void Imu::add_check_sum()
    {
        this->find_check_sum( this->size() );
        this->push( this->MSB , this->LSB );
    } // Imu::add_check_sum()

    void Imu::init_header()
    {
        this->clear();
        this->push( 0x75 , 0x65 );
    } // Imu::init_header()

    void Imu::find_check_sum( unsigned int size_packet )
    {
        this->MSB = 0;
        this->LSB = 0;
        for( unsigned int run = 0 ; run < size_packet ; run++ )
        {
            ( this->MSB ) += (*this)[ run ];
            ( this->LSB ) += this->MSB;
        } // loop check sum
    } // Imu::find_check_sum()
    
    std::vector< unsigned char >::iterator Imu::end()
    {
        return this->vector.end();
    } // imu::end


} // namespace packet 

} // namespace zeabus
