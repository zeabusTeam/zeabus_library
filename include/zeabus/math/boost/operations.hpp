// FILE			: operations.hpp
// AUTHOR		: K.Supasan
// CREATE ON	: 2019, Febuary 24 (UTC+0)
// MAINTAINER	: K.Supasan

// MACRO DETAIL

// README

// REFERENCE

// MACRO SET

// MACRO CONDITION

#include    <boost/qvm/vec.hpp>
#include    <boost/qvm/mat.hpp>

#include    <cstring>

#ifndef _ZEABUS_MATH_BOOST_OPERATIONS_HPP__
#define _ZEABUS_MATH_BOOST_OPERATIONS_HPP__

namespace zeabus_boost
{
    template< typename T , int R , int C >
    inline void mat_concat( boost::qvm::mat< T , R * 2 , C >* target , 
            const boost::qvm::mat< T , R , C >* source1,
            const boost::qvm::mat< T , R , C >* source2);
}

#include    <zeabus/math/boost/operations.cpp>

#endif // _ZEABUS_MATH_BOOST_OPERATIONS_HPP__
