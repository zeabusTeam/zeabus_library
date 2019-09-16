// FILE			: base_class.hpp
// AUTHOR		: K.Supasan
// CREATE ON	: 2019, September 11 (UTC+0)
// MAINTAINER	: K.Supasan

// MACRO DETAIL

// README

// REFERENCE
//  ref01   : https://en.cppreference.com/w/cpp/container/vector/operator_at
//  ref02   : http://www.cplusplus.com/reference/ios/ios_base/width/
//  ref03   : http://www.cplusplus.com/reference/vector/vector/begin/

// MACRO SET

// MACRO CONDITION

#include    <iostream>  // for print data

#include    <vector>    // for std vector

#ifndef _ZEABUS_PACKET_BASE_CLASS_HPP__
#define _ZEABUS_PACKET_BASE_CLASS_HPP__

namespace zeabus
{

namespace packet
{

    template< class vector_type > // This packet will utilize and support many type
    class BaseClass
    {

        public:

            BaseClass();

            ~BaseClass();

            void print_memory(); // print information about memory

            void fit_memory(); // manage memory reallocate equal size of vector

            void resize( unsigned int size ); // resize vector

            void clear(); // clear or delete all element

            void reserve( unsigned int size ); // allocate memory for vector

            void print_data_hex( std::string message = "MEMBER : ");

            void print_data( std::string message = "MEMBER : "); // print all element in vector

            void push( vector_type data ); // add single data to last element

            unsigned int size(); // return size of element in vector

            template< typename... pack_type >
            void push( vector_type data , pack_type... pack ); // add vary data to last element

            vector_type& operator[]( unsigned int position ); // access n

            std::vector< vector_type >* pointer(); // return pointer of vector

        protected:
            std::vector< vector_type > vector;

    }; // BaseClass object

} // namespace packet

} // namespace zeabus

#include    <zeabus/packet/base_class.cpp>

#endif // _ZEABUS_PACKET_BASE_CLASS_HPP__
