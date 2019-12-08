// FILE			: array.hpp
// AUTHOR		: K.Supasan
// CREATE ON	: 2019, December 5 (UTC+0)
// MAINTAINER	: K.Supasan

// MACRO DETAIL

// README

// REFERENCE
//  ref01: http://www.cplusplus.com/reference/cstdlib/malloc/
//  ref02: https://en.cppreference.com/w/cpp/string/byte/memcpy
//  ref03: http://www.cplusplus.com/reference/cstdlib/realloc/

// MACRO SET

// MACRO CONDITION

#include    <cstdlib> // import function malloc

#include    <iostream>

#include    <cstring> // import function memcpy

#ifndef _ZEABUS_MATH_ARRAY_HPP__
#define _ZEABUS_MATH_ARRAY_HPP__

namespace zeabus
{

namespace math
{

    template
    <class data_type >
    class Array
    {
        public:
            Array( unsigned int size );

            void resize( unsigned int size );

            template< typename vector_type >
            void get_vector( vector_type* vector_address );

            void push_data( data_type value );

            data_type* begin();

            data_type* last();

            unsigned int size();
            
        protected:
            unsigned int size;
            data_type* address;

    }; // class structure array

} // namespace math

} // namespace zeabus

#include    <zeabus/math/array.cpp>

#endif // _ZEABUS_MATH_ARRAY_HPP__
