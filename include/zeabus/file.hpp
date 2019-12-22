// FILE			: file.hpp
// AUTHOR		: K.Supasan
// CREATE ON	: 2019, December 22 (UTC+0)
// MAINTAINER	: K.Supasan

// MACRO DETAIL

// README

// REFERENCE
//  ref01   : http://www.cplusplus.com/reference/istream/istream/istream/

// MACRO SET

// MACRO CONDITION

#include    <iostream>

#include    <fstream>

#include    <zeabus/escape_code.hpp>

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
}
