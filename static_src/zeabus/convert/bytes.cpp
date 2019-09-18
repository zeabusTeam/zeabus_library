// FILE			: bytes.cpp
// AUTHOR		: K.Supasan
// CREATE ON	: 2019, September 18 (UTC+0)
// MAINTAINER	: K.Supasan

// MACRO DETAIL

// README

// REFERENCE

// MACRO SET

// MACRO CONDITION

#include    <zeabus/convert/bytes.hpp>

namespace zeabus
{

namespace convert
{

namespace bytes
{

    bool to_float( std::vector< unsigned char >* data ,
            float* answer ,
            unsigned int offset )
    {
        bool result = true;
        unsigned int size = data->size();
        unsigned long int data32 = 0;
        if( offset + 3 < size )
        {
            data32 = ( ( (unsigned long int) ((*data)[offset] ) ) << 24 ) |
                    ( ( (unsigned long int) ((*data)[offset + 1] ) ) << 16 ) |
                    ( ( (unsigned long int) ((*data)[offset + 2] ) ) << 8 ) |
                    ( ( (unsigned long int) ((*data)[offset + 3] ) ) << 0 );
        }
        else
        {
            result = false;
            std::cout   << zeabus::escape_code::bold_yellow << "WARNING "
                        << zeabus::escape_code::normal_white << ": data length < 4\n";
            unsigned int limit = offset - size;
            for( int run = limit , count = 0 ; run > -1 ;  )
            {
                data32 |= (((unsigned long int) ((*data)[offset + run ] ) )<< (count * 8));
                run--;
                count++;
            }
        }
        memcpy( answer , &data32 , 4 );
        return result;
    } // function to_float

    bool to_double( std::vector< unsigned char>* data ,
            double* answer , 
            unsigned int offset )
    {
        bool result = true;
        unsigned int size = data->size();
        unsigned long long int data64 = 0;
        if( offset + 7 < size )
        {
            data64 = ( ( (unsigned long long int) ((*data)[offset] ) ) << 56 ) |
                    ( ( (unsigned long long int) ((*data)[offset + 1] ) ) << 48 ) |
                    ( ( (unsigned long long int) ((*data)[offset + 2] ) ) << 40 ) |
                    ( ( (unsigned long long int) ((*data)[offset + 3] ) ) << 32 ) |
                    ( ( (unsigned long long int) ((*data)[offset + 4] ) ) << 24 ) |
                    ( ( (unsigned long long int) ((*data)[offset + 5] ) ) << 16 ) |
                    ( ( (unsigned long long int) ((*data)[offset + 6] ) ) << 8 ) |
                    ( ( (unsigned long long int) ((*data)[offset + 7] ) ) << 0 );
        }
        else
        {
            result = false;
            std::cout   << zeabus::escape_code::bold_yellow << "WARNING "
                        << zeabus::escape_code::normal_white << ": data length < 8\n";
            unsigned int limit = offset - size;
            for( int run = limit , count = 0 ; run > -1 ;  )
            {
                data64 |= (((unsigned long long int) ((*data)[offset + run ] ) )<< (count * 8));
                run--;
                count++;
            }
        }
        memcpy( answer , &data64 , 8 );
        return result;
    } 

} // namespace bytes

} // namespace convert

} // namespace zeabus
