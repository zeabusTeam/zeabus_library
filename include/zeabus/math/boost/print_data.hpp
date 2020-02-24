// FILE			: print_data.hpp
// AUTHOR		: K.Supasan
// CREATE ON	: 2019, Febuary 10 (UTC+0)
// MAINTAINER	: K.Supasan

// MACRO DETAIL

// README

// REFERENCE

// MACRO SET

// MACRO CONDITION

#include    <boost/qvm/vec.hpp>

#include    <boost/qvm/mat.hpp>

#include    <iostream>

#ifndef _ZEABUS_MATH_BOOST_PRINT_DATA_HPP__
#define _ZEABUS_MATH_BOOST_PRINT_DATA_HPP__

namespace zeabus_boost
{

    template< class T , int R , int C >
    void print( const boost::qvm::mat< T , R , C > data );

    template< class T , int S > 
    void print( const boost::qvm::vec< T , S > data );

} // namespace zeabus_boost

#include    <zeabus/math/boost/print_data.cpp>
#endif // _ZEABUS_MATH_BOOST_PRINT_DATA_HPP__
