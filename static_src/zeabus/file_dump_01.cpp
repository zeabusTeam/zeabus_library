// FILE			: file_dump_01.cpp
// AUTHOR		: K.Supasan
// CREATE ON	: 2020, March 11 (UTC+0)
// MAINTAINER	: K.Supasan

// MACRO DETAIL

// README

// REFERENCE

// MACRO SET

// MACRO CONDITION

#include    <zeabus/file.hpp>

namespace zeabus
{

    void dump_csv_type_3( const std::string full_path , 
            const double* first , const double* second , const double* third ,
            unsigned int size )
    {
        std::ofstream file;
        file.open( full_path );
        file << first[ 0 ] << "," << second[ 0 ] << "," << third[ 0 ];
        for( unsigned int run = 1 ; run < size ; run++ )
        {
            file    << "\n" << first[ run ] << "," 
                    << second[ run ] << ","
                    << third[ run ];
        }
        file.close();
    }

} // namespace zeabus
