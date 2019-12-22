// FILE			: file.hpp
// AUTHOR		: K.Supasan
// CREATE ON	: 2019, December 22 (UTC+0)
// MAINTAINER	: K.Supasan

// MACRO DETAIL

// README

// REFERENCE
//  ref01   : http://www.cplusplus.com/reference/istream/istream/istream/
//  ref02   : http://www.cplusplus.com/reference/cstdio/sscanf/

// MACRO SET

// MACRO CONDITION

#include    <cstdio>

#include    <fstream>

#include    <iostream>

#include    <zeabus/escape_code.hpp>

#ifndef _ZEABUS_FILE_HPP__
#define _ZEABUS_FILE_HPP__

namespace zeabus
{
    class FileCSV : public std::ifstream
    {

        public:
            FileCSV();

            // return finish or not
            bool count_column( unsigned int* num_column , char signature = ',' );

            bool count_line( unsigned int* num_line );
 
        private:
            void print_alert( std::string purpose );

    }; // class structor declare

    bool extract_csv_type_2( FileCSV* file_object , int* first , double* second );
}

#endif // _ZEABUS_FILE_HPP__
