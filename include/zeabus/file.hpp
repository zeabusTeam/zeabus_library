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

#include    <cstdlib>

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

    bool extract_csv_type_1( FileCSV* file_object , double* first );

    bool extract_csv_type_2( FileCSV* file_object , int* first , double* second );

    bool extract_csv_type_3( FileCSV* file_object , double* first , double* second,
            double* third );

    bool extract_csv_type_8( FileCSV* file_object , std::string* frame_id , std::string* child_frame,
            double* translation_x , double* translation_y , double* translation_z ,
            double* rotation_x , double* rotation_y , double* rotation_z );

    bool extract_csv_type_15( FileCSV* file_object, double* thruster_force , 
            double* euler_robot , double* angular_velocity , double* angular_accel );

    bool extract_csv_type_observer_train( FileCSV* file_object , double* robot_velocity,
            double* robot_acceleration, double* robot_quaternion , double* force_thruster );
}

#endif // _ZEABUS_FILE_HPP__
