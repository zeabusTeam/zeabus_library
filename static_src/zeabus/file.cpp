// FILE			: file.cpp
// AUTHOR		: K.Supasan
// CREATE ON	: 2019, December 22 (UTC+0)
// MAINTAINER	: K.Supasan

// MACRO DETAIL

// README

// REFERENCE
//  ref01   : http://www.cplusplus.com/reference/istream/istream/istream/
//  ref02   : http://www.cplusplus.com/reference/fstream/ifstream/

// MACRO SET

// MACRO CONDITION

#include    <zeabus/file.hpp>

namespace zeabus
{

    FileCSV::FileCSV() : std::ifstream()
    {
        ;
    } // FileCSV function constructor

    bool FileCSV::count_column( unsigned int* num_column , char signature )
    {
        bool return_value = false;
        if( ! this->is_open() )
        {
            this->print_alert( "count_column" );
        } // condition you now file didn't open 
        else
        {
            char temp = 's';
            int start_position = this->tellg();
            std::cout   << "Start position " << start_position << "\n";
            *num_column = 1;
            while( temp != '\n' )
            {
                if( temp == signature ) (*num_column) +=1;
                this->get( temp );
            } // loop count command
            std::cout   << "Before set new " << this->tellg() << "\n";
            this->seekg( start_position );
            std::cout   << "After set new " << this->tellg() << "\n";
            return_value = true;
        }
        return return_value;
    } // function count_column

    bool FileCSV::count_line( unsigned int* num_line )
    {
        *num_line = -1;
        std::string temporary;
        bool success = false;
        if( ! this->is_open() )
        {
            this->print_alert( "count_line" );
        }
        else
        {
            int save_position = this->tellg();
            this->seekg( 0 );
            std::string temp;
            while( !this->eof() )
            {
                *this >> temporary;
                *num_line += 1; 
            }
            this->seekg( save_position );
            success = true;
        }
        return success;
    } // function count_line() 

    void FileCSV::print_alert( std::string purpose )
    {
        std::cout   << escape_code::bold_red << "Fatal!" << escape_code::normal_white 
                    << "File not alvalible for " << purpose << std::endl;

    } // function print_alert

} // namespace zeabus
