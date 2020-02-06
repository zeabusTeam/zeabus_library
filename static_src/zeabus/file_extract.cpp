// FILE			: file_extract.cpp
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

    bool extract_csv_type_2( FileCSV* file_object , int* first , double* second )
    {
        std::string str_array[2];
        std::string str_collect;
        unsigned int num_line;
        bool success = false; 
        if( ! file_object->count_line( &num_line ) )
        {
            ;
        }
        else
        {
            for( unsigned int run = 0 ; run < num_line ; run++ )
            {
                *file_object >> str_collect;

                str_array[0] = "";
                str_array[1] = "";
                // x for run in str_collect
                // y for run in str_array
                for( unsigned int x = 0 , y = 0 ; x < str_collect.size() ; x++ )
                {
                    switch( str_collect[x] )
                    {
                    case ',' : 
                        y++;
                    case '\n':
                    case '\0': 
                        break;
                    default :
                        str_array[ y ] += str_collect[x];
                    }
                }
                first[ run ] = std::atoi( str_array[0].c_str() );
                second[ run ] = std::atof( str_array[1].c_str() );
            }
            success = true;
        }

        return success;
    }

    bool extract_csv_type_8( FileCSV* file_object , std::string* frame_id , std::string* child_frame,
            double* translation_x , double* translation_y , double* translation_z ,
            double* rotation_x , double* rotation_y , double* rotation_z )
    {
        std::string str_array[ 8 ];
        std::string str_collect;
        unsigned int num_line;
        free( frame_id );
        free( child_frame );
        free( translation_x );
        free( translation_y );
        free( translation_z );
        free( rotation_x );
        free( rotation_y );
        free( rotation_z );
        frame_id = ( std::string* ) malloc( sizeof( std::string ) * num_line ); 
        child_frame = ( std::string* ) malloc( sizeof( std::string ) * num_line );
        translation_x = ( double* ) malloc( sizeof( double ) * num_line ); 
        translation_y = ( double* ) malloc( sizeof( double ) * num_line ); 
        translation_z = ( double* ) malloc( sizeof( double ) * num_line ); 
        rotation_x = ( double* ) malloc( sizeof( double ) * num_line ); 
        rotation_y = ( double* ) malloc( sizeof( double ) * num_line ); 
        rotation_z = ( double* ) malloc( sizeof( double ) * num_line ); 
        bool success = false;
        if( ! file_object->count_line( &num_line ) )
        {
            ;
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
                frame_id[ run ] = str_array[ 0 ];
                child_frame[ run ] = str_array[ 1 ];
                translation_x[ run ] = std::atof( str_array[ 2 ].c_str() );
                translation_y[ run ] = std::atof( str_array[ 3 ].c_str() );
                translation_z[ run ] = std::atof( str_array[ 4 ].c_str() );
                rotation_x[ run ] = std::atof( str_array[ 5 ].c_str() );
                rotation_y[ run ] = std::atof( str_array[ 6 ].c_str() );
                rotation_z[ run ] = std::atof( str_array[ 7 ].c_str() );
            }
            success = true;
        }
        return success;
    }
} // namesapce zeabus
