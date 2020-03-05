// FILE			: file_extract_01.cpp
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

    // robot_velocity use 6
    // robot_acceleration use 6
    // robot_quaternion use 4
    // force_thruster use 8
    bool extract_csv_type_observer_train( FileCSV* file_object , double* robot_velocity,
            double* robot_acceleration, double* robot_quaternion , double* force_thruster )
    {
        std::string str_array[ 24 ];
        std::string str_collect;
        unsigned int num_line;
        bool success = file_object->count_line( &num_line );
        if( ! success )
        {
            printf( "Failure to count line\n");
        }
        else
        {
            for( unsigned int run = 0 ; run < num_line ; run++ )
            {
                *file_object >> str_collect;
        
                for( unsigned int reset = 0 ; reset < 8 ; reset++ )
                {
                    str_array[ reset ] = "";
                }
                
                // x for run in str_collect
                // y for run in str_array
                for( unsigned int x = 0 , y = 0 ;  x < str_collect.size() ; x++ )
                {
                    switch( str_collect[ x ] )
                    {
                    case ',' :
                        y++;
                    case '\n':
                    case '\0':
                        break;
                    default:
                        str_array[ y ] += str_collect[ x ];
                    }
                }
                robot_velocity[ ( run * 6 ) + 0 ] = std::atof( str_array[ 0 ].c_str() );
                robot_velocity[ ( run * 6 ) + 1 ] = std::atof( str_array[ 1 ].c_str() );
                robot_velocity[ ( run * 6 ) + 2 ] = std::atof( str_array[ 2 ].c_str() );
                robot_velocity[ ( run * 6 ) + 3 ] = std::atof( str_array[ 3 ].c_str() );
                robot_velocity[ ( run * 6 ) + 4 ] = std::atof( str_array[ 4 ].c_str() );
                robot_velocity[ ( run * 6 ) + 5 ] = std::atof( str_array[ 5 ].c_str() );
                robot_acceleration[ ( run * 6 ) + 0 ] = std::atof( str_array[ 6 ].c_str() );
                robot_acceleration[ ( run * 6 ) + 1 ] = std::atof( str_array[ 7 ].c_str() );
                robot_acceleration[ ( run * 6 ) + 2 ] = std::atof( str_array[ 8 ].c_str() );
                robot_acceleration[ ( run * 6 ) + 3 ] = std::atof( str_array[ 9 ].c_str() );
                robot_acceleration[ ( run * 6 ) + 4 ] = std::atof( str_array[ 10 ].c_str() );
                robot_acceleration[ ( run * 6 ) + 5 ] = std::atof( str_array[ 11 ].c_str() );
                robot_quaternion[ ( run * 4 ) + 0 ] = std::atof( str_array[ 12 ].c_str() );
                robot_quaternion[ ( run * 4 ) + 1 ] = std::atof( str_array[ 13 ].c_str() );
                robot_quaternion[ ( run * 4 ) + 2 ] = std::atof( str_array[ 14 ].c_str() );
                robot_quaternion[ ( run * 4 ) + 3 ] = std::atof( str_array[ 15 ].c_str() );
                force_thruster[ ( run * 8 ) + 0 ] = std::atof( str_array[ 16 ].c_str() );
                force_thruster[ ( run * 8 ) + 1 ] = std::atof( str_array[ 17 ].c_str() );
                force_thruster[ ( run * 8 ) + 2 ] = std::atof( str_array[ 18 ].c_str() );
                force_thruster[ ( run * 8 ) + 3 ] = std::atof( str_array[ 19 ].c_str() );
                force_thruster[ ( run * 8 ) + 4 ] = std::atof( str_array[ 20 ].c_str() );
                force_thruster[ ( run * 8 ) + 5 ] = std::atof( str_array[ 21 ].c_str() );
                force_thruster[ ( run * 8 ) + 6 ] = std::atof( str_array[ 22 ].c_str() );
                force_thruster[ ( run * 8 ) + 7 ] = std::atof( str_array[ 23 ].c_str() );
            }
            success = true;
        }
        return success;
    } // end function


} // namesapce zeabus
