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

namespace zeabus
{

    template <typename first_array , typename second_array>
    bool extract_csv_type_2( FileCSV* file_object , first_array* first , second_array* second )
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
                std::cout   << "before sscanf : " << str_collect << "\n";

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
            }
            success = true;
        }

        return success;
    }

} // namesapce zeabus
