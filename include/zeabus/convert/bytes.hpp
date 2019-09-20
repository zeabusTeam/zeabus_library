// FILE			: bytes.hpp
// AUTHOR		: K.Supasan
// CREATE ON	: 2019, September 18 (UTC+0)
// MAINTAINER	: K.Supasan

// MACRO DETAIL

// README
//  This file create for convert data bytes to variable type int / float or double up to you 
//  But ensure you have to study about size of type varaible and your data that are correct
//  for size of type varaible we reference from http://www.cplusplus.com/doc/tutorial/variables/

// REFERENCE

// MACRO SET

// MACRO CONDITION

#include    <cstring>

#include    <vector>

#include    <zeabus/escape_code.hpp>

#ifndef _ZEABUS_CONVERT_BYTES_HPP__
#define _ZEABUS_CONVERT_BYTES_HPP__

namespace zeabus
{

namespace convert
{

namespace bytes
{

    bool to_float( std::vector< unsigned char>* data ,
            float* answer , 
            unsigned int offset = 0 );

    bool to_double( std::vector< unsigned char>* data ,
            double* answer ,
            unsigned int offset = 0 );

    bool to_float( std::vector< unsigned char>::iterator data ,
            float* answer , 
            unsigned int offset = 0 );

    bool to_float( std::vector< unsigned char>::iterator data ,
            double* answer , 
            unsigned int offset = 0 );

} // namespace bytes

} // namespace convert

} // namespace zeabus

#endif // _ZEABUS_CONVERT_BYTES_HPP__
